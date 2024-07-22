#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Book
{

    public:
        
        //COSTRUTTORI
        Book();
        Book(string name, string lastname, string title_b, string isbn_n);
        Book(string name, string lastname, string title_b, string isbn_n, Date book_d);

        bool state;             //indica stato del libro: disponibile/ in prestito
        class Invalid_isbn{};
        
        //FUNZIONI GET
        string get_title();
        string get_name_a();
        string get_lastname_a();
        string get_isbn();
        bool get_state();
        Date get_date(); //da togliere
        
        //FUNZIONI SET
        void set_title(string title_b);
        void set_name(string name);
        void set_lastname(string lastname);
        void set_isbn(string isbn_n);
        void set_date(Date d);// da torgliere
        void set_state(bool s);
        
        bool isbn_valid(string isbn_n);      //funzione per verificare la validità dell'isbn
        bool book_free();                    //funzione per settare lo stato del libro a disponibile 
        bool book_borrowed();                //funzione per settare lo stato del libro a occupato 
        void print_state();

        friend ostream& operator<<(ostream& os, Book& libro);
        friend bool operator!= (Book& libro1, Book& libro2);
        friend bool operator== (Book& libro1, Book& libro2);

    private:
        string isbn; 
        string title;
        string name_a;          //nome autore
        string lastname_a;      //cognome autore
        Date book_date;         //oggetto classe date 
};

    ostream& operator<<(ostream& os, Book& libro);
    bool operator!= (Book& libro1, Book& libro2);
    bool operator== (Book& libro1, Book& libro2);
    
#endif