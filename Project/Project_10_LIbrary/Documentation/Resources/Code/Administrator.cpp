#include<iostream>
#include<cstring>
#include "Administrator.h"

void Administrator::copy(const Administrator& other)
{
    
}

void Administrator::delete_Administrator()
{
}



Administrator::Administrator() : Parent()
{

}

Administrator::Administrator (const Administrator& other) : Parent(other)
{
    
}

/**
 * @brief 
 * 
 * @param other 
 * @return Administrator& 
 */

Administrator& Administrator::operator=(const Administrator& other)
{
    if(this != &other)
    {
        Parent::operator=(other);
        
    }
    return *this;
}

/**
 * @brief Destroy the Administrator:: Administrator object
 * 
 */

Administrator::~Administrator()
{
    delete_Administrator();
}

/**
 * @brief Помощна функция към library_books_add
 * 
 * @param book 
 * @param books_array 
 * @param index 
 */

void Administrator::books_add(Book book, Book* books_array, int index)
{
    books_array[index] = book;
}

/**
 * @brief Помощна функция към library_books_remove
 * 
 * @param b 
 * @param books_array 
 * @param index 
 */

void Administrator::books_remove(Book b, Book* books_array, int index)
{
   for(int i = 0; i < index; i++)
    {
        if(strcmp(books_array[i].getTitle(), b.getTitle()) == 0)
        {
            Book temp = books_array[index - 1];
            books_array[index - 1] = books_array[i];
            books_array[i] = temp;
        }
    }
}

/**
 * @brief Оператор за извеждане на данни на Administrator в поток
 * 
 * @param out 
 * @param a 
 * @return std::ostream& 
 */

std::ostream &operator <<(std::ostream &out, const Administrator &a)
{ 
   out << (Parent)a;
   return out;
} 



