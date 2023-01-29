#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include<iostream>
#include "../include/book.h"
using namespace::std;

///
/// \brief The Library class
///

class Library: public QObject
{
    Q_OBJECT
public:
    ///
    /// \brief Library
    ///
    explicit Library(int a ,QObject *parent =nullptr);

    ///
    /// \brief Library
    /// \param parent
    ///
    explicit Library(QObject *parent = nullptr);

    ///
    /// \brief searchBookbytitle
    /// \param title
    /// \return
    ///
    QVector<Book*> searchBookbytitle(QString title);

    ///
    /// \brief searchBookbyauthor
    /// \param author
    /// \return
    ///
    QVector<Book*> searchBookbyauthor(QString author);

    ///
    /// \brief searchBookbypublisher
    /// \param publisher
    /// \return
    ///
    QVector<Book*> searchBookbypublisher(QString publisher);

    ///
    /// \brief searchBookbypublishyaer
    /// \param publishyear
    /// \return
    ///
    QVector<Book*> searchBookbypublishyear(QString publishyear);

    ///
    /// \brief borrowBook
    /// \param book
    /// \return
    ///
    bool borrowBook(Book* book);

    ///
    /// \brief getBackbook
    /// \param book
    /// \return
    ///
    void getBackbook(Book* book);
Q_SIGNALS:
    ///
    /// \brief borrowBook_SI
    ///
    void borrowBook_SI();

    ///
    /// \brief getBackbook_SI
    ///
    void getBackbook_SI();

    ///
    /// \brief searchBookbytitle_SI
    ///
    void searchBookbytitle_SI();

    ///
    /// \brief searchBookbyauthor_SI
    ///
    void searchBookbyauthor_SI();

    ///
    /// \brief searchBookbypublisher_SI
    ///
    void searchBookbypublisher_SI();

    ///
    /// \brief searchBookbypublishyaer_SI
    ///
    void searchBookbypublishyaer_SI();
public Q_SLOTS:
    ///
    /// \brief borrowBook_SL
    ///
    void borrowBook_SL();

    ///
    /// \brief getBackbook_SL
    ///
    void getBackbook_SL();

    ///
    /// \brief searchBookbytitle_SL
    ///
    void searchBookbytitle_SL();

    ///
    /// \brief searchBookbyauthor_SL
    ///
    void searchBookbyauthor_SL();

    ///
    /// \brief searchBookbypublisher_SL
    ///
    void searchBookbypublisher_SL();

    ///
    /// \brief searchBookbypublishyaer_SL
    ///
    void searchBookbypublishyaer_SL();
};

#endif // LIBRARY_H
