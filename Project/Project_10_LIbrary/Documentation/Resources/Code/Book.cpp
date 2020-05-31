#pragma once

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include "Book.h"


void Book::copy(const Book& other)
{
    author = new (std::nothrow) char[strlen(other.author) + 1];
    strcpy(author, other.author);
    title = new (std::nothrow) char[strlen(other.title) + 1];
    strcpy(title, other.title);
    genre = new (std::nothrow) char[strlen(other.genre) + 1];
    strcpy(genre, other.genre);
    summary = new (std::nothrow) char[strlen(other.summary) + 1];
    strcpy(summary, other.summary);
    tag = new (std::nothrow) char[strlen(other.tag) + 1];
    strcpy(tag, other.tag);
    year_release = other.year_release;
    rating = other.rating;
    library_ID = other.library_ID;
}


void Book::delete_Book()
{
    delete[] author;
    delete[] title;
    delete[] genre;
    delete[] tag;
}

/**
 * @brief Construct a new Book:: Book object
 * 
 */

Book::Book()
{
    author = new char[1];
    title = new char[1];
    genre = new char[1];
    summary = new char[1];
    tag = new char[1];
    year_release = 0;
    rating = 0.0;
    library_ID = 0;
}

/**
 * @brief Construct a new Book:: Book object
 * 
 * @param other 
 */

