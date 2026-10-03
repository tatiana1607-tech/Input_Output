#include "MobileApp.h"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

MobileApp::MobileApp()
{
    name = "Приложение";
    version = "1.0.0";
    createdate = date();
    os = "android";
    raiting = 0;
    isFree = true;
}

MobileApp::MobileApp(string n, string v, date d, string o, double r, bool free)
{
    set_name(n);
    set_version(v);
    set_createdate(d);
    set_os(o);
    set_raiting(r);
    set_free(free);
}

MobileApp::MobileApp(const MobileApp& other)
{
    name = other.name;
    version = other.version;
    createdate = other.createdate;
    os = other.os;
    raiting = other.raiting;
    isFree = other.isFree;
}

MobileApp::~MobileApp() {}

void MobileApp::set_name(string n)
{
    if (!n.empty()) name = n;
    else name = "Без названия";
}

void MobileApp::set_version(string v)
{
    if (!v.empty()) version = v;
    else version = "1.0.0";
}

void MobileApp::set_createdate(date d)
{
    createdate = d;
}

void MobileApp::set_os(string o)
{
    if (!o.empty())
    {
        for (char& c : o) c = tolower(c);
        os = o;
    }
    else os = "android";
}

void MobileApp::set_raiting(double r)
{
    if (r >= 0.0 && r <= 5.0) raiting = r;
    else raiting = 0.0;
}

void MobileApp::set_free(bool free)
{
    isFree = free;
}

string MobileApp::get_name() const { return name; }
string MobileApp::get_version() const { return version; }
date MobileApp::get_createdate() const { return createdate; }
string MobileApp::get_os() const { return os; }
double MobileApp::get_raiting() const { return raiting; }
bool MobileApp::get_free() const { return isFree; }

void MobileApp::out() const
{
    cout << "=================================\n";
    cout << "Название: " << name << endl;
    cout << "Версия: " << version << endl;
    cout << "Дата создания: " << createdate.toString() << endl;
    cout << "ОС: " << os << endl;
    cout << "Рейтинг: " << raiting << endl;
    cout << "Платное: " << (isFree ? "Нет" : "Да") << endl;
    cout << "=================================\n";
}

void MobileApp::input()
{
    string input;
    int ch;

    cout << "Введите название приложения: ";
    getline(cin, input);
    set_name(input);

    cout << "Введите версию приложения: ";
    getline(cin, input);
    set_version(input);

    cout << "Введите дату создания:\n";
    createdate.input();

    cout << "Введите ОС (Android/IOS/Windows/Linux/MacOS): ";
    getline(cin, input);
    for (char& c : input) c = tolower(c);
    set_os(input);

    cout << "Введите рейтинг (0–5): ";
    cin >> raiting;
    set_raiting(raiting);

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Платное? (1 — да, 0 — нет): ";
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    set_free(ch == 1);
}

void MobileApp::save_file(ofstream& file) const
{
    if (file.is_open())
    {
        file << name << "," << version << ","
            << createdate.get_d() << "." << createdate.get_m() << "." << createdate.get_y()
            << "," << os << "," << raiting << "," << isFree << endl;
    }
}

MobileApp MobileApp::newest_app(MobileApp arr[], int count)
{
    if (count == 0) return MobileApp();

    MobileApp newest = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (arr[i].get_createdate().comparedate(newest.get_createdate()))
        {
            newest = arr[i];
        }
    }
    return newest;
}

void MobileApp::find_app(MobileApp arr[], int count, const string& os)
{
    string os_norm = os;
    for (char& c : os_norm) c = tolower(c);

    cout << "Приложения для ОС: " << os_norm << endl;

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        string app_os = arr[i].get_os();
        for (char& c : app_os) c = tolower(c);

        if (app_os == os_norm)
        {
            arr[i].out();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Ничего не найдено.\n";
    }
}

void MobileApp::find_raiting(MobileApp arr[], int count, double rait)
{
    cout << "Приложения с рейтингом ≥ " << rait << endl;

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].get_raiting() >= rait)
        {
            arr[i].out();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Ничего не найдено.\n";
    }
}

void MobileApp::paid(MobileApp arr[], int count, bool paid)
{
    if (paid)
    {
        cout << "Платные приложения:" << endl;
    }
    else
    {
        cout << "Бесплатные приложения:" << endl;
    }

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        
        if (arr[i].get_free() == !paid)
        {
            arr[i].out();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Ничего не найдено.\n";
    }
}