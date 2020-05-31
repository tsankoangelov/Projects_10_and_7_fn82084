#ifndef _Travellers_app_HH
#define _Travellers_app_HH
#include "User.cpp"

/**
 * @brief Класът Travellers_app съдържа данни за приложение, което има пътувания и потребители
 * 
 */



class Travellers_app
{
    private:
    User* users;
    int capacity_users;
    int size_users;
    User* current_user;
    char* filename;


    void copy(const Travellers_app& );
    void delete_Travellers_app();

    public:
    Travellers_app();
    Travellers_app(const Travellers_app&);
    Travellers_app& operator =(const Travellers_app&);
    ~Travellers_app();
    void setCapacity_users(int);
    int getCapacity_users() const;
    void resizeUsers();
    void users_add(User);
    void users_remove(const char*);
    User* getUsers() const;
    void login(const char*, const char*);
    void logout();
    void print() const;
    friend std::ostream& operator <<(std::ostream& out, const Travellers_app& ap);
    friend std::istream& operator >>(std::istream& in,  Travellers_app& ap);
    void read();
    void save() const;
};

#endif