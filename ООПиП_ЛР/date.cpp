#include "date.h"
#include <iostream>
#include <string>
using namespace std;

date::date()
{
    day = 1;
    month = 1;
    year = 1990;
}

date::date(int d, int m, int y)
{
    set_d(d, m, y);
}

void date::set_d(int d, int m, int y)
{
    if ((y >= 1990 && y <= 2026) && (m >= 1 && m <= 12) && (d >= 1 && d <= 31))
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        cout << "ќшибка! ¬ы ввели некорректную дату. Ѕудет установлена дата по умолчанию 01.01.1990" << endl;
        day = 1;
        month = 1;
        year = 1990;
    }
}

int date::get_d() const
{
    return day;
}

int date::get_m() const
{
    return month;
}

int date::get_y() const
{
    return year;
}

string date::toString() const
{
    string result;
    if (day < 10) result += "0";
    result += to_string(day) += ".";
    if (month < 10) result += "0";
    result += to_string(month) += ".";
    result += to_string(year);
    return result;
}

void date::input()
{
    int d, m, y;
    cout << "¬ведите день" << endl;
    cin >> d;
    cout << "¬ведите мес€ц" << endl;
    cin >> m;
    cout << "¬ведите год" << endl;
    cin >> y;
    set_d(d, m, y);
}

bool date::comparedate(const date& other) const
{
    if (year > other.year) return true;
    if (year < other.year) return false;
    if (month > other.month) return true;
    if (month < other.month) return false;
    return day > other.day;
}