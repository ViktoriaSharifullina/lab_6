#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include<ctype.h>
#include<iomanip>
#include<clocale>
#include<Windows.h>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

/*class date {
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
        day = ((d>=1)&&(d<=31))?d:1;
    }
    void set_month(char* e);
    void set_year(int j);
};*/

char* date::get_month()
{
    char* MONTH = new char[100];
    strcpy(MONTH, month);
    return MONTH;
}
void date::set_day(int d) {
    day = ((d >= 1) && (d <= 31)) ? d : 1;
}
void date::set_year(int j) {
    year = (j >= 1900 && j <= 2021) ? j : 1900;
}
date::~date() {
    delete[]month;
}
date::date() {
    day = 0;
    year = -1;
    month = new char[2];
    strcpy(month, " ");
}
date::date(const date& other)
{
    this->day = other.day;
    delete[] this->month;
    this->month = new char[strlen(other.month) + 1];
    strcpy(this->month, other.month);
    this->year = other.year;
    cout << "�������� ����������� �����������" << endl;
}

/*class Supplier
{
private:
    char* firma;
    char* adr;
    int type;
    date D;

public:
    double balance;
    static int count;   // ������� ������������ �������� ������

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

};*/

char* Supplier::get_firma()
{
    char* Firma = new char[100];
    strcpy(Firma, firma);
    return Firma;
}
char* Supplier::get_adr()
{
    char* Adr = new char[100];
    strcpy(Adr, adr);
    return Adr;
}
int Supplier::get_type() {
    return type;
}
int Supplier::get_count() {
    return count;
}
void Supplier::set_firma(char* f) {
    delete[]firma;
    firma = new char[strlen(f) + 1];
    strcpy(firma, f);
}
void Supplier::set_type(int d) {
    type = d;
}
void Supplier::set_balance(double r) {
    balance = r;
}

int Supplier::month_to_int(char* m) {
    if (strcmp(m, "january") == 0) {
        return 1;
    }
    else if (strcmp(m, "february") == 0) {
        return 2;
    }
    else if (strcmp(m, "march") == 0) {
        return 3;
    }
    else if (strcmp(m, "april") == 0) {
        return 4;
    }
    else if (strcmp(m, "may") == 0) {
        return 5;
    }
    else if (strcmp(m, "june") == 0) {
        return 6;
    }
    else if (strcmp(m, "july") == 0) {
        return 7;
    }
    else if (strcmp(m, "august") == 0) {
        return 8;
    }
    else if (strcmp(m, "september") == 0) {
        return 9;
    }
    else if (strcmp(m, "octomber") == 0) {
        return 10;
    }
    else if (strcmp(m, "november") == 0) {
        return 11;
    }
    else if (strcmp(m, "december") == 0) {
        return 12;
    }
    else return 1;
}

