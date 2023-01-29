/*
  The MIT License (MIT)
  Copyright (c) 2020 Amirhosein Farahmand
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#include<iostream>
using namespace::std;

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
//#include<QIODevice>
//#include<QDebug>
//#include <QJsonDocument>
//#include <QJsonParseError>
//#include <QJsonObject>
//#include <QJsonValue>
//#include <QJsonArray>
//#include<QVector>
#include <QDebug>
#include<QtCore>

#include "../include/usermanager.h"
#include "../include/dbmanager.h"
#include "../include/common.h"
#include "../include/config.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "AmirhoseinFarahmandLib_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject* app_root = new QObject();
    DBManager* db_manager = new DBManager(app_root);
    UserManager* user_manager = new UserManager(db_manager,app_root);
    if (db_manager->init())
    {

        if (engine.rootObjects().isEmpty())
        {
                return -1;
        }
        QObject *item = engine.rootObjects()[0];
        auto root_context = engine.rootContext();

        root_context->setContextProperty("default_width", PROJECT_UI_DEFAULT_WIDTH);
        root_context->setContextProperty("default_height", PROJECT_UI_DEFAULT_HEIGHT);
        root_context->setContextProperty("min_width", PROJECT_UI_MIN_WIDTH);
        root_context->setContextProperty("min_height", PROJECT_UI_MIN_HEIGHT);
        root_context->setContextProperty("default_gap", PROJECT_UI_DEFAULT_GAP);
        engine.rootContext()->setContextProperty("db_manager", db_manager);
        engine.rootContext()->setContextProperty("user_manager", user_manager);
        //engine.rootContext()->setContextProperty("library", library);//QVariant::fromValue(calendar_context)

        QVariant returnedValue;
        QMetaObject::invokeMethod(item, "init");
        QMetaObject::invokeMethod(item, "loadPage",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, QString("LoginPage")));

        qDebug() << "QML function returned:" << returnedValue.toString();
    }
    else
    {

    }

    return app.exec();
}
