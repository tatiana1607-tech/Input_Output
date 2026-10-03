#pragma once
#include "Toy.h"

class Constructor : public Toy {
private:
    int piecesCount;
    string series;

public:
    Constructor();
    Constructor(const string& article, const string& name, double price, int minAge, int piecesCount, const string& series);

    int get_piecesCount() const;
    string get_series() const;

    void set_piecesCount(int p);
    void set_series(const string& s);

    string get_type() const override;
    void print(ostream& os) const override;
    void input(istream& is) override;

    void saveToFile(ofstream& ofs) const override;
    void loadFromFile(ifstream& ifs) override;
};