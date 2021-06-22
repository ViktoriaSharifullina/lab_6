#pragma once
#include"classes.h"
class date {
    int day;
    char* month;
    int year;
    friend class Supplier;
public:
    date();
    ~date();
    int get_day() {
        return day;
    };
    char* get_month();
    int get_year() {
        return year;
    }
    date(const date& object);

    void set_day(int d) {
        day = ((d >= 1) && (d <= 31)) ? d : 1;
    }
    void set_month(char* e);
    void set_year(int j);
};
class Supplier
{
private:
    char* firma;
    char* adr;
    int type;
    date D;

public:
    double balance;
    static int count;   // счетчик существующих объектов класса

    Supplier();
    ~Supplier();
    friend class Data;
    friend void find_firma(Supplier* test, char* nfirma, int& N);
    void find_data(Supplier*test, int d, char* m, int& y);
    void sort_data(Supplier* test, int d, char* m, int &y);
    int month_to_int(char* m);
    void add_sup(Supplier*& test, int& N);
    void Showspisok(Supplier* pr);
    void find_type(Supplier* test,int t, int& N);
    void find_saldo(Supplier * test);
    Supplier(char* firm, char* adress, int typ,double balanc, int dayy, char* mon, int yearr);
    //void define_sup();
    void display();

    void menu(Supplier* test, int& N);
    void operator=(const Supplier& COPY );
    friend istream& operator>> (istream& in, Supplier& supplier);
    void save_base(Supplier* test);
    void loading(Supplier*& test, int& size);
    void init(Supplier*& test, int& size);
    void add_etalon(Supplier*& pr, int& n);
    int proverka_month(char* monthh);


    double get_balance() {
       return balance;
    }
    char* get_firma();
    char* get_adr();
    int get_type();
    int get_count();
    void set_adr(char* n);
    void set_firma(char* f);
    void set_type(int d);
    void set_balance(double r);

};

istream& operator>> (istream& in, Supplier& obj);