#ifndef _Library_HH
#define _Library_HH

/**
 * @file Library.h
 * @author your name (you@domain.com)
 * @brief Класът Library съдържа данни за една библиотека, която има книги, потребители и администратори
 * @version 0.1
 * @date 2020-05-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Book.cpp"
#include "Customer.cpp"
#include "Administrator.cpp"

class Library
{
    private:
    Book* library_books;
    int capacity_library_books;
    int size_library_books;
    Customer* customers;
    int capacity_customers;
    int size_customers;
    Customer* current_customer = nullptr;
    Administrator* administrators;
    int capacity_administrators;
    int size_administrators;
    Administrator* current_administrator = nullptr;
    char* filename;

    void copy(const Library& );
    void delete_Library();

    public:
    Library();
    Library(const Library&);
    Library& operator =(const Library&);
    ~Library();
    void setCapacity_library_books(int);
    Book* getlibrary_books() const;
    int getCapacity_library_books() const;
    void library_books_add(Book);
    void library_books_remove(Book);
    void resizelibrary_books();
    void setCapacity_customers(int);
    Customer* getCustomers() const;
    int getCapacity_customers() const;
    void resizeCustomers();
    Customer* getCurrent_Customer() const;
    void setCapacity_administrators(int);
    Administrator* getAdministrators() const;
    int getCapacity_administrators() const;
    void resizeAdministrators();
    Administrator* getCurrent_Administrator() const;
    bool checkAdministrator() const;
    bool checkCustomer() const;
    void customers_add(Customer);
    void customers_remove(const char*);
    void administrators_add(Administrator);
    void administrators_remove(const char*);
    void print() const;
    void login(const char*, const char*);
    void logout();
    void books_all() const;
    void books_sort(char*, char* = "asc");
    void books_find(const char*, const char*) const;
    void books_info(const int) const;
    friend std::ostream &operator <<(std::ostream &out, const Library &l);
    friend std::istream& operator >>(std::istream& in,  Library& l);
    void read();
    void save() const;
};

#endif