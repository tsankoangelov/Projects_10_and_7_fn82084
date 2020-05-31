#pragma once

#ifndef _User_HH
#define _User_HH

/**
 * @file User.h
 * @author your name (you@domain.com)
 * @brief Класът User съдържа данни за профил, който е регистриран в приложението
 * @version 0.1
 * @date 2020-05-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Travel.cpp"
class User
{
    private:
    char* username;
    char* password;
    char* email;
    Travel* travels;
    int capacity_travels;
    int size_travels;
 

    void copy(const User& );
    void delete_User();

    public:
    User();
    User(const User&);
    User& operator =(const User&);
    ~User();
    User(const char*, const char*, const char*);
    void setUsername(char*);
    void setPassword(char*);
    void setEmail(char*);
    void setCapacity_travels(int);
    char* getUsername() const;
    char* getPassword() const;
    char* getEmail() const;
    int getCapacity_travels() const;
    void resizeTravels();
    void travels_add(Travel);
    Travel* getTravels() const;
    void print() const;
    friend std::ostream& operator <<(std::ostream& out, const User& u);
    friend std::istream& operator >>(std::istream& in,  User& u);
    void read(std::istream& is, User& user);
    void write(std::ostream& os, const User& user);
};

#endif