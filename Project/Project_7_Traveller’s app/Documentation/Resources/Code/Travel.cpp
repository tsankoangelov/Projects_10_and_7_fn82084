#include<iostream>
#include<cstring>
#include "Travel.h"

void Travel::copy(const Travel& other)
{
    destination = new (std::nothrow) char[strlen(other.destination) + 1];
    strcpy(destination, other.destination);
    duration = new (std::nothrow) char[strlen(other.duration) + 1];
    strcpy(duration, other.duration);
    comment = new (std::nothrow) char[strlen(other.comment) + 1];
    strcpy(comment, other.comment);
    rating = other.rating;
    photos = new (std::nothrow) char[strlen(other.photos) + 1];
    strcpy(photos, other.photos);
}

void Travel::delete_Travel()
{
    delete[] destination;
    delete[] duration;
    delete[] comment;
    delete[] photos;
}

/**
 * @brief Construct a new Travel:: Travel object
 * 
 */

Travel::Travel()
{
    destination = new char[1];
    duration = new char[1];
    comment = new char[1];
    rating = 0;
    photos = new char[1];
}

/**
 * @brief Construct a new Travel:: Travel object
 * 
 * @param other 
 */

Travel::Travel (const Travel& other)
{
    copy(other);
}

/**
 * @brief 
 * 
 * @param other 
 * @return Travel& 
 */

Travel& Travel::operator=(const Travel& other)
{
    if(this != &other)
    {
        delete_Travel();
        copy(other);
    }
    return *this;
}

/**
 * @brief Destroy the Travel:: Travel object
 * 
 */

Travel::~Travel()
{
    delete_Travel();
}

/**
 * @brief Construct a new Travel:: Travel object
 * 
 * @param _destination 
 * @param _duration 
 * @param _rating 
 * @param _comment 
 * @param _photos 
 */

Travel::Travel(const char* _destination, const char* _duration, const int _rating, const char* _comment, const char* _photos)
{
    delete[] destination;
    destination = new (std::nothrow) char[strlen(_destination) + 1];
    strcpy(destination, _destination);
    delete[] duration;
    duration = new (std::nothrow) char[strlen(_duration) + 1];
    strcpy(duration, _duration);
    delete[] comment;
    comment = new (std::nothrow) char[strlen(_comment) + 1];
    strcpy(comment, _comment);
    rating = _rating;
    delete[] photos;
    photos = new (std::nothrow) char[strlen(_photos) + 1];
    strcpy(photos, _photos);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната destination
 * 
 * @param _destination 
 */

void Travel::setDestination(char* _destination)
{
    delete[] destination;
    destination = new (std::nothrow) char[strlen(_destination) + 1];
    strcpy(destination, _destination);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната duration
 * 
 * @param _duration 
 */

void Travel::setDuration(char* _duration)
{
    delete[] duration;
    duration = new (std::nothrow) char[strlen(_duration) + 1];
    strcpy(duration, _duration);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната comment
 * 
 * @param _comment 
 */

void Travel::setComment(char* _comment)
{
    delete[] comment;
    comment = new (std::nothrow) char[strlen(_comment) + 1];
    strcpy(comment, _comment);
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната rating
 * 
 * @param _rating 
 */

void Travel::setRating(int _rating)
{
    rating = _rating;
}

/**
 * @brief Мутатор с аргумент, който се вкарва в член-данната photos
 * 
 * @param _photos 
 */

void Travel::setPhotos(char* _photos)
{
    delete[] photos;
    photos = new (std::nothrow) char[strlen(_photos) + 1];
    strcpy(photos, _photos);
}

/**
 * @brief Селектор извеждащ стойността на член-данната destination
 * 
 * @return char* 
 */


char* Travel::getDestination() const
{
    return destination;
}

/**
 * @brief Селектор извеждащ стойността на член-данната duration
 * 
 * @return char* 
 */

char* Travel::getDuration() const
{
    return duration;
}

/**
 * @brief Селектор извеждащ стойността на член-данната comment
 * 
 * @return char* 
 */

char* Travel::getComment() const
{
    return comment;
}

/**
 * @brief Селектор извеждащ стойността на член-данната rating
 * 
 * @return int 
 */

int Travel::getRating() const
{
    return rating;
}

/**
 * @brief Селектор извеждащ стойността на член-данната photos
 * 
 * @return char* 
 */

char* Travel::getPhotos() const
{
    return photos;
}

/**
 * @brief Принтира стойностите на член-данните от класа
 * 
 */

void Travel::print() const
{
    std::cout << "Destination:";
    std::cout << getDestination() << std::endl;
    std::cout << "Duration:";
    std::cout << getDuration() << std::endl;
    std::cout << "Comment:";
    std::cout << getComment() << std::endl;
    std::cout << "Rating:";
    std::cout << getRating() << std::endl;
    std::cout << "Photos:";
    std::cout << getPhotos() << std::endl;
}

/**
 * @brief Оператор за извеждане на данни на Travel в поток
 * 
 * @param out 
 * @param t 
 * @return std::ostream& 
 */

std::ostream &operator <<(std::ostream &out, const Travel &t)
{ 
   out <<  t.getDestination() << std::endl << t.getDuration() << std::endl << t.getComment() << std::endl << t.getRating() << std::endl;
   return out;
} 

/**
 * @brief Оператор за въвеждане на данни на Travel в поток
 * 
 * @param in 
 * @param t 
 * @return std::istream& 
 */

std::istream &operator >>(std::istream &in, Travel &t)
{
    char buffer1[50];
    char buffer2[50];
    char buffer3[50];
    char buffer4[50];
    char buffer5[50];
    in.getline(buffer1, 50);
    in.getline(buffer2, 50);
    in.getline(buffer3, 50);
    in.getline(buffer4, 50);
    in.getline(buffer5, 50);
    t.setDestination(buffer1);
    t.setDuration(buffer2);
    t.setComment(buffer3);
    t.setRating(atoi(buffer4));
    t.setPhotos(buffer5);
    return in;
}

/**
 * @brief Четене на данни за Travel от файлов поток
 * 
 * @param is 
 * @param travel 
 */

void Travel::read(std::istream& is, Travel& travel)
{
    is.read(travel.getDestination(), 50);

    is.read(travel.getDuration(), 50);

    is.read(travel.getComment(), 50);

    int rating = travel.getRating();
    char* ratingChar = (char *) &rating;
    is.read(ratingChar, 50);

    is.read(travel.getPhotos(), 50);
}

/**
 * @brief Писане на данни за Travel от файлов поток
 * 
 * @param os 
 * @param travel 
 */

void Travel::write(std::ostream& os, const Travel& travel)
{
    os.write(travel.getDestination(), 50);

    os.write(travel.getDuration(), 50);

    os.write(travel.getComment(), 50);

    int rating = travel.getRating();
    char* ratingChar = (char *) &rating;
    os.write(ratingChar, 50);

    os.write(travel.getPhotos(), 50);
}
