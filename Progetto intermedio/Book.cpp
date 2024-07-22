#include <iostream>
#include <string>
#include "Book.h"
#include "Date.h"

using namespace std;

//COSTRUTTORI
Book::Book()
{
    name_a = "";
    lastname_a ="";
    title = "";
    isbn = "000-000-000-0";
    Date book_d;
    state = true;
}

Book::Book(string name, string lastname, string title_b, string isbn_n)
    :name_a{name}, lastname_a{lastname},title{title_b},isbn{isbn_n}
    {
        if(!isbn_valid(isbn))
        {
            throw Invalid_isbn();
        }
        state = true;
    }

Book::Book(string name, string lastname, string title_b, string isbn_n, Date book_d)
    :name_a{name}, lastname_a{lastname},title{title_b},isbn{isbn_n},book_date{book_d}
    {
        if(!isbn_valid(isbn))
        {
            throw Invalid_isbn();
        }
        state = true;
    }

//FUNZIONI GET
string Book::get_title() 
    {return title; }

string Book::get_name_a() 
    {return name_a; }

string Book::get_lastname_a()
    {return lastname_a; }

string Book::get_isbn()
    {return isbn; }
    
bool Book::get_state()
    {return state;}
Date Book::get_date()
    {return book_date;}

//FUNZIONI SET
void Book::set_title(string title_b)
    {title = title_b; }

void Book::set_name(string name)
    {name_a = name; }

void Book::set_lastname(string lastname)
    {lastname_a = lastname; }

void Book::set_isbn(string isbn_n)
    {isbn = isbn_n; }

void Book::set_date(Date d)
    {book_date = d;}
    
void Book::set_state(bool s)
    {state = s; }

//FUNZIONI VALIDITA ISBN'
bool Book::isbn_valid(string isbn_n)
{
    bool valid = false;
    
    if(isbn_n.empty())
        {
            cout<<"L'isbn e' vuoto \n";
            return valid;
        }
    if(isbn.length()!=13)
    {
        cout<<"L'isbn non e' della lunghezza corretta \n";
        return valid;
    }
    if(isbn.length() == 13)
    {
        for(int i = 0; i < 13; i++)
        {
            if (i>=0 && i<3 || i>=4 && i<7 || i>=8 && i<11)
            {
                if(isbn[i]>= 48 && isbn[i]<=57)     //Controllare che siano numeri
                {
                    valid= true;
                }
                else
                {
                    throw Invalid_isbn();
                }
            }
            if(i==3 || i==7 || i==11)       //controllare che siano "-"
            {
                if (isbn[i]== 45)
                {
                    valid = true;
                }
                else
                {
                    throw Invalid_isbn();
                }
            }
            if(i == 12)//Controllare che siano numeri o lettere maiuscole
            {
                if(isbn[i]>=48 && isbn[i]<= 57 ||isbn[i]>= 65 && isbn[i]<=90 || isbn[i] >= 97 && isbn[i] <= 122)
                {
                    valid= true;
                }
                else
                {
                    throw Invalid_isbn();
                }
            }
        }
        return valid;
    }
    return valid;   
}

//FUNZIONI PER MODIFICARE LO STATO DEL LIBRO IN DISPONIBILE/OCCUPATO
bool Book::book_free()
{
    state= true;
    return state;
}

bool Book::book_borrowed()
{
    state = false;
    return state;
}

void Book::print_state()
{
    if(state)
    {
        cout<< "Libro disponibile \n";
    }
    else
    {
        cout<< "Libro in prestito \n";
    }
}

//OPERATORI
bool operator== (Book& libro1, Book& libro2) //verifica che due libri abbiano stesso isbn
{
    if(libro1.get_isbn() == libro2.get_isbn())
    {
        return true;
    }
     else
    {
        return false;
    }
}

bool operator!= (Book& libro1, Book& libro2) //verifica che due libri abbiano isbn diverso
{
    if(libro1.get_isbn() != libro2.get_isbn()) 
    {
        return true;
    }
     else
    {
        return false;
    }
}

ostream& operator<<(ostream& os, Book& libro) //stampa titolo, autore, ISBN su righe separate 
{
    os<<"Il titolo del libro e': "<<libro.get_title()<< "\n"
    <<"L'autore del libro e': "<<libro.get_name_a()<<" "
    <<libro.get_lastname_a()<< "\n"
    <<"L'ISBN del libro e': "<<libro.get_isbn();
    return os;
}