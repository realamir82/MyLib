#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <iostream>
using namespace::std;
//#include <bits/stdc++.h>

///
/// \brief The Book class
///
class Book: public QObject
{
    Q_OBJECT
public:
    ///
    /// \brief Book
    /// \param parent
    ///
    explicit Book(QObject *parent = nullptr);

    ///
    /// \brief Book
    /// \param id
    /// \param title
    /// \param shelfnumber
    /// \param author
    /// \param edition
    /// \param publisher
    /// \param publishyear
    /// \param length
    /// \param subject
    /// \param isbn
    /// \param parent
    ///
    explicit Book(int id,
                  QString title,
                  int shelfnumber,
                  QString author,
                  QString edition,
                  QString publisher,
                  QString publishyear,
                  int length,
                  QString subject,
                  int  isbn=0,
                  QObject *parent = nullptr);

    ///
    /// \brief getId
    /// \return
    ///
    int getId();

    ///
    /// \brief setTitle
    /// \param title
    ///
    void setTitle(QString title);
    ///
    /// \brief getTitle
    /// \return
    ///
    QString getTitle();

    ///
    /// \brief setShelfNumber
    /// \param shelfnumber
    ///
    void setShelfNumber(int shelfnumber);
    ///
    /// \brief getShelfNumber
    /// \return
    ///
    int getShelfNumber();

    ///
    /// \brief setAuthor
    /// \param author
    ///
    void setAuthor(QString author);
    ///
    /// \brief getAuthor
    /// \return
    ///
    QString getAuthor();

    ///
    /// \brief setEdition
    /// \param edition
    ///
    void setEdition(QString edition);
    ///
    /// \brief getEdition
    /// \return
    ///
    QString getEdition();

    ///
    /// \brief setPublisher
    /// \param publisher
    ///
    void setPublisher(QString publisher);
    ///
    /// \brief getPublisher
    /// \return
    ///
    QString getPublisher();

    ///
    /// \brief setPublishYear
    /// \param publishyear
    ///
    void setPublishYear(QString publishyear);
    ///
    /// \brief getPublishYear
    /// \return
    ///
    QString getPublishYear();

    ///
    /// \brief setLength
    /// \param length
    ///
    void setLength(int length);
    ///
    /// \brief getLength
    /// \return
    ///
    int getLength();

    ///
    /// \brief setSubject
    /// \param subject
    ///
    void setSubject(QString subject);
    ///
    /// \brief getSubject
    /// \return
    ///
    QString getSubject();

    ///
    /// \brief setBorrowerId
    /// \param borrowerId
    ///
    void setBorrowerId(int borrowerId);
    ///
    /// \brief getBorrowerId
    /// \return
    ///
    int getBorrowerId();

    ///
    /// \brief setISBN
    /// \param shelfNumber
    ///
    void setISBN(int isbn);
    ///
    /// \brief getISBN
    /// \return
    ///
    int getISBN();

    ///
    /// \brief getInfo
    /// \return
    ///
    QString getInfo();
Q_SIGNALS:
    ///
    /// \brief bookChanged_SI
    ///
    void bookChanged_SI ();
public Q_SLOTS:
    ///
    /// \brief bookChanged_SL
    ///
    void bookChanged_SL();
private:
    ///
    /// \brief _id
    ///
    int _id = 0;
    ///
    /// \brief _title
    ///
    QString _title = "";
    ///
    /// \brief _shelf_number
    ///
    int _shelf_number = 0;
    ///
    /// \brief _author
    ///
    QString _author = "";
    ///
    /// \brief _edition
    ///
    QString _edition = "";
    ///
    /// \brief _publisher
    ///
    QString _publisher = "";
    ///
    /// \brief _publics_year
    ///
    QString _publics_year = "";
    ///
    /// \brief _length
    ///
    int _length = 0;
    ///
    /// \brief _subject
    ///
    QString _subject = "";
    ///
    /// \brief _borrower_id
    ///
    int _borrower_id = 0;
    ///
    /// \brief _isbn
    ///
    int  _isbn = 0;

};

#endif // BOOK_H
