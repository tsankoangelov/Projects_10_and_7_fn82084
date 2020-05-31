#include<iostream>
#include<cstring>
#include<algorithm>
#include "Customer.h"

void Customer::copy(const Customer& other)
{
    capacity_books = other.capacity_books;
    size_books = other.size_books;
    books = new (std::nothrow) Book[size_books];
    for (int i = 0; i < capacity_books; i++)
    {
        books[i] = other.books[i];
    }
}

void Customer::delete_Customer()
{
   delete[] books;
}

/**
 * @brief Construct a new Customer:: Customer object
 * 
 */

Customer::Customer() : Parent()
{
   capacity_books = 0;
    size_books = 10;
    books = new Book[size_books];
}

/**
 * @brief Construct a new Customer:: Customer object
 * 
 * @param other 
 */

Customer::Customer (const Customer& other) : Parent(other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Customer& 
 */

Customer& Customer::operator=(const Customer& other)
{
    if(this != &other)
    {
        Parent::operator=(other);
        delete_Customer();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the Customer:: Customer object
 * 
 */

Customer::~Customer()
{
    delete_Customer();
}

/**
 * @brief Construct a new Customer:: Customer object
 * 
 * @param _username 
 * @param _password 
 */

Customer::Customer(const char* _username, const char* _password) : Parent(_username, _password)
{

}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_books
 * 
 * @param _capacity_books 
 */

void Customer::setCapacity_books(int _capacity_books)
{
    capacity_books = _capacity_books;
}

/**
 * @brief Селектор извеждащ масива books
 * 
 * @return Book* 
 */

Book* Customer::getBooks() const
{
    return books;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_books
 * 
 * @return int 
 */

int Customer::getCapacity_books() const
{
    return capacity_books;
}

/**
 * @brief Функция, която добавя книга в масива books на потребителя
 * 
 * @param book 
 * @param books_array 
 * @param index 
 */

void Customer::books_add(Book book, Book* books_array, int index)
{
    for(int i = 0; i < index; i++)
    {
        if(strcmp(books_array[i].getTitle(), book.getTitle()) == 0)
        {
            if (size_books == capacity_books + 1)
            {
                resizebooks();
            }
            books[capacity_books] = book;
            capacity_books++;
            std::cout << "Successfully added book!" << std::endl;
            return;
        }
    }
    std::cout << "This book is not available" << std::endl;
    
}

/**
 * @brief Функция, която премахва книга в масива books на потребителя
 * 
 * @param b 
 */

void Customer::books_remove(Book b)
{
    for(int i = 0; i < capacity_books; i++)
    {
        if(strcmp(books[i].getTitle(), b.getTitle()) == 0)
        {
            Book temp = books[capacity_books - 1];
            books[capacity_books - 1] = books[i];
            books[i] = temp;
            capacity_books--; 
        }
    }
}

/**
 * @brief Функция, която увеличава размера на capacity_books, ако няма повече място за нови книги
 * 
 */

void Customer::resizebooks()
{
    Book* new_books = new Book[size_books];
    for(int i = 0; i < capacity_books; i++)
    {
        new_books[i] = books[i];
    }
    delete[] books;
    books = new Book[size_books*2];
    for(int i = 0; i < capacity_books; i++)
    {
        books[i] = new_books[i];
    }
    size_books = 2*size_books;
    delete[] new_books;
}

/**
 * @brief Оператор за извеждане на данни на Customer в поток
 * 
 * @param out 
 * @param c 
 * @return std::ostream& 
 */

std::ostream &operator <<(std::ostream &out, const Customer &c)
{ 
   out << (Parent)c;
   return out;
} 










