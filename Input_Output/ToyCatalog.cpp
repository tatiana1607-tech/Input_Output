#include "ToyCatalog.h"
#include <iomanip>

using namespace std;

ToyCatalog::ToyCatalog() : data(nullptr), count(0), capacity(0) {}

ToyCatalog::ToyCatalog(const ToyCatalog& other) : data(nullptr), count(0), capacity(0) {
    if (other.count > 0) {
        capacity = other.capacity;
        data = new Toy * [capacity];
        for (int i = 0; i < other.count; ++i) {
            data[i] = other.data[i];
        }
        count = other.count;
    }
}

ToyCatalog& ToyCatalog::operator=(const ToyCatalog& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        count = 0;
        capacity = 0;

        if (other.count > 0) {
            capacity = other.capacity;
            data = new Toy * [capacity];
            for (int i = 0; i < other.count; ++i) {
                data[i] = other.data[i];
            }
            count = other.count;
        }
    }
    return *this;
}

ToyCatalog::~ToyCatalog() {
    for (int i = 0; i < count; ++i) delete data[i];
    delete[] data;
}

int ToyCatalog::getCount() const {
    return count;
}

void ToyCatalog::ensureCapacity() {
    if (count < capacity) return;
    int newCap = (capacity == 0) ? 4 : capacity * 2;
    Toy** newData = new Toy * [newCap];
    for (int i = 0; i < count; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCap;
}

void ToyCatalog::printTable(ostream& os) const {
    if (count == 0) {
        os << "\nКаталог пуст.\n";
        return;
    }

    os.setf(ios::left, ios::adjustfield);
    os.setf(ios::fixed, ios::floatfield);
    os.setf(ios::showpoint);
    os.setf(ios::showpos);
    

    os << "\n" << setfill('=') << setw(97) << "=" << setfill(' ') << "\n";
    os << setw(10) << "Артикул"
        << setw(22) << "Название"
        << setw(10) << "Цена"
        << setw(8) << "Возр."
        << setw(14) << "Тип"
        << setw(18) << "Хар-ка 1"
        << setw(14) << "Хар-ка 2" << "\n";
    os << setfill('-') << setw(97) << "-" << setfill(' ') << "\n";

    os.precision(2);

    for (int i = 0; i < count; ++i) {
        os << *data[i] << "\n";
    }

    os << setfill('=') << setw(97) << "=" << setfill(' ') << "\n";

   
    os.unsetf(ios::showpos);
    os.unsetf(ios::showpoint);
    os.unsetf(ios::fixed);
    os.setf(ios::right, ios::adjustfield);

    os << "Всего товаров в каталоге: " << count << "\n";
}

void ToyCatalog::add(Toy* t) {
    if (!t) return;
    ensureCapacity();
    data[count++] = t;
}

Toy* ToyCatalog::findByArticle(const string& art) const {
    for (int i = 0; i < count; ++i) {
        if (data[i]->get_article() == art) return data[i];
    }
    return nullptr;
}

void ToyCatalog::sortByPrice() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - 1 - i; ++j) {
            if (data[j]->get_price() > data[j + 1]->get_price()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void ToyCatalog::sortByName() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - 1 - i; ++j) {
            if (data[j]->get_name() > data[j + 1]->get_name()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void ToyCatalog::printFindByName(const string& part) const {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (data[i]->get_name().find(part) != string::npos) {
            cout << *data[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "Товары не найдены.\n";
}