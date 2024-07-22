#include <iostream>                                                            
#include <string>                   
#include <vector>                   
#include "Date.h"                   
#include "Book.h"

using namespace std;

int main(void)
{
    bool continua = true;   //continua ciclo finchè non premo 4
    bool presente = false;  //libro già esistente nella libreria 
    int day, month, year;
    string nome, cognome, titolo, isbn;
    vector<Book> shelf(10);

    Date libro_1(19, 5, 2006);
    Date libro_3(21, 9, 1937);
    Date libro_4(4, 2, 2003);

    Book libro_std();
    Book libro1("Dan", "Brown", "Il Codice da Vinci", "111-111-111-A", libro_1);   
    Book libro2("J.K", "Rawling", "H.P. e la pietra filosofale", "222-222-222-B");  
    Book libro3("J.R.R", "Tolkien", "Lo hobbit", "333-333-333-C", libro_3);         
    Book libro4("Bill", "Bryson", "Breve storia di (quasi) tutto", "444-444-444-4", libro_4);   
    Book libro5("J.K", "Rawling", "H.P. e la pietra filosofale", "222-222-222-B");             
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4"); 

    shelf.erase(shelf.begin(), shelf.begin()+6);
    shelf.insert(shelf.begin(), libro1);     //Inserisco Libro1 alla posizione 0
    shelf.insert(shelf.begin() + 1, libro2); //Inserisco Libro2 alla posizione 1
    shelf.insert(shelf.begin() + 2, libro3); //Inserisco Libro3 alla posizione 2
    shelf.insert(shelf.begin() + 3, libro4); //Inserisco Libro4 alla posizione 3
    shelf.insert(shelf.begin() + 4, libro5); //Inserisco Libro5 alla posizione 4
    shelf.insert(shelf.begin() + 5, my_favourite_book); //Inserisco My_favourite_book alla posizione 5

    cout<<endl<<"PROVA OVERLOADING \'<<\'"<<endl;

    cout<<"La libreria contiene: "<<endl;
    for(int i = 0; i <shelf.size(); i++)
    {
        cout<<endl<<"---------LIBRO("<<i+1<<")---------"<<endl<<endl<<shelf.at(i)<<endl;
    }
    
    //Modifichiamo il libro1 con le funzioni set
    cout<<endl<<"PROVA GET E SET: modifico parametri del primo libro";
    
    shelf.at(0).set_title("Il giovane Holden");
    shelf.at(0).set_name("Jerome David");
    shelf.at(0).set_lastname("Salinger");
    shelf.at(0).set_isbn("555-555-555-F");
    libro_1.set_date(16 , 7 ,1951);
    shelf.at(0).book_borrowed();  //libro occupato
    cout<<endl<<endl;

    //Controlliamo che il libro1 sia stato modificato correttamente con le funzione get
    cout<<shelf.at(0).get_title()<<endl;
    cout<<shelf.at(0).get_name_a()<<endl;
    cout<<shelf.at(0).get_lastname_a()<<endl;
    cout<<shelf.at(0).get_isbn()<<endl;
    cout<<libro_1;
    shelf.at(0).print_state();
    cout<<endl<<"Ora la libreria contiene al primo posto: "<<endl;

    cout<<"---------LIBRO("<<1<<")---------"<<endl<<endl<<shelf.at(1)<<endl<<endl;
    //Cambiamo stato libro1 da occupato in libero
    cout << "CAMBIO STATO LIBRO 1 DA OCCUPATO A DISPONIBILE: "<<endl;
    shelf.at(0).book_free();
    shelf.at(0).print_state();

    cout<<endl<<endl<<"PROVA OPERATORE \'==\'"<<endl;

    if(libro2==libro5)
    {
        cout<<"Gli ISBN del libro 2 e libro 5 coincidono"<<endl;
    }
    else
    {
        cout<< "Gli ISBN del libro 2 e libro 5 non coincidono"<<endl;
    }

    cout<<endl<<endl<<"PROVA OPERATORE "<<"\'!=\'"<<endl;
    if (libro2!=libro3)
    {
        cout<<"Gli ISBN del libro 2 e del libro 3 non coincidono"<<endl;
    }
    else
    {
        cout<<"Gli ISBN del libro 2 e del libro 3 coincidono"<<endl;
    }
    
    cout<<endl<<"PROVA FUNZIONI VALIDITA' DATA E ISBN"<<endl;
    
    try
    {
        Date libro_7 (1,13,2002);
        if(libro_7.date_valid() == true)
        {
            cout<<"La data inserita è valida";
        }
        else
        {
            throw (libro_7);
        }
    }
    catch(Date::Invalid)
    {
        cout << "Errore: Data =1-13-2002 non valida"<<endl;
    }
    
    try
    {
        string isbn_n = "111-2s5-vvv.0";
        Book prova("mar 09", "montagna", "casa", isbn_n);
    }
    catch(Book::Invalid_isbn)
    {
        cout << "Errore: ISBN = 111-2s5-vvv.0 non valido"<<endl;
    }


    

    
    
    

   
    
    
    
    
    
}