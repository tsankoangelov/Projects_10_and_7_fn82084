#pragma once

#include<iostream>
#include<cstring>
#include "Parent.h"

void Parent::copy(const Parent& other)
{
    username = new (std::nothrow) char[strlen(other.username) + 1];
    strcpy(username, other.username);
    password = new (std::nothrow) char[strlen(other.password) + 1];
    strcpy(password, other.password);
}

void Parent::delete_Parent()
{
    delete[] username;
    delete[] password;
}

/**
 * @brief Construct a new Parent:: Parent object
 * 
 */

Parent::Parent()
{
    username = new char[1];
    password = new char[1];
}

/**
 * @brief Construct a new Parent:: Parent object
 * 
 * @param other 
 */

Parent::Parent (const Parent& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Parent& 
 */

Parent& Parent::operator=(const Parent& other)
{
    if(this != &other)
    {
        delete_Parent();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the Parent:: Parent object
 * 
 */

Parent::~Parent()
{
    delete_Parent();
}

/**
 * @brief Construct a new Parent:: Parent object
 * 
 * @param _username 
 * @param _password 
 */

Parent::Parent(const char* _username, const char* _password)
{
    delete[] username;
    username = new (std::nothrow) char[strlen(_username) + 1];
    strcpy(username, _username);
    delete[] password;
    password = new (std::nothrow) char[strlen(_password) + 1];
    strcpy(password, _password); 
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната username
 * 
 * @param _username 
 */

void Parent::setUsername(const char* _username)
{
    delete[] username;
    username = new (std::nothrow) char[strlen(_username) + 1];
    strcpy(username, _username);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната password
 * 
 * @param _password 
 */

void Parent::setPassword(const char* _password)
{
    delete[] password;
    password = new (std::nothrow) char[strlen(_password) + 1];
    strcpy(password, _password);
}

/**
 * @brief Селектор извеждащ стойността на член-данната username
 * 
 * @return char* 
 */


char* Parent::getUsername() const
{
    return username;
}

/**
 * @brief Селектор извеждащ стойността на член-данната password
 * 
 * @return char* 
 */

char* Parent::getPassword() const
{
    return password;
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */

void Parent::print() const
{
    std::cout << "Username:";
    std::cout << getUsername() << std::endl;
    std::cout << "Password:";
    std::cout << getPassword() << std::endl;
}

/**
 * @brief Оператор за извеждане на данни на Book в поток
 * 
 * @param out 
 * @param p 
 * @return std::ostream& 
 */


std::ostream &operator <<(std::ostream &out, const Parent &p)
{ 
   out << p.getUsername();
   out << p.getPassword();
   return out;
} 

/**
 * @brief Оператор за въвеждане на данни на Book в поток
 * 
 * @param in 
 * @param p 
 * @return std::istream& 
 */

std::istream &operator >>(std::istream &in,  Parent &p)
{
    char buffer1[50];
    char buffer2[50];
    in.getline(buffer1, 50);
    in.getline(buffer2, 50);
    p.setUsername(buffer1);
    p.setPassword(buffer2);
    return in;  
}

/**
 * @brief Четене на данни за Parent от файлов поток
 * 
 * @param is 
 * @param parent 
 */

void Parent::read(std::istream& is, Parent& parent)
{
    is.read(parent.getUsername(), 50);

    is.read(parent.getPassword(), 50);
}

/**
 * @brief Писане на данни за Parent от файлов поток
 * 
 * @param os 
 * @param parent 
 */
    
    
void Parent::write(std::ostream& os, const Parent& parent)
{
    os.write(parent.getUsername(), 50);

    os.write(parent.getPassword(), 50);

}