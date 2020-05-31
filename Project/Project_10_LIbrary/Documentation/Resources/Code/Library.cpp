#include<iostream>
#include<cstring>
#include<fstream>
#include "Library.h"


void Library::copy(const Library& other)
{
    capacity_library_books = other.capacity_library_books;
    size_library_books = other.size_library_books;
    library_books = new (std::nothrow) Book[size_library_books];
    for (int i = 0; i < capacity_library_books; i++)
    {
        library_books[i] = other.library_books[i];
    }
    capacity_customers = other.capacity_customers;
    size_customers = other.size_customers;
    customers = new (std::nothrow) Customer[size_customers];
    for (int i = 0; i < capacity_customers; i++)
    {
        customers[i] = other.customers[i];
    }
    capacity_administrators = other.capacity_administrators;
    size_administrators = other.size_administrators;
    administrators = new (std::nothrow) Administrator[size_administrators];
    for (int i = 0; i < capacity_administrators; i++)
    {
       administrators[i] = other.administrators[i];
    }
}
void Library::delete_Library()
{
    delete[] library_books;
    delete[] customers;
    delete[] administrators;
}

/**
 * @brief Construct a new Library:: Library object
 * 
 */

Library::Library()
{
    capacity_library_books = 0;
    size_library_books = 10;
    library_books = new Book[size_library_books];
    capacity_customers = 0;
    size_customers = 10;
    customers = new Customer[size_customers];
    capacity_administrators = 0;
    size_administrators = 10;
    administrators = new Administrator[size_administrators];
    Administrator a;
    a.setUsername("admin");
    a.setPassword("i<3c++");
    this->administrators_add(a);
}

/**
 * @brief Construct a new Library:: Library object
 * 
 * @param other 
 */

