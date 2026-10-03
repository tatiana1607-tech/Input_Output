    #include "Order.h"
    #include <iomanip>

    void Order::ensureCapacity() {
        if (count < capacity) return;
        capacity = (capacity == 0) ? 4 : capacity * 2;
        OrderItem** temp = new OrderItem * [capacity];
        for (int i = 0; i < count; ++i) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
    }

    Order::Order() : items(nullptr), count(0), capacity(0) {}

    Order::Order(const Order& other) : items(nullptr), count(0), capacity(0) {
        *this = other;
    }

    Order& Order::operator=(const Order& other) {
        if (this == &other) return *this;

        clear();
        capacity = other.capacity;
        count = other.count;
        items = new OrderItem * [capacity];

        for (int i = 0; i < count; ++i) {
            items[i] = new OrderItem(*other.items[i]);
        }
        return *this;
    }

    Order::~Order() {
        clear();
    }

    void Order::addItem(OrderItem* item) {
        if (!item) return;
        ensureCapacity();
        items[count++] = item;
    }

    double Order::getFinalCost() const {
        double total = 0.0;
        for (int i = 0; i < count; ++i) {
            total += items[i]->getTotalPrice();
        }
        return total;
    }

    void Order::printReceipt() const {
        if (count == 0) {
            cout << "\n×åê ïóñò. Äîáàâüòå òîâàðû èç êàòàëîãà.\n";
            return;
        }

        cout << "\n==================== ÒÎÂÀÐÍÛÉ ×ÅÊ ====================\n";
        cout << left << setw(12) << "Àðòèêóë"
            << setw(25) << "Íàçâàíèå"
            << setw(10) << "Öåíà"
            << setw(8) << "Êîë-âî"
            << setw(10) << "Ñóììà" << "\n";
        cout << "-----------------------------------------------------\n";

        for (int i = 0; i < count; ++i) {
            items[i]->print(cout);
        }
        cout << "-----------------------------------------------------\n";
        cout << "ÈÒÎÃÎ Ê ÎÏËÀÒÅ: " << getFinalCost() << " ðóá.\n";
        cout << "=====================================================\n";
    }

    void Order::clear() {
        for (int i = 0; i < count; ++i) {
            delete items[i];
        }
        delete[] items;
        items = nullptr;
        count = 0;
        capacity = 0;
    }