void Supplier::find_data(Supplier* pr, int d, char* m, int& y) {
    int i;
    printf("|%-15s", "�����");
    printf("|%-18s", "�����");
    printf("|%-8s", "���");
    printf("|%-10s", "������");
    printf("|%-5s", "����");
    printf("|%-15s", "�����");
    printf("|%-10s", "���");
    printf("|\n");
    for (i = 0; i < pr->get_count(); i++) {
        if ((d == pr[i].D.get_day()) && (y == pr[i].D.get_year()) && (strcmp(pr[i].D.get_month(), m) == 0)) {
            pr[i].display();
        }
    }
}
void Supplier::sort_data(Supplier* pr, int d, char* m, int& y) {
    int i;
    printf("|%-15s", "�����");
    printf("|%-18s", "�����");
    printf("|%-8s", "���");
    printf("|%-10s", "������");
    printf("|%-5s", "����");
    printf("|%-15s", "�����");
    printf("|%-10s", "���");
    printf("|\n");
    for (i = 0; i < pr->get_count(); i++) {
        if (pr[i].D.get_year() >= y) {
            if (month_to_int(pr[i].D.get_month()) >= month_to_int(m)) {
                if (pr[i].D.get_day() >= d) {
                    pr[i].display();
                }
            }

        }
    }

}
Supplier::Supplier()
{
    firma = new char[30];
    strcpy(firma, " ");
    adr = new char[30];
    strcpy(adr, " ");
    type = 0;
    balance = 0;

}
Supplier::Supplier(char* firm, char* adress, int typ, double balanc, int dayy, char* mon, int yearr) {

    firma = new char[strlen(firm) + 1];
    strcpy(firma, firm);
    adr = new char[strlen(adress) + 1];
    strcpy(adr, adress);
    type = typ;
    balance = balanc;
    D.day = dayy;
    D.month = new char[strlen(mon) + 1];
    strcpy(D.month, mon);
    D.year = yearr;
}
Supplier::~Supplier()
{
    delete[] firma;
    delete[] adr;
}
/*void Supplier::define_sup()
{
   char buff[200];
   count++;
    printf(" ������� �������� ����� ���������� : \n");
    cin.ignore();
    cin.getline(buff, 200);
    set_firma(buff);
    printf("������� ����������� ����� : \n");
    cin.ignore();
    cin.getline(buff, 200);
    set_adr(buff);
    int p;
    printf("������� ��� ����� (1- ��������� �����, 2- ��������� ������������) :\n");
    cin >> p;
    set_type(p);
    double s;
    printf("������� ������ :\n");
    cin >> s;
    set_balance(s);
    int w, l;
    cout << "������� ���� ��������(�����):" << endl;
    cin >> w;
    D.set_day(w);
    cout << "������� ����� ��������(�����):" << endl;
    cin.ignore();
    cin.getline(buff, 20);
    D.set_month(buff);
    cout << "������� ��� �������� ��������(�����):" << endl;
    cin >>l;
    D.set_year(l);
    printf("----------------------------------------------\n");
}*/



