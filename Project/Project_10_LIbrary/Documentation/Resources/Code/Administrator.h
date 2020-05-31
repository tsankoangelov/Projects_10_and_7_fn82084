#ifndef _Administrator_HH
#define _Administrator_HH

/**
 * @file Administrator.h
 * @author your name (you@domain.com)
 * @brief Класът Administrator съдържа данни за профил, който е с администраторски права
 * @version 0.1
 * @date 2020-05-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Parent.cpp"
#include "Book.cpp"

class Administrator: public Parent
{
    private:
    void copy(const Administrator& );
    void delete_Administrator();

    public:
    Administrator();
    Administrator(const Administrator&);
    Administrator& operator =(const Administrator&);
    ~Administrator();
    void books_add(Book, Book*, int);
    void books_remove(Book, Book*, int);
    friend std::ostream &operator <<(std::ostream &out, const Administrator &a);
};

#endif