Book::Book (const Book& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Book& 
 */

Book& Book::operator=(const Book& other)
{
    if(this != &other)
    {
        delete_Book();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the Book:: Book object
 * 
 */

Book::~Book()
{
    delete_Book();
}

/**
 * @brief Construct a new Book:: Book object
 * 
 * @param _title 
 * @param _author 
 * @param _genre 
 * @param _summary 
 * @param _year_release 
 * @param _tag 
 * @param _rating 
 * @param _library_ID 
 */

Book::Book(const char* _title,const char* _author,const char* _genre, const char* _summary, const int _year_release, const char* _tag, const double _rating, const int _library_ID)
{
    delete[] author;
    author = new (std::nothrow) char[strlen(_author) + 1];
    strcpy(author, _author);
    delete[] title;
    title = new (std::nothrow) char[strlen(_title) + 1];
    strcpy(title, _title);
    delete[] genre;
    genre = new (std::nothrow) char[strlen(_genre) + 1];
    strcpy(genre, _genre);
    delete[] summary;
    summary = new (std::nothrow) char[strlen(_summary) + 1];
    strcpy(summary, _summary);
    delete[] tag;
    tag = new (std::nothrow) char[strlen(_tag) + 1];
    strcpy(tag, _tag);
    year_release = _year_release;
    rating = _rating;
    library_ID = _library_ID;
}   


/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната author
 * 
 * @param _author 
 */

void Book::setAuthor(char* _author)
{
    delete[] author;
    author = new (std::nothrow) char[strlen(_author) + 1];
    strcpy(author, _author);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната title
 * 
 * @param _title 
 */

void Book::setTitle(char* _title)
{
    delete[] title;
    title = new (std::nothrow) char[strlen(_title) + 1];
    strcpy(title, _title);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната genre
 * 
 * @param _genre 
 */

void Book::setGenre(char* _genre)
{
    delete[] genre;
    genre = new (std::nothrow) char[strlen(_genre) + 1];
    strcpy(genre, _genre);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната summary
 * 
 * @param _summary 
 */

void Book::setSummary(char* _summary)
{
    delete[] summary;
    summary = new (std::nothrow) char[strlen(_summary) + 1];
    strcpy(summary, _summary);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната year_release
 * 
 * @param _year_release 
 */

void Book::setYear_release(int _year_release)
{
    year_release = _year_release;
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната tag
 * 
 * @param _tag 
 */

void Book::setTag(char* _tag)
{
    delete[] tag;
    tag = new (std::nothrow) char[strlen(_tag) + 1];
    strcpy(tag, _tag);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната rating
 * 
 * @param _rating 
 */

void Book::setRating(double _rating)
{
    rating = _rating;
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната library_ID
 * 
 * @param _library_ID 
 */

void Book::setLibrary_ID(int _library_ID)
{
    library_ID = _library_ID;
}

/**
 * @brief Селектор извеждащ стойността на член-данната author
 * 
 * @return char* 
 */

char* Book::getAuthor() const
{
    return author;
}

/**
 * @brief Селектор извеждащ стойността на член-данната title
 * 
 * @return char* 
 */

char* Book::getTitle() const
{
    return title;
}

/**
 * @brief Селектор извеждащ стойността на член-данната genre
 * 
 * @return char* 
 */

char* Book::getGenre() const
{
    return genre;
}

/**
 * @brief Селектор извеждащ стойността на член-данната summary
 * 
 * @return char* 
 */

char* Book::getSummary() const
{
    return summary;
}

/**
 * @brief Селектор извеждащ стойността на член-данната year_release
 * 
 * @return int 
 */

int Book::getYear_release() const
{
    return year_release;
}

/**
 * @brief Селектор извеждащ стойността на член-данната tag
 * 
 * @return char* 
 */

char* Book::getTag() const
{
    return tag;
}

/**
 * @brief Селектор извеждащ стойността на член-данната rating
 * 
 * @return double 
 */

double Book::getRating() const
{
    return rating;
}

/**
 * @brief Селектор извеждащ стойността на член-данната library_ID
 * 
 * @return int 
 */

int Book::getLibrary_ID() const
{
    return library_ID;
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */

void Book::print() const
{
    std::cout << "Title:";
    std::cout << getTitle() << std::endl;
    std::cout << "Author:";
    std::cout << getAuthor() << std::endl;
    std::cout << "Genre:";
    std::cout << getGenre() << std::endl;
    std::cout << "Library ID:";
    std::cout << getLibrary_ID() << std::endl;
    std::cout << "Summary:";
    std::cout << getSummary() << std::endl;
    std::cout << "Year release:";
    std::cout << getYear_release() << std::endl;
    std::cout << "Tag:";
    std::cout << getTag() << std::endl;
    std::cout << "Rating:";
    std::cout << getRating() << std::endl;
}

/**
 * @brief Помощна функция към books_all
 * 
 */

void Book::books_all_print() const
{
    std::cout << "Title:";
    std::cout << getTitle() << std::endl;
    std::cout << "Author:";
    std::cout << getAuthor() << std::endl;
    std::cout << "Genre:";
    std::cout << getGenre() << std::endl;
    std::cout << "Library ID:";
    std::cout << getLibrary_ID() << std::endl;
}

/**
 * @brief Оператор за извеждане на данни на Book в поток
 * 
 * @param out 
 * @param b 
 * @return std::ostream& 
 */

std::ostream &operator <<(std::ostream &out, const Book &b)
{ 
   out <<  b.getTitle() << std::endl << b.getAuthor() << std::endl << b.getGenre() << std::endl << b.getLibrary_ID() << std::endl << b.getSummary() << std::endl << b.getYear_release() << std::endl << b.getTag() << std::endl << b.getRating();
   return out;
} 

/**
 * @brief Оператор за въвеждане на данни на Book в поток
 * 
 * @param in 
 * @param b 
 * @return std::istream& 
 */

std::istream &operator >>(std::istream &in, Book &b)
{
    char buffer1[50];
    char buffer2[50];
    char buffer3[50];
    char buffer4[50];
    char buffer5[50];
    char buffer6[50];
    char buffer7[50];
    char buffer8[50];
    in.getline(buffer1, 50);
    in.getline(buffer2, 50);
    in.getline(buffer3, 50);
    in.getline(buffer4, 50);
    in.getline(buffer5, 50);
    in.getline(buffer6, 50);
    in.getline(buffer7, 50);
    in.getline(buffer8, 50);
    b.setTitle(buffer1);
    b.setAuthor(buffer2);
    b.setGenre(buffer3);
    b.setLibrary_ID(atoi(buffer4));
    b.setSummary(buffer5);
    b.setYear_release(atoi(buffer6));
    b.setTag(buffer7);
    b.setRating(atof(buffer8));
    return in;
}

/**
 * @brief Четене на данни за Book от файлов поток
 * 
 * @param is 
 * @param book 
 */

void Book::read(std::istream& is, Book& book)
{
    is.read(book.getTitle(), 50);

    is.read(book.getAuthor(), 50);

    is.read(book.getGenre(), 50);

    int id = book.getLibrary_ID();
    char* idChar = (char *) &id;
    is.read(idChar, 50);

    is.read(book.getSummary(), 50);

    int year = book.getYear_release();
    char* yearChar = (char *) &year;
    is.read(yearChar, 50);

    is.read(book.getTag(), 50);
    
    double rat = book.getRating();
    char* ratChar = (char *) &rat;
    is.read(ratChar, 50);
}

/**
 * @brief Писане на данни за Book от файлов поток
 * 
 * @param os 
 * @param book 
 */

void Book::write(std::ostream& os, const Book& book)
{
    os.write(book.getTitle(), 50);

    os.write(book.getAuthor(), 50);

    os.write(book.getGenre(), 50);

    int id = book.getLibrary_ID();
    char* idChar = (char *) &id;
    os.write(idChar, 50);

    os.write(book.getSummary(), 50);

    int year = book.getYear_release();
    char* yearChar = (char *) &year;
    os.write(yearChar, 50);

    os.write(book.getTag(), 50);
    
    double rat = book.getRating();
    char* ratChar = (char *) &rat;
    os.write(ratChar, 50);
}




