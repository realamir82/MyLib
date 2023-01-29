#include "../include/book.h"
#include "../include/randomGenerator.h"

Book::Book(QObject *parent):
    Book(0,
         "unknown book",
         0,
         "unknown author",
         "unknown editor",
         "unknown publisher",
         "unknown publish year",
         0,
         "unknown subject",
         0,
         parent)
{}

Book::Book(int id,
           QString title,
           int shelfnumber,
           QString author,
           QString edition,
           QString publisher,
           QString publishyear,
           int length,
           QString subject,
           int isbn,
           QObject *parent):
                QObject(parent)
{
    _id =  id;
    setTitle(title);
    setShelfNumber(shelfnumber);
    setAuthor(author);
    setEdition(edition);
    setPublisher(publisher);
    setPublishYear(publishyear);
    setLength(length);
    setSubject(subject);
    setISBN(isbn);
}

int Book::getId()
{
    return _id;
}

void Book::setTitle(QString title)
{
    if(_title != title)
    {
        _title = title;
        emit bookChanged_SI();
    }
}

QString Book::getTitle()
{
    return _title;
}

void Book::setShelfNumber(int shelfnumber)
{
    if(_shelf_number != shelfnumber)
    {
        _shelf_number = shelfnumber;
        emit bookChanged_SI();
    }
}

int Book::getShelfNumber()
{
    return _shelf_number;
}

void Book::setAuthor(QString author)
{
    if(_author != author)
    {
        _author = author;
        emit bookChanged_SI();
    }
}

QString Book::getAuthor()
{
    return _author;
}

void Book::setEdition(QString edition)
{
    if(_edition != edition)
    {
        _edition = edition;
        emit bookChanged_SI();
    }
}

QString Book::getEdition()
{
    return _edition;
}

void Book::setPublisher(QString publisher)
{
    if(_publisher != publisher)
    {
        _publisher = publisher;
        emit bookChanged_SI();
    }
}

QString Book::getPublisher()
{
    return _publisher;
}

void Book::setPublishYear(QString publishyear)
{
    if(_publics_year != publishyear)
    {
        _publics_year = publishyear;
        emit bookChanged_SI();
    }
}

QString Book::getPublishYear()
{
    return _publics_year;
}

void Book::setLength(int length)
{
    if(_length != length)
    {
        _length = length;
        emit bookChanged_SI();
    }
}

int Book::getLength()
{
    return _length;
}

void Book::setSubject(QString subject)
{
    if(_subject != subject)
    {
        _subject = subject;
        emit bookChanged_SI();
    }
}

QString Book::getSubject()
{
    return _subject;
}

void Book::setBorrowerId(int borrowerId)
{
    if(_borrower_id != borrowerId)
    {
        _borrower_id = borrowerId;
        emit bookChanged_SI();
    }
}

int Book::getBorrowerId()
{
    return _borrower_id;
}

void Book::setISBN(int isbn)
{
    if(isbn > 0)
    {
        if(isbn != _isbn)
        {
           _isbn =  isbn;
           emit bookChanged_SI();
        }
    }
    else
    {
        _isbn = Mygenerator();
        emit bookChanged_SI();
    }
}

int Book::getISBN()
{
    return _isbn;
}

QString Book::getInfo()
{
    return "";
}




