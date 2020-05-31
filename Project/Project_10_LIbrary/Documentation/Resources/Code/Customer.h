#ifndef _Customer_HH
#define _Customer_HH

/**
 * @file Customer.h
 * @author your name (you@domain.com)
 * @brief Класът Administrator съдържа данни за профил, който е с потребителски права
 * @version 0.1
 * @date 2020-05-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Parent.cpp"
#include "Book.cpp"

class Customer: public Parent 
{
    private:
    Book* books;
    int capacity_books;
    int size_books;
    void copy(const Customer& );
    void delete_Customer();

    public:
    Customer();
    Customer(const Customer&);
    Customer& operator =(const Customer&);
    ~Customer();
    Customer(const char*, const char*);
    void setCapacity_books(int);
    Book* getBooks() const;
    int getCapacity_books() const;
    void resizebooks();
    void books_add(Book, Book*, int);
    void books_remove(Book);
    friend std::ostream& operator <<(std::ostream& out, const Customer& c);
};

#endif
