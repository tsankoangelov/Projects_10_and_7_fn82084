#include<iostream>
#include<cstring>
#include "User.h"

void User::copy(const User& other)
{
    username = new (std::nothrow) char[strlen(other.username) + 1];
    strcpy(username, other.username);
    password = new (std::nothrow) char[strlen(other.password) + 1];
    strcpy(password, other.password);
    email = new (std::nothrow) char[strlen(other.email) + 1];
    strcpy(email, other.email);
    capacity_travels = other.capacity_travels;
    size_travels = other.size_travels;
    travels = new (std::nothrow) Travel[size_travels];
    for (int i = 0; i < capacity_travels; i++)
    {
        travels[i] = other.travels[i];
    }
}

void User::delete_User()
{
    delete[] username;
    delete[] password;
    delete[] email;
    delete[] travels;
}

/**
 * @brief Construct a new User:: User object
 * 
 */

User::User()
{
    username = new char[1];
    password = new char[1];
    email = new char[1];
    capacity_travels = 0;
    size_travels = 10;
    travels = new Travel[size_travels];
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param other 
 */

User::User (const User& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return User& 
 */

User& User::operator=(const User& other)
{
    if(this != &other)
    {
        delete_User();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the User:: User object
 * 
 */

User::~User()
{
    delete_User();
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param _username 
 * @param _password 
 * @param _email 
 */

User::User(const char* _username, const char* _password, const char* _email)
{
    delete[] username;
    username = new (std::nothrow) char[strlen(_username) + 1];
    strcpy(username, _username);
    delete[] password;
    password = new (std::nothrow) char[strlen(_password) + 1];
    strcpy(password, _password);
    delete[] email;
    email = new (std::nothrow) char[strlen(_email) + 1];
    strcpy(email, _email);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната username
 * 
 * @param _username 
 */

void User::setUsername(char* _username)
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

void User::setPassword(char* _password)
{
    delete[] password;
    password = new (std::nothrow) char[strlen(_password) + 1];
    strcpy(password, _password);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната email
 * 
 * @param _email 
 */

void User::setEmail(char* _email)
{
    delete[] email;
    email = new (std::nothrow) char[strlen(_email) + 1];
    strcpy(email, _email);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_travels
 * 
 * @param _capacity_travels 
 */

void User::setCapacity_travels(int _capacity_travels)
{
    capacity_travels = _capacity_travels;
}

/**
 * @brief Селектор извеждащ стойността на член-данната username
 * 
 * @return char* 
 */

char* User::getUsername() const
{
    return username;
}

/**
 * @brief Селектор извеждащ стойността на член-данната password
 * 
 * @return char* 
 */

char* User::getPassword() const
{
    return password;
}

/**
 * @brief Селектор извеждащ стойността на член-данната email
 * 
 * @return char* 
 */

char* User::getEmail() const
{
    return email;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_travels
 * 
 * @return int 
 */

int User::getCapacity_travels() const
{
    return capacity_travels;
}


/**
 * @brief Функция, която увеличава размера на capacity_travels, ако няма повече място за нови потребители
 * 
 */

void User::resizeTravels()
{
    Travel* new_travels = new Travel[size_travels];
    for(int i = 0; i < capacity_travels; i++)
    {
        new_travels[i] = travels[i];
    }
    delete[] travels;
    travels = new Travel[size_travels*2];
    for(int i = 0; i < capacity_travels; i++)
    {
        travels[i] = new_travels[i];
    }
    size_travels = 2*size_travels;
    delete[] new_travels;
}

/**
 * @brief Функция, която добавя пътуване в масива travels на потребителя
 * 
 * @param travel 
 */


void User::travels_add(Travel travel)
{
    if (size_travels == capacity_travels + 1)
    {
        resizeTravels();
    }
    travels[capacity_travels] = travel;
    capacity_travels++;
}

/**
 * @brief Селектор извеждащ масива travels
 * 
 * @return Travel* 
 */

Travel* User::getTravels() const
{
    return travels;
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */



void User::print() const
{
    std::cout << "Username:";
    std::cout << getUsername() << std::endl;
    std::cout << "Password:";
    std::cout << getPassword() << std::endl;
    std::cout << "Email:";
    std::cout << getEmail() << std::endl;
    std::cout << "Travels:";
    std::cout << getCapacity_travels() << std::endl;
        for (int i = 0; i < getCapacity_travels(); i++)
        {
            getTravels()[i].print();
        }
}

/**
 * @brief Оператор за извеждане на данни на User в поток
 * 
 * @param out 
 * @param u 
 * @return std::ostream& 
 */


std::ostream &operator <<(std::ostream &out, const User &u)
{ 
    out <<  u.getUsername() << std::endl << u.getPassword() << std::endl << u.getEmail() << std::endl;
    out << "Travels:";
    out << u.getCapacity_travels() << std::endl;
    for (int i = 0; i < u.getCapacity_travels(); i++)
    {
       out << u.getTravels()[i] << std::endl;
    }
    return out;
} 

/**
 * @brief Оператор за въвеждане на данни на User в поток
 * 
 * @param in 
 * @param u 
 * @return std::istream& 
 */

std::istream &operator >>(std::istream &in, User &u)
{
    char buffer1[50];
    char buffer2[50];
    char buffer3[50];
    char buffer4[50];
    in.getline(buffer1, 50);
    in.getline(buffer2, 50);
    in.getline(buffer3, 50);
    u.setUsername(buffer1);
    u.setPassword(buffer2);
    u.setEmail(buffer3);
    std::cout << "Travels:";
    in.getline(buffer4, 50);
    u.setCapacity_travels(atoi(buffer4));
    for(int i = 0; i < u.getCapacity_travels(); i++)
    {
        Travel t;
        in >> t;
        u.getTravels()[u.getCapacity_travels()] = t;
        u.setCapacity_travels(u.getCapacity_travels() + 1);
    }
    return in;
}

/**
 * @brief Четене на данни за User от файлов поток
 * 
 * @param is 
 * @param user 
 */

void User::read(std::istream& is, User& user)
{
    is.read(user.getUsername(), 50);

    is.read(user.getPassword(), 50);

    is.read(user.getEmail(), 50);

    for (int i = 0; i < user.getCapacity_travels(); i++) 
    {
        //is.read(user.getTravels()[i].read(is, user.getTravels()[i]), 50);
        is.read(user.getTravels()[i].getDestination(), 50);

        is.read(user.getTravels()[i].getDuration(), 50);

        is.read(user.getTravels()[i].getComment(), 50);

        int rating = user.getTravels()[i].getRating();
        char* ratingChar = (char *) &rating;
        is.read(ratingChar, 50);

        is.read(user.getTravels()[i].getPhotos(), 50);
    }
}

/**
 * @brief Писане на данни за User от файлов поток
 * 
 * @param os 
 * @param user 
 */

void User::write(std::ostream& os, const User& user)
{
    os.write(user.getUsername(), 50);

    os.write(user.getPassword(), 50);

    os.write(user.getEmail(), 50);

    for (int i = 0; i < user.getCapacity_travels(); i++) 
    {
        os.write(user.getTravels()[i].getDestination(), 50);
        os.write(user.getTravels()[i].getDuration(), 50);

        os.write(user.getTravels()[i].getComment(), 50);

        int rating = user.getTravels()[i].getRating();
        char* ratingChar = (char *) &rating;
        os.write(ratingChar, 50);

        os.write(user.getTravels()[i].getPhotos(), 50);
    }
}




