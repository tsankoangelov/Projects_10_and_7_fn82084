#ifndef _Book_HH
#define _Book_HH

/**
 * @brief Класът Book съдържа данни за една книга в библиотека като съдържа:
 * Заглавие
 * Автор
 * Жанр
 * Резюме
 * Годината, в която е написана
 * Ключови думи
 * Рейтинг
 * Уникален номер за библиотеката
 * 
 */


class Book
{
    private:
    char* author;
    char* title;
    char* genre;
    char* summary;
    int year_release;
    char* tag;
    double rating;
    int library_ID;

    void copy(const Book& );
    void delete_Book();

    public:
    Book();
    Book(const Book&);
    Book& operator =(const Book&);
    ~Book();
    Book(const char*, const char*, const char*, const char*, const int, const char*, const double, const int);
    void setAuthor(char*);
    void setTitle(char*);
    void setGenre(char*);
    void setSummary(char*);
    void setYear_release(int);
    void setTag(char*);
    void setRating(double);
    void setLibrary_ID(int);
    char* getAuthor() const;
    char* getTitle() const;
    char* getGenre() const;
    char* getSummary() const;
    int getYear_release() const;
    char* getTag() const;
    double getRating() const;
    int getLibrary_ID() const;
    void print() const;
    void books_all_print() const;
    friend std::ostream& operator <<(std::ostream& out, const Book& b);
    friend std::istream& operator >>(std::istream& in,  Book& b);
    void read(std::istream& is, Book& book);
    void write(std::ostream& os, const Book& book);
};

#endif