void Supplier::add_etalon(Supplier*& pr, int& size) {
    Supplier etalon;
    char buff[200];
    int p, w, l;
    double s;
    cin.ignore();
    printf("������� ����� ��: ");

    cin.getline(buff, 200);
    etalon.set_firma(buff);

    printf("������� ����� ��: ");
    //cin.ignore();
    cin.getline(buff, 200);
    etalon.set_adr(buff);

    printf("������� ��� ��: ");
    cin >> p;
    etalon.set_type(p);

    printf("������� ������ ��: ");
    cin >> s;
    etalon.set_balance(s);

    printf("������� ���� �������� ��: ");
    cin >> w;
    etalon.D.set_day(w);
    cin.ignore();
    printf("������� ����� �������� (�����) ��: ");

    cin.getline(buff, 200);
    etalon.D.set_month(buff);

    printf("������� ��� �������� (�����) ��: ");
    cin >> l;
    etalon.D.set_year(l);

    int flag = 0, count_etalon = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(pr[i].get_firma(), etalon.get_firma()) == 0) {
            if (strcmp(pr[i].get_adr(), etalon.get_adr()) == 0) {
                if (pr[i].get_type() == etalon.get_type()) {
                    if (pr[i].get_balance() == etalon.get_balance()) {
                        if (pr[i].D.get_day() == etalon.D.get_day()) {
                            if (strcmp(pr[i].D.get_month(), etalon.D.get_month()) == 0) {
                                if (pr[i].D.get_year() == etalon.D.get_year()) {
                                    flag = 1;
                                    count_etalon++;
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    cout << flag << endl;
    if (flag == 0) {
        if (count < size) {
            printf("������� ����� ��������� �������. \n");
            char* k;
            k = etalon.get_firma();
            pr[count].set_firma(k);
            pr[count].set_adr(etalon.get_adr());
            pr[count].set_type(etalon.get_type());
            pr[count].set_balance(etalon.get_balance());
            pr[count].D.set_day(etalon.D.get_day());
            pr[count].D.set_month(etalon.D.get_month());
            pr[count].D.set_year(etalon.D.get_year());
            count++;
        }
        else {
            Supplier* sup = new Supplier[size + 1];
            for (int i = 0; i < count; i++) {
                sup[i] = pr[i];
            }
            delete[]pr;
            pr = sup;
            pr[count] = etalon;
            size = size + 1;
            count = count + 1;
        }
    }
    else if (flag == 1) {
        printf("----------------------------------------------\n");
        printf("���������� ������������� ��������: ");
        printf("%d\n", count_etalon);
        printf("----------------------------------------------\n");
    }

    cout << flag << endl;
    printf("----------------------------------------------\n");
}

int Supplier::proverka_month(char* mon) {
    if ((strcmp(mon, "january") == 0) || (strcmp(mon, "february") == 0) || (strcmp(mon, "march") == 0) || (strcmp(mon, "april") == 0) || (strcmp(mon, "may") == 0) || (strcmp(mon, "june") == 0) || (strcmp(mon, "july") == 0) || \
        (strcmp(mon, "august") == 0) || (strcmp(mon, "september") == 0) || (strcmp(mon, "octomber") == 0) || (strcmp(mon, "november") == 0) || (strcmp(mon, "december") == 0))
    {
        return 1;
    }
    else  return 0;
}

void  Supplier::display()
{

    printf("|%-15s", firma);
    printf("|%-18s", adr);
    printf("|%-8d", type);
    printf("|%-10.2lf", balance);
    printf("|%-5d", D.get_day());
    printf("|%-15s", D.get_month());
    printf("|%-10d|", D.get_year());
    printf("\n");
}
void Supplier::add_sup(Supplier*& pr, int& n) { // ������� ���������� ����� �����

    int flag = 1;

    int i = (pr->get_count());
    if (i < n) {
        for (i; i < n; i++)
        {
            cout << "������� �������� ����� ����������, ����������� �����, ��� �����, ������, ����, ����� � ��� ��������\n";
            cin >> pr[i];
            cout << "��� ����������� ������� - 1,����� ��������� - 0 : ";
            cin.ignore();
            cin >> flag;
            if (flag == 0) break;
        }
    }
    if (i >= n)
    { //���� ��������� ����������� ������� �������,������� �����

        Supplier* temp = new   Supplier[n + 1];//������� ������ ��� ����������� ������������ ������
        for (int j = 0; j < n; j++)
        {
            temp[j] = pr[j];
        }
        cout << "����������� ��������� �������!" << endl;
        cout << "������� �������� ����� ����������, ����������� �����, ��� �����, ������, ����, ����� � ��� ��������\n";
        cin >> temp[n];
        count++;
        n = n + 1;//��������� ����������� �������
        delete[] pr;//�������
        pr = temp;

        cout << pr->get_count() << endl << "����������� ��������� �������!" << endl;
        system("pause");
    }

}
void  Supplier::menu(Supplier* pr, int& N) {
    int flag = 1;
    while (TRUE)
    {
        int var;
        printf(" ������� ����� ������� :\n");
        printf(" 1) �������� ����� �����.\n");
        printf(" 2) ������� ���������� � ��������� ����.\n");
        printf(" 3) ����� ���������� �� �������� �����.\n");
        printf(" 4) ����� ����������� ��������� ����.\n");
        printf(" 5) ����������� �� ���������� ������.\n");
        printf(" 6) ����� ��� �������� � �������� �����.\n");
        printf(" 7) ����� ��� �������� � ����� ������, ��� ��������.\n");
        printf(" 8) ����� ���������� �������� � ����.\n ");
        printf(" 9) ��������� � ����� �� ���������.\n ");

        printf("----------------------------------------------\n");
        printf(" ������� ����� ������� : ");
        scanf("%d", &var);

        switch (var) {
        case 1:
        {
            add_sup(pr, N);
            cout << pr->get_count();
            printf("----------------------------------------------\n");
            break;
        }
        case 2:
        {
            Showspisok(pr);
            break;
        }
        case 3:
        {
            char nfirma[100];
            printf("�������� �����, ������� ����� ����� : ");
            cin.ignore();
            cin.getline(nfirma, 100);
            char* search = new char[strlen(nfirma) + 1];
            strcpy(search, nfirma);
            find_firma(pr, search, N);
            printf("----------------------------------------------\n");
            break;
        }
        case 4:
        {
            int t;
            printf("��� �����������, ������� ����� �����\n");
            printf("1- ��������� �����, 2- ��������� ������������ : ");
            scanf("%d", &t);
            find_type(pr, t, N);
            printf("----------------------------------------------\n");
            break;
        }
        case 5:
        {
            find_saldo(pr);
            Showspisok(pr);
            cout << "\n----------------------------------------------" << endl;
            break;

        }
        case 6:
        {
            char buff[200];
            int dayy, yearr;
            printf("-----�������� ����----- \n");
            printf("����: ");
            scanf("%d", &dayy);
            dayy = (dayy >= 1 && dayy <= 31) ? dayy : 1;
            cin.ignore();
            cout << dayy << endl;

            int f = 0;
            while (!f) {
                printf("�����: ");
                cin.getline(buff, 20);
                char* monthh = new char[strlen(buff) + 1];

                if (proverka_month(buff) == 1) {
                    strcpy(monthh, buff);

                    printf("���: ");
                    scanf("%d", &yearr);
                    yearr = (yearr >= 1900 && yearr <= 2021) ? yearr : 1900;
                    cout << yearr << endl;
                    printf("----------------------- \n");
                    find_data(pr, dayy, monthh, yearr);
                    cout << "\n----------------------------------------------" << endl;
                    f = 1;
                }
                else {
                    cout << "������� ������������ ������!!!! ��������� ����...." << endl;
                }
            }
            break;
        }
        case 7:
        {
            char buff[200];
            int dayy, yearr;
            printf("-----�������� ����----- \n");
            printf("����(�����): ");
            scanf("%d", &dayy);
            dayy = (dayy >= 1 && dayy <= 31) ? dayy : 1;
            cin.ignore();

            int f = 0;
            while (f == 0) {
                printf("�����: ");
                cin.getline(buff, 20);
                char* monthh = new char[strlen(buff) + 1];

                if (proverka_month(buff) == 1) {
                    strcpy(monthh, buff);

                    printf("���: ");
                    scanf("%d", &yearr);
                    yearr = (yearr >= 1900 && yearr <= 2021) ? yearr : 1900;
                    cout << yearr << endl;
                    printf("----------------------- \n");
                    sort_data(pr, dayy, monthh, yearr);
                    cout << "��������� ���������� ����. " << endl;
                    cout << "\n----------------------------------------------" << endl;
                    f = 1;
                }
                else {
                    cout << "������� ������������ ������!!!! ��������� ����...." << endl;
                }
            }
            break;
        }
        case 8:
        {
            add_etalon(pr, N);
            cout << "\n----------------------------------------------" << endl;
            break;
        }
        case 9:
        {
            flag = 0;
            pr->save_base(pr);
            system("pause");
            break;
        }
        }
    }
}

void Supplier::Showspisok(Supplier* pr) { //������� ��� ������ �������
   // system("cls");
    int i;
    cout << "----------------------------------------------" << endl;
    printf("\nINFORMATION\n\n");
    printf("|%-15s", "�����");
    printf("|%-18s", "�����");
    printf("|%-8s", "���");
    printf("|%-10s", "������");
    printf("|%-5s", "����");
    printf("|%-15s", "�����");
    printf("|%-10s", "���");
    printf("|\n");
    for (i = 0; i < pr->get_count(); i++) {
        pr[i].display();
    }
    cout << "\n----------------------------------------------" << endl;
    printf("\n");

}
void find_firma(Supplier* pr, char* nfirma, int& n) { //������� ��� ������ ���������� �� �������� �����
    int i;
    printf("|%-15s", "�����");
    printf("|%-18s", "�����");
    printf("|%-8s", "���");
    printf("|%-10s", "������");
    printf("|%-5s", "����");
    printf("|%-15s", "�����");
    printf("|%-10s", "���");
    printf("|\n");
    for (i = 0; i < n; i++) {
        if (strcmp(pr[i].get_firma(), nfirma) == 0) {
            pr[i].display();
        };
    }
}
void Supplier::find_type(Supplier* pr, int t, int& n) { //������� ��� ������ ���������� ��������� ����
    int i;
    printf("|%-15s", "�����");
    printf("|%-18s", "�����");
    printf("|%-8s", "���");
    printf("|%-10s", "������");
    printf("|\n");

    for (i = 0; i < n; i++) {
        if (pr[i].get_type() == t) {
            pr[i].display();
        };
    }
}
void Supplier::operator=(const Supplier& COPY) {
    delete[]firma;
    delete[]adr;
    delete[] D.month;

    firma = new char[strlen(COPY.firma) + 1];
    strcpy(firma, COPY.firma);
    adr = new char[strlen(COPY.adr) + 1];
    strcpy(adr, COPY.adr);

    type = COPY.type;
    balance = COPY.balance;
    D.month = new char[strlen(COPY.D.month) + 1];
    strcpy(D.month, COPY.D.month);
    D.day = COPY.D.day;
    D.year = COPY.D.year;

}
istream& operator>> (istream& in, Supplier& obj) {
    char* buff_1 = new char[100];
    char* buff_2 = new char[100];
    char* buff_3 = new char[100];
    char* firm;
    char* adress;
    char* mon;
    int typ, dayy, yearr;
    double balanc;
    in >> buff_1 >> buff_2 >> typ >> balanc >> dayy >> buff_3 >> yearr;
    firm = new char[strlen(buff_1) + 1];
    strcpy(firm, buff_1);
    adress = new char[strlen(buff_1) + 1];
    strcpy(adress, buff_2);
    mon = new char[strlen(buff_3) + 1];
    strcpy(mon, buff_3);
    obj = Supplier(firm, adress, typ, balanc, dayy, mon, yearr);

    delete[] buff_1;
    delete[] buff_2;
    delete[] buff_3;
    return in;

}

void Supplier::find_saldo(Supplier* test) {
    int size = test->get_count();
    Supplier sort;
    int i, j;
    for (i = 0; i < (size); i++) {
        for (j = i + 1; j < (size); j++) {
            if (test[i].get_balance() < test[j].get_balance()) {
                sort = test[i];
                test[i] = test[j];
                test[j] = sort;
            }
        }
    }
}
void Supplier::save_base(Supplier* test)
{
    const char* name = "Lab2.txt";
    ofstream fo(name, ios::out | ios::trunc);//out - �������� ������(����� ���������� � ����), trunc - ������ ���������� ����� ���������
    if (!fo.is_open()) // ���� ���� �� ������
        cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else {

        fo << (test->get_count()) << endl;
        for (int i = 0; i < (test->get_count()); i++) {
            fo << test[i].firma << endl;
            fo << test[i].adr << endl;
            fo << test[i].type << endl;
            fo << test[i].balance << endl;
            fo << test[i].D.get_day() << endl;
            fo << test[i].D.get_month() << endl;
            fo << test[i].D.get_year() << endl;
        }
        fo.close();
        cout << "���� ������� ��������!" << endl;

    }
}
void Supplier::loading(Supplier*& test, int& size) {

    int s, l, d, y;
    char buff[200];
    const char* name = "Lab2.txt";
    ifstream fin(name, ios::binary | ios::in);

    //(ios::binary) ������ ����������� ��� ����, ��� ������-���� ��������������
    // (ios::in) ��������� ������� (�������� ������) �� ������

    if (!fin.is_open()) cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
    else {
        fin >> s;
        size = s;
        delete[]test;
        Supplier* p = new Supplier[s];
        test = p;
        for (int i = 0; i < s; i++) {
            delete[] test[i].firma;
            fin >> buff;
            test[i].firma = new char[strlen(buff) + 1];
            strcpy(test[i].firma, buff);
            delete[] test[i].adr;
            fin >> buff;
            test[i].adr = new char[strlen(buff) + 1];
            strcpy(test[i].adr, buff);

            fin >> l;
            test[i].type = (int)l;
            fin >> test[i].balance;
            fin >> d;
            test[i].D.set_day(d);
            delete[] test[i].D.get_month();
            fin >> buff;
            test[i].D.set_month(buff);
            fin >> y;
            test[i].D.set_year(y);
        }
    }
    count = s;
    fin.close();
}
void Supplier::init(Supplier*& test, int& N) {
    int flag = 1;
    int i;
    for (i = 0; i < N; i++)
    {

        cin >> test[i];
        count++;
        cout << "����� ��� - 1, ��������� ���������� - 0." << endl;
        cin.ignore();
        cin >> flag;
        if (flag == 0) break;
    }

    if (i >= N)
    {
        do {
            Supplier* prr = new Supplier[N + 50];
            for (int j = 0; j < N; j++) {//��������
                prr[j] = test[j];
            }
            delete[]test;
            N = N + 50;//����� ������
            for (i; i < N; i++) {
                cin >> prr[i];
                count++;
                cout << "����� ��� - 1, ��������� ���������� - 0." << endl;
                cin.ignore();
                cin >> flag;

            }
            test = prr;

        } while (flag != 0);
    }
}
