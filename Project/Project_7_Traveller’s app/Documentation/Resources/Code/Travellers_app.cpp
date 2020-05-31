#include<iostream>
#include<cstring>
#include<fstream>
#include "Travellers_app.h"

void Travellers_app::copy(const Travellers_app& other)
{
    capacity_users = other.capacity_users;
    size_users = other.size_users;
    users = new (std::nothrow) User[size_users];
    for (int i = 0; i < capacity_users; i++)
    {
        users[i] = other.users[i];
    }
}

void Travellers_app::delete_Travellers_app()
{
    delete[] users;
}

/**
 * @brief Construct a new Travellers_app::Travellers_app object
 * 
 */
Travellers_app::Travellers_app()
{
    capacity_users = 0;
    size_users = 10;
    users = new User[size_users];
}

/**
 * @brief Construct a new Travellers_app::Travellers_app object
 * 
 * @param other 
 */
Travellers_app::Travellers_app (const Travellers_app& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Travellers_app& 
 */

Travellers_app& Travellers_app::operator=(const Travellers_app& other)
{
    if(this != &other)
    {
        delete_Travellers_app();
        copy(other);
    }
    return *this;
}


/**
 * @brief Destroy the Travellers_app::Travellers_app object
 * 
 */
Travellers_app::~Travellers_app()
{
    delete_Travellers_app();
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_users
 * 
 * @param _capacity_users 
 */

void Travellers_app::setCapacity_users(int _capacity_users)
{
    capacity_users = _capacity_users;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_users
 * 
 * @return int 
 */

int Travellers_app::getCapacity_users() const
{
    return capacity_users;
}

/**
 * @brief Функция, която увеличава размера на capacity_users, ако няма повече място за нови потребители
 * 
 */

void Travellers_app::resizeUsers()
{
    User* new_users = new User[size_users];
    for(int i = 0; i < capacity_users; i++)
    {
        new_users[i] = users[i];
    }
    delete[] users;
    users = new User[size_users*2];
    for(int i = 0; i < capacity_users; i++)
    {
        users[i] = new_users[i];
    }
    size_users = 2*size_users;
    delete[] new_users;
}

/**
 * @brief Функция, която добавя потребител в масива users на приложението
 * 
 * @param user 
 */

void Travellers_app::users_add(User user)
{
    if (size_users == capacity_users + 1)
    {
        resizeUsers();
    }
    users[capacity_users] = user;
    capacity_users++;
}

/**
 * @brief Функция, която премахва потребител в масива users на приложението
 * 
 * @param _username 
 */

void Travellers_app::users_remove(const char* _username)
{
    int index = 0;
    for(int i = 0; i < capacity_users; i++)
    {
        if(strcmp(_username,users[i].getUsername()) == 0)
        {
            index = i;
        }
    }
    User temp = users[index];
    users[index] = users[capacity_users - 1];
    users[capacity_users - 1] = temp;
    capacity_users--;
}

/**
 * @brief Селектор извеждащ масива users
 * 
 * @return User* 
 */


User* Travellers_app::getUsers() const
{
    return users;
}

/**
 * @brief Функция за влизане на профил в приложението
 * 
 * @param _username 
 * @param _password 
 */

void Travellers_app::login(const char* _username, const char* _password)
{
    for (int i = 0; i < capacity_users; i++)
    {
        if(strcmp(users[i].getUsername(), _username) == 0)
        {
            if(strcmp(users[i].getPassword(), _password) == 0)
            {
                std::cout << "Welcome," << users[i].getUsername() << "!";
                current_user = &users[i];
                return;
            }
        }
    }

    current_user = nullptr;
}

/**
 * @brief Функция за излизане на профил от приложението
 * 
 */

void Travellers_app::logout()
{
    std::cout << "Goodbye," << current_user->getUsername() << "!";
    current_user = nullptr;
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */

void Travellers_app::print() const
{
    std::cout << "Users:";
    std::cout << getCapacity_users() << std::endl;
    for (int i = 0; i < getCapacity_users(); i++)
    {
        getUsers()[i].print();
    }
}

/**
 * @brief Оператор за извеждане на данни на Travellers_app в поток
 * 
 * @param out 
 * @param ap 
 * @return std::ostream& 
 */

std::ostream& operator <<(std::ostream& out, const Travellers_app& ap)
{

    out << "Users:";
    out << ap.getCapacity_users() << std::endl;
    for (int i = 0; i < ap.getCapacity_users(); i++)
    {
       out << ap.getUsers()[i] << std::endl;
    }
    return out;
}

/**
 * @brief Оператор за въвеждане на данни на Travellers_app в поток
 * 
 * @param in 
 * @param ap 
 * @return std::istream& 
 */

std::istream& operator >>(std::istream& in,  Travellers_app& ap)
{
    char buffer1[50];
    std::cout << "Users:";
    in.getline(buffer1, 50);
    ap.setCapacity_users(atoi(buffer1));
    for(int i = 0; i < ap.getCapacity_users(); i++)
    {
        in >> ap.getUsers()[i];
    }
    return in;
}

/**
 * @brief Четене на данни за Travellers_app от файлов поток
 * 
 */

void Travellers_app::read()
{
    std::ifstream in(filename, std::ios::binary);
    while(true)
    {
        User user;
        user.read(in, user);
        if(in.eof())
        {
            break;
        }
        users_add(user);
    }
    in.close();
}

/**
 * @brief Запазване на данни за Travellers_app от файлов поток
 * 
 */

void Travellers_app::save() const
{
    std::ofstream out(filename, std::ios::binary);
    for(int i=0; i < capacity_users; i++)
    {
        getUsers()[i].write(out, getUsers()[i]);
    }
    out.close();
}

/**
 * @brief Генериране на файл
 * 
 * @return int 
 */

int main()
{
    std::ofstream out("travellers_app.txt", std::ios::binary);
    
    Travel travel;
    User u;
    std:: cin >> u;
    u.write(out, u);

    out.close();

    std::ifstream in("travellers_app.txt");
    User s;
   
    s.read(in, s);

    //travel.print();
    s.print();
    return 0;
}