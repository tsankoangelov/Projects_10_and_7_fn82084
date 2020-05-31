#include<iostream>
#include<cstring>
#include<stdlib.h>
#include "Library.cpp"

/**
 * @brief Това е менюто, което разчита командите от конзолата, отделя параметрите чрез търсене на интервали мужду тях и ги подава 
 * като параметри на методите на съответния клас 
 * 
 * @return int 
 */

class Menu
{
    public:
    void menu()
    {

    
        Library l;
        
        while (true) 
        {
            Administrator a;
            Customer c;
            Book b;
            Book o;
            char sentence[200];
            int index;
            std::cin.getline(sentence,200);

            char command[50];
            char usernameA[50];
            char usernameC[50];
            char passwordA[60];
            char passwordC[60];
            char adminremove[70];
            char userremove[50];
            char bookad[50];
            char bookremove[50];
            char title[50];
            char author[50];
            char rating[50];
            char genre[50];
            char tag[50];
            char summary[50];
            char yearrelease[50];
            char ID[50];
            char criteria[50];
            char order[50];
            char value[50];
            char criteria1[50];
            char logusername[50];
            char logpassword[50];

            for(int count = 0; sentence[count] != '\0'; count++)
            {
                if(sentence[count] == ' ')
                {
                    index = count;
                    break;
                }
            }
            for(int i = 0; i < index; i++)
            {
                command[i] = sentence[i];
            
            }
            command[index] = '\0';


            if(strcmp(command, "add_admin") == 0)
            {
                int index1 = 0;
                for(int i=10; sentence[i] != '\0'; i++)
                {
                    if(sentence[i] == ' ' || sentence[i] == '\0')
                    {
                        
                        index1 = i;
                        break;
                    }
                }
                for(int j = 0; j < index1 - 9; j++)
                {
                    usernameA[j] = sentence[j+10];
            
                }
                usernameA[index1 - 9] = '\0';

                int index2 = 0;
                for(int k = 10 + strlen(usernameA); sentence[k] != '\0'; k++)
                {
                    if(sentence[k] == ' '|| sentence[k+1] == '\0' )
                    {
                        index2 = k;
                        break;
                    }
                }
                for(int l = 0; l < index2 - 9 - strlen(usernameA); l++)
                {
                    passwordA[l] = sentence[l + 10 + strlen(usernameA)];
                }
                passwordA[index2 - 9 - strlen(usernameA)] = '\0';

                a.setUsername(usernameA);
                a.setPassword(passwordA);
                l.administrators_add(a);
                std::cout << a.getUsername() << std::endl;
                std::cout << a.getPassword() << std::endl;
                std::cout << "Registration Successful!" << std::endl;
                l.print();
            }


            if(strcmp(command, "remove_admin") == 0)
            {
                int index3 = 0;
                for(int i=13; sentence[i] != '\0'; i++)
                {
                    if(sentence[i] == ' ' || sentence[i] == '\0')
                    {
                        
                        index3 = i;
                        break;
                    }
                }
                for(int j = 0; j < index3 - 12; j++)
                {
                    usernameA[j] = sentence[j+13];
            
                }
                usernameA[index3 - 12] = '\0';
                a.setUsername(usernameA);
                l.administrators_remove(a.getUsername());
                std::cout << "Administrator was successfully removed!" << std::endl;
                l.print();
            }

            if(strcmp(command, "add_user") == 0)
            {
                int index4 = 0;
                for(int i=9; sentence[i] != '\0'; i++)
                {
                    if(sentence[i] == ' ' || sentence[i] == '\0')
                    {
                        
                        index4 = i;
                        break;
                    }
                }
                for(int j = 0; j < index4 - 8; j++)
                {
                    usernameC[j] = sentence[j+9];
                }
                usernameC[index4 - 8] = '\0';

                int index5 = 0;
                for(int k = 9 + strlen(usernameC); sentence[k] != '\0'; k++)
                {
                    if(sentence[k] == ' '|| sentence[k+1] == '\0' )
                    {
                        index5 = k;
                        break;
                    }
                }
                for(int l = 0; l < index5 - 8 - strlen(usernameC); l++)
                {
                    passwordC[l] = sentence[l + 9 + strlen(usernameC)];
                }
                passwordC[index5 - 8 - strlen(usernameC)] = '\0';
                
                c.setUsername(usernameC);
                c.setPassword(passwordC);
                l.customers_add(c);
                std::cout << c.getUsername() << std::endl;
                std::cout << c.getPassword() << std::endl;
                std::cout << "Registration Successful!" << std::endl;
                l.print();
            }

            if(strcmp(command, "remove_user") == 0)
            {
                int index6 = 0;
                for(int i=12; sentence[i] != '\0'; i++)
                {
                    if(sentence[i] == ' ' || sentence[i] == '\0')
                    {
                        
                        index6 = i;
                        break;
                    }
                }
                for(int j = 0; j < index6 - 11; j++)
                {
                    usernameA[j] = sentence[j+12];
            
                }
                usernameA[index6 - 11] = '\0';
                c.setUsername(usernameC);
                l.customers_remove(c.getUsername());
                std::cout << "User was successfully removed!" << std::endl;
                l.print();
            }

            if(strcmp(command, "add_book") == 0)
            { 
                std::cout << "Title:" << std::endl;
                std::cin.getline(title, 50);
                std::cout << "Author:" << std::endl;
                std::cin.getline(author, 50);
                std::cout << "Genre:" << std::endl;
                std::cin.getline(genre, 50);
                std::cout << "ID:" << std::endl;
                std::cin.getline(ID, 50);
                std::cout << "Summary:" << std::endl;
                std::cin.getline(summary, 50);
                std::cout << "Year release:" << std::endl;
                std::cin.getline(yearrelease, 50);
                std::cout << "Tag:" << std::endl;
                std::cin.getline(tag, 50);
                std::cout << "Rating:" << std::endl;
                std::cin.getline(rating, 50);
                b.setTitle(title);
                b.setAuthor(author);
                b.setGenre(genre);
                b.setLibrary_ID(atoi(ID));
                b.setSummary(summary);
                b.setYear_release(atoi(yearrelease));
                b.setTag(tag);
                b.setRating(atof(rating));
                l.library_books_add(b);
                b.print();
                std::cout << "Book added!" << std::endl;
                l.print();
            }

            if(strcmp(command, "remove_book") == 0)
            {
                int index14 = 0;
                for(int i=12; sentence[i] != '\0'; i++)
                {
                    if(sentence[i] == ' ' || sentence[i] == '\0')
                    {
                        
                        index14 = i;
                        break;
                    }
                }
                for(int j = 0; j < index14 - 11; j++)
                {
                    bookremove[j] = sentence[j+12];
            
                }
                bookremove[index14 - 11] = '\0';
                b.setTitle(bookremove);
                l.library_books_remove(b);
                std::cout << "User was successfully removed!" << std::endl;
                l.print();
            }
            if(strcmp(command, "еxit") == 0)
            {
                break;
            }
        }
    }
}