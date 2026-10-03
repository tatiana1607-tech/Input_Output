#pragma once
#include "Toy.h"

class Electronic : public Toy {
private:
    string batteryType;
    bool hasRemote;

public:
    Electronic();
    Electronic(const string& article, const string& name, double price, int minAge, const string& batteryType, bool hasRemote);

    string get_batteryType() const;
    bool get_hasRemote() const;

    void set_batteryType(const string& b);
    void set_hasRemote(bool r);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;

    void saveToFile(ofstream& ofs) const override;
    void loadFromFile(ifstream& ifs) override;
};