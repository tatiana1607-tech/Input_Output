#ifndef DATE_H
#define DATE_H

#include<string>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;
public:
    date();
    date(int d, int m, int y);
    void set_d(int d, int m, int y);
    int get_d() const;
    int get_m() const;
    int get_y() const;
    string toString() const;
    void input();
    bool comparedate(const date& other) const;
};

#endif