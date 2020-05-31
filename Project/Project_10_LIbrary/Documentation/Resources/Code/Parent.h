#ifndef _Parent_HH
#define _Parent_HH

/**
 * @brief Класът Parent съдържа основни данни за един профил като няма значение дали е адиминистратор или потребител
 * 
 */

class Parent
{
    private:
    char* username;
    char* password;

    void copy(const Parent& );
    void delete_Parent();

    public:
    Parent();
    Parent(const Parent&);
    Parent& operator =(const Parent&);
    ~Parent();
    Parent(const char*, const char*);
    void setUsername(const char*);
    void setPassword(const char*);
    char* getUsername() const;
    char* getPassword() const;
    void print() const;
    friend std::ostream& operator <<(std::ostream& out, const Parent& p);
    friend std::istream& operator >>(std::istream& in,  Parent& p);
    void read(std::istream& is, Parent& parent);
    void write(std::ostream& os, const Parent& parent);
};

#endif