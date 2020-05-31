#ifndef _Travel_HH
#define _Travel_HH

/**
 * @brief Класът Travel съдържа данни за едно пътуване на потребител от приложението като съдържа:
 * Дестинация
 * Времеви период
 * Рейтинг
 * Коментари
 * Снимки
 * 
 */

class Travel
{
    private:
    char* destination;
    char* duration;
    int rating;
    char* comment;
    char* photos;

    void copy(const Travel& );
    void delete_Travel();

    public:
    Travel();
    Travel(const Travel&);
    Travel& operator =(const Travel&);
    ~Travel();
    Travel(const char*, const char*, const int, const char*, const char*);
    void setDestination(char*);
    void setDuration(char*);
    void setComment(char*);
    void setRating(int);
    void setPhotos(char*);
    char* getDestination() const;
    char* getDuration() const;
    char* getComment() const;
    int getRating() const;
    char* getPhotos() const;
    void print() const;
    friend std::ostream& operator <<(std::ostream& out, const Travel& t);
    friend std::istream& operator >>(std::istream& in,  Travel& t);
    void read(std::istream& is, Travel& travel);
    void write(std::ostream& os, const Travel& travel);
};

#endif