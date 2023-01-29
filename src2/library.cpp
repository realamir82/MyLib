#include "../include/library.h"



Library::Library(QObject *parent):
    Library(0
            ,parent)
{

}

Library::Library(int a,QObject *parent)
{
}


QVector<Book*> Library::searchBookbytitle(QString title)
{

}

QVector<Book*> Library::searchBookbyauthor(QString author)
{

}

QVector<Book*> Library::searchBookbypublisher(QString publisher)
{

}

QVector<Book*> Library::searchBookbypublishyear(QString publishyear)
{

}

bool Library::borrowBook(Book* book)
{
    if(book->getBorrowerId()>0)
        return false;
    else
        return true;
}

void Library::getBackbook(Book* book)
{
    book->setBorrowerId(0);
}



