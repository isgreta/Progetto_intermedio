#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

//COSTRUTTORI 
Date::Date()
    {
        d = 1;
        m = 1;
        y = 0;
    }
Date::Date(int day, int month, int year)
    :d{day}, m{month}, y{year} 
    {
        if(!date_valid())
            throw Invalid();
    }

//FUNZIONI GET
string Date::get_date()
{
    return to_string(d)+"-"+to_string(m)+"-"+to_string(y);
}

int Date::get_day()
{
    return d;
}

int Date::get_month()
{
    return m;
}

int Date::get_year()
{
    return y;
}

//FUNZIONI SET, PRINT
void Date::set_date(int day, int month, int year)
{
    d = day;
    m = month;
    y = year;
}

//FUNZIONE VALIDITA' DATA 
bool Date::date_valid()         
{
    
    if(m<1 || m>12||y<0||y>2022||d<=0||d>31) 
    {
        return false;
    }
    else if(m==11||m==4||m==6||m==9)
    {
        if(d<=0||d>30)
            return false;
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        if(d<=0||d>31)
            return false;
    }
    else if(m==2)
    {
        //controlliamo mese febbraio per anni bisestile
        if(y>=1582)
        {
            if(y%400==0)
            {
                if(d<=0||d>29)
                    return false;           //è falso perché l'anno è bisestile e quindi 0<d<=29
            }
            else
            {
                if(y%4==0 && !(y%100==0))
                { 
                    if(d<=0||d>29)
                        return false;       //bisestile
                }
                else
                {   
                    if(d<=0||d>28)
                        return false;       //bisestile
                }
            }
            
        }
        else 
        {   
            if(d<=0||d>28)
            return false;                   //controlla che il giorno sia 0<d<=28
        }
    }
    return true;
}

//OPERATORI
ostream& operator<<(ostream& os, Date& data) //stampa data di copyright su righe separate 
{
    os<<"La data di copyright e': "<<data.get_date()<<"\n";
    return os;
}