Library::Library (const Library& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Library& 
 */

Library& Library::operator=(const Library& other)
{
    if(this != &other)
    {
        delete_Library();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the Library:: Library object
 * 
 */

Library::~Library()
{
    delete_Library();
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_library_books
 * 
 * @param _capacity_library_books 
 */


void Library::setCapacity_library_books(int _capacity_library_books)
{
    capacity_library_books = _capacity_library_books;
}

/**
 * @brief Селектор извеждащ масива library_books
 * 
 * @return Book* 
 */

Book* Library::getlibrary_books() const
{
    return library_books;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_library_books
 * 
 * @return int 
 */

int Library::getCapacity_library_books() const
{
    return capacity_library_books;
}

/**
 * @brief Функция, която добавя книга в масива library_books на библиотеката
 * 
 * @param book 
 */

void Library::library_books_add(Book book)
{
    if(checkAdministrator() == true)
    {
        std::cout << "No administrator" << std::endl;
    }
    else
    {
        if (size_library_books == capacity_library_books + 1)
    {
        resizelibrary_books();
    }
        current_administrator->books_add(book, getlibrary_books(), capacity_library_books);
        capacity_library_books++;
    }
}

/**
 * @brief Функция, която премахва книга в масива library_books на библиотеката
 * 
 * @param b 
 */

void Library::library_books_remove(Book b)
{
    if(checkAdministrator() == true)
    {
        std::cout << "No administrator" << std::endl;
    }
    else
    {
    current_administrator->books_remove(b, getlibrary_books(), capacity_library_books);
    capacity_library_books--;
    }
}

/**
 * @brief  Функция, която увеличава размера на capacity_library_books, ако няма повече място за нови книги
 * 
 */


void Library::resizelibrary_books()
{
    Book* new_library_books = new Book[size_library_books];
    for(int i = 0; i < capacity_library_books; i++)
    {
        new_library_books[i] = library_books[i];
    }
    delete[] library_books;
    library_books = new Book[size_library_books*2];
    for(int i = 0; i < capacity_library_books; i++)
    {
        library_books[i] = new_library_books[i];
    }
    size_library_books = 2*size_library_books;
    delete[] new_library_books;
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_customers
 * 
 * @param _capacity_customers 
 */


void Library::setCapacity_customers(int _capacity_customers)
{
    capacity_customers = _capacity_customers;
}

/**
 * @brief Селектор извеждащ масива customers
 * 
 * @return Customer* 
 */

Customer* Library::getCustomers() const
{
    return customers;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_customers
 * 
 * @return int 
 */

int Library::getCapacity_customers() const
{
    return capacity_customers;
}

/**
 * @brief  Функция, която увеличава размера на capacity_customers, ако няма повече място за нови потребители
 * 
 */

void Library::resizeCustomers()
{
    Customer* new_customers = new Customer[size_customers];
    for(int i = 0; i < capacity_customers; i++)
    {
        new_customers[i] = customers[i];
    }
    delete[] customers;
    customers = new Customer[size_customers*2];
    for(int i = 0; i < capacity_customers; i++)
    {
        customers[i] = new_customers[i];
    }
    size_customers = 2*size_customers;
    delete[] new_customers;
}

/**
 * @brief Функция, която добавя потребител в масива customers на библиотеката
 * 
 * @param customer 
 */

void Library::customers_add(Customer customer)
{
    if(checkAdministrator() == true)
    {
        std::cout << "No administrator" << std::endl;
    }
    else
    {
    if (size_customers == capacity_customers + 1)
    {
        resizeCustomers();
    }
    customers[capacity_customers] = customer;
    capacity_customers++;
    }
}

/**
 * @brief Функция, която премахва потребител в масива customers на библиотеката
 * 
 * @param _username 
 */

void Library::customers_remove(const char* _username)
{
    if(checkAdministrator() == true)
    {
        std::cout << "No administrator" << std::endl;
    }
    else
    {
    int index = 0;
    for(int i = 0; i < capacity_customers; i++)
    {
        if(strcmp(_username,customers[i].getUsername()) == 0)
        {
            index = i;
        }
    }
    Customer temp = customers[index];
    customers[index] = customers[capacity_customers - 1];
    customers[capacity_customers - 1] = temp;
    capacity_customers--;
    if(capacity_customers == 0)
    {
        current_customer = nullptr;
    }
    }
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната capacity_administrators
 * 
 * @param _capacity_administrators 
 */

void Library::setCapacity_administrators(int _capacity_administrators)
{
    capacity_administrators = _capacity_administrators;
}

/**
 * @brief Селектор извеждащ масива administrators
 * 
 * @return Administrator* 
 */

Administrator* Library::getAdministrators() const
{
    return administrators;
}

/**
 * @brief Селектор извеждащ стойността на член-данната capacity_administrators
 * 
 * @return int 
 */

int Library::getCapacity_administrators() const
{
    return capacity_administrators;
}

/**
 * @brief  Функция, която увеличава размера на capacity_administrators, ако няма повече място за нови администратори
 * 
 */

void Library::resizeAdministrators()
{
    Administrator* new_administrators = new Administrator[size_administrators];
    for(int i = 0; i < capacity_administrators; i++)
    {
        new_administrators[i] = administrators[i];
    }
    delete[] administrators;
    administrators = new Administrator[size_administrators*2];
    for(int i = 0; i < capacity_administrators; i++)
    {
       administrators[i] = new_administrators[i];
    }
    size_administrators = 2*size_administrators;
    delete[] new_administrators;
}

/**
 * @brief Функция, която добавя администратор в масива administrators на библиотеката
 * 
 * @param administrator 
 */

void Library::administrators_add(Administrator administrator)
{
    if (size_administrators == capacity_administrators + 1)
    {
        resizeAdministrators();
    }
    administrators[capacity_administrators] = administrator;
    capacity_administrators++;
    current_administrator = &administrator;
    return;
}

/**
 * @brief Функция, която премахва администратор в масива administrators на библиотеката
 * 
 * @param _username 
 */

void Library::administrators_remove(const char* _username)
{
    int index = 0;
    for(int i = 0; i < capacity_administrators; i++)
    {
        if(strcmp(_username,administrators[i].getUsername()) == 0)
        {
            index = i;
        }
    }
    Administrator temp = administrators[index];
    administrators[index] = administrators[capacity_administrators - 1];
    administrators[capacity_administrators - 1] = temp;
    capacity_administrators--;
    if(capacity_administrators == 0)
    {
        current_administrator = nullptr;
    }
}

/**
 * @brief Функция за влизане на профил като проверява дали е потребител или администратор
 * 
 * @param _username 
 * @param _password 
 */

void Library::login(const char* _username, const char* _password)
{
    for (int i = 0; i < capacity_customers; i++)
    {
        if(strcmp(customers[i].getUsername(), _username) == 0)
        {
            if(strcmp(customers[i].getPassword(), _password) == 0)
            {
                std::cout << "Welcome," << customers[i].getUsername() << "!" << std::endl;
                current_customer = &customers[i];
                return;
            }
        }
    }
    current_customer = nullptr;

    for (int i = 0; i < capacity_administrators; i++)
    {
        if(strcmp(administrators[i].getUsername(), _username) == 0)
        {
            if(strcmp(administrators[i].getPassword(), _password) == 0)
            {
                std::cout << "Welcome," << administrators[i].getUsername() << "!" << std::endl;
                current_administrator = &administrators[i];
                return;
            }
        }
    }
    current_administrator = nullptr;
    std::cout << "Wrong username or password!"  << std::endl;
    return;
}

/**
 * @brief Функция за излизане на потребител 
 * 
 */

void Library::logout()
{
    if(checkCustomer() == true)
    {
        std::cout << "No user found.Please, first login in your account!" << std::endl;
    }
    else
    {
    std::cout << "Goodbye," << current_customer->getUsername() << "!" << std::endl;
    current_customer = nullptr;
    }

}

/**
 * @brief Мутатор извеждащ стойността на член-данната current_customer
 * 
 * @return Customer* 
 */

Customer* Library::getCurrent_Customer() const
{
    return current_customer;
}

/**
 * @brief Мутатор извеждащ стойността на член-данната current_administrator
 * 
 * @return Administrator* 
 */

Administrator* Library::getCurrent_Administrator() const
{
    return current_administrator;
}

/**
 * @brief Функция, която проверява дали има влезнал потребител
 * 
 * @return true 
 * @return false 
 */

bool Library::checkCustomer() const
{
    if(current_customer == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Функция, която проверява дали има влезнал администратор
 * 
 * @return true 
 * @return false 
 */

bool Library::checkAdministrator() const
{
    if(current_administrator == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Функция, която извежда последователно за всяка книга следната информация:
   заглавие, автор, жанр,персонален номер

 * 
 */

void Library::books_all() const
{
    if(checkCustomer() == true)
    {
        std::cout << "No user found.Please, first login in your account!" << std::endl;
    }
    else
    {
        for (int i = 0; i < capacity_library_books; i++)
        {
            library_books[i].books_all_print();
        }
    }
}

/**
 * @brief Функция, която сортира книгите в библиотеката във възходящ или низходящ ред по дадени заглавие или автор, или година, или рейтинг
 * 
 * @param criteria 
 * @param order 
 */

void Library::books_sort(char* criteria, char* order)
{
    if(checkCustomer() == true)
    {
        std::cout << "No user found.Please, first login in your account!" << std::endl;
    }
    else
    {
        if (strcmp(criteria, "title") == 0)
        {
            for(int i = 0; i < capacity_library_books - 1; i++)
            {
                for(int j = 1; j < capacity_library_books; j++)
                {
                    if((strcmp(library_books[i].getTitle(), library_books[j].getTitle()) > 0) && (strcmp(order, "asc") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }
                    else if((strcmp(library_books[i].getTitle(), library_books[j].getTitle()) < 0) && (strcmp(order, "des") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }

                }
            }
        }
        if (strcmp(criteria, "author") == 0)
        {
            for(int i = 0; i < capacity_library_books - 1; i++)
            {
                for(int j = 1; j < capacity_library_books; j++)
                {
                    if((strcmp(library_books[i].getAuthor(), library_books[j].getAuthor()) > 0) && (strcmp(order, "asc") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }
                    else if((strcmp(library_books[i].getAuthor(), library_books[j].getAuthor()) < 0) && (strcmp(order, "des") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }
                }
            }
        }
        if (strcmp(criteria, "rating") == 0)
        {
            for(int i = 0; i < capacity_library_books - 1; i++)
            {
                for(int j = 1; j < capacity_library_books; j++)
                {
                    if(((library_books[i].getRating() >  library_books[j].getRating()) ) && (strcmp(order, "asc") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }
                    else if(((library_books[i].getRating() <  library_books[j].getRating()) ) && (strcmp(order, "des") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }

                }
            }
        }
        if (strcmp(criteria, "year") == 0)
        {
            for(int i = 0; i < capacity_library_books - 1; i++)
            {
                for(int j = 1; j < capacity_library_books; j++)
                {
                    if(((library_books[i].getYear_release() >  library_books[j].getYear_release()) ) && (strcmp(order, "asc") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }
                    else if(((library_books[i].getYear_release() <  library_books[j].getYear_release()) ) && (strcmp(order, "des") == 0))
                    {
                        Book temp = library_books[i];
                        library_books[i] = library_books[j];
                        library_books[j] = temp;

                    }

                }
            }
        }
        
        for (int i = 0; i < capacity_library_books; i++)
        {
        library_books[i].Book::print();
        }
    }
}

/**
 * @brief Функция, която извежда на екрана подробна информация за книга с персонален номер 
 * 
 * @param _ID 
 */


void Library::books_info(const int _ID) const
{
    if(checkCustomer() == true)
    {
        std::cout << "No user found.Please, first login in your account!" << std::endl;
    }
    else
    {
        for(int i = 0; i < capacity_library_books; i++)
        {
            if(library_books[i].getLibrary_ID() == _ID)
            {
                library_books[i].print();
                return;
            }
            std::cout << "No book was found.Please, try again with correct ID!";
        }
    }
}

/**
 * @brief Функция, която търси книга по дадено заглавие, автор или ключова дума
 * 
 * @param criteria 
 * @param value 
 */

void Library::books_find(const char* criteria, const char* value) const
{
    if(checkCustomer() == true)
    {
        std::cout << "No user found.Please, first login in your account!" << std::endl;
    }
    else
    {
        if (strcmp(criteria, "title") == 0)
        {
            for(int i = 0; i < capacity_library_books; i++)
            {
                if(strcmp(library_books[i].getTitle(), value)  == 0)
                {
                    library_books[i].print();
                    return;
                }
            }
        }
        if (strcmp(criteria, "author") == 0)
        {
            for(int i = 0; i < capacity_library_books; i++)
            {
                if(strcmp(library_books[i].getAuthor(), value)  == 0)
                {
                    library_books[i].print();
                    return;
                }
            }
        }
        if (strcmp(criteria, "tag") == 0)
        {
            for(int i = 0; i < capacity_library_books; i++)
            {
                if(strcmp(library_books[i].getTag(), value)  == 0)
                {
                    library_books[i].print();
                    return;
                }
            }
        }
       
        std::cout << "No book was found!" << std::endl;
    }
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */




void Library::print() const
{
    std::cout << "library_books:";
    std::cout << getCapacity_library_books() << std::endl;
    for (int i = 0; i < getCapacity_library_books(); i++)
    {
       getlibrary_books()[i].print();
    }
    std::cout << "Customers:";
    std::cout << getCapacity_customers() << std::endl;
    for (int i = 0; i < getCapacity_customers(); i++)
    {
        getCustomers()[i].print();
    }
    std::cout << "Administrators:";
    std::cout << getCapacity_administrators() << std::endl;
    for (int i = 0; i < getCapacity_administrators(); i++)
    {
        getAdministrators()[i].print();
    }
}

/**
 * @brief Оператор за извеждане на данни на Library в поток
 * 
 * @param out 
 * @param l 
 * @return std::ostream& 
 */

std::ostream &operator <<(std::ostream &out, const Library &l)
{

    out << "library_books:";
    out << l.getCapacity_library_books() << std::endl;
    for (int i = 0; i < l.getCapacity_library_books(); i++)
    {
       out << l.getlibrary_books()[i] << std::endl;
    }
    out << "Customers:";
    out << l.getCapacity_customers() << std::endl;
    for (int i = 0; i < l.getCapacity_customers(); i++)
    {
       out << l.getCustomers()[i] << std::endl;
    }
    out << "Administrators:";
    out << l.getCapacity_administrators() << std::endl;
    for (int i = 0; i < l.getCapacity_administrators(); i++)
    {
       out << l.getAdministrators()[i] << std::endl;
    }
    return out;
}

/**
 * @brief Оператор за въвеждане на данни на Library в поток
 * 
 * @param in 
 * @param l 
 * @return std::istream& 
 */

std::istream& operator >>(std::istream& in,  Library& l)
{
    char buffer1[50];
    char buffer2[50];
    char buffer3[50];
    std::cout << "Books:";
    in.getline(buffer1, 50);
    l.setCapacity_library_books(atoi(buffer1));
    for(int i = 0; i < l.getCapacity_library_books(); i++)
    {
        in >> l.getlibrary_books()[i];
    }
    std::cout << "Customers:";
    in.getline(buffer2, 50);
    l.setCapacity_customers(atoi(buffer2));
    for(int i = 0; i < l.getCapacity_customers(); i++)
    {
        in >> l.getCustomers()[i];
    }
    std::cout << "Admins:";
    in.getline(buffer3, 50);
    l.setCapacity_administrators(atoi(buffer3));
    for(int i = 0; i < l.getCapacity_administrators(); i++)
    {
        in >> l.getAdministrators()[i];
    }
    return in;
}

/**
 * @brief Четене на данни за Library от файлов поток
 * 
 */

void Library::read()
{
    std::ifstream in(filename, std::ios::binary);
    while(true)
    {
        Book book;
        book.read(in, book);
        if(in.eof())
        {
            break;
        }
        library_books_add(book);
    }
    in.close();
}

/**
 * @brief Запазване на данни за Library от файлов поток
 * 
 */

void Library::save() const
{
    std::ofstream out(filename, std::ios::binary);
    for(int i=0; i < capacity_library_books; i++)
    {
        getlibrary_books()[i].write(out, getlibrary_books()[i]);
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
    std::ofstream out("library.txt", std::ios::binary);
    
    Book book;
    Customer c;
    std:: cin >> c;
    c.write(out, (Parent) c);
    std:: cin >> c;
    c.write(out, (Parent) c);

    out.close();

    std::ifstream in("library.txt");
    Customer cpy;
    Customer cpy2;
   
    cpy.read(in, cpy);
    cpy2.read(in, cpy2);

   
    cpy.print();
    cpy2.print();
    return 0;
}


