#ifndef MOBILEAPP_H
#define MOBILEAPP_H

#include <string>
#include <fstream>
#include "date.h"
using namespace std;

class MobileApp
{
private:
    string name;
    string version;
    date createdate;
    string os;
    double raiting;
    bool isFree;

public:
    MobileApp();
    MobileApp(string n, string v, date d, string o, double r, bool free);
    MobileApp(const MobileApp& other);
    ~MobileApp();

    void set_name(string n);
    void set_version(string v);
    void set_createdate(date d);
    void set_os(string o);
    void set_raiting(double r);
    void set_free(bool free);

    string get_name() const;
    string get_version() const;
    date get_createdate() const;
    string get_os() const;
    double get_raiting() const;
    bool get_free() const;

    void out() const;
    void input();
    void save_file(ofstream& file) const;

    static MobileApp newest_app(MobileApp arr[], int count);
    static void find_app(MobileApp arr[], int count, const string& os);
    static void find_raiting(MobileApp arr[], int count, double rait);
    static void paid(MobileApp arr[], int count, bool paid);
};

#endif