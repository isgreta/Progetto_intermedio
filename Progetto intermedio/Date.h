#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
    public:
        //COSTRUTTORI
        Date();
        Date(int day, int month, int year);
       
        //FUNZIONI E CLASSE VALIDITA' DATA
        class Invalid {};
        bool date_valid();

        string get_date();
        int get_day();
        int get_month();
        int get_year();
        void set_date(int day, int month, int year);
        
        friend ostream& operator<<(ostream& os, Date& data);
    
    private:
        int d;  //giorno 
        int m;  //mese
        int y;  //anno
};

    ostream& operator<<(ostream& os, Date& data);
    
#endif