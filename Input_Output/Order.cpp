#include "Order.h"
#include <iomanip>

using namespace std;

Order::Order() : items(nullptr), count(0), capacity(0) {}

Order::Order(const Order& other) : items(nullptr), count(0), capacity(0) {
    if (other.count > 0) {
        capacity = other.capacity;
        items = new OrderItem * [capacity];
        for (int i = 0; i < other.count; ++i) {
            items[i] = new OrderItem(*other.items[i]);
        }
        count = other.count;
    }
}

Order& Order::operator=(const Order& other) {
    if (this != &other) {
        clear();
        if (other.count > 0) {
            capacity = other.capacity;
            items = new OrderItem * [capacity];
            for (int i = 0; i < other.count; ++i) {
                items[i] = new OrderItem(*other.items[i]);
            }
            count = other.count;
        }
    }
    return *this;
}

Order::~Order() {
    clear();
}

int Order::getCount() const {
    return count;
}

void Order::clear() {
    for (int i = 0; i < count; ++i) delete items[i];
    delete[] items;
    items = nullptr;
    count = 0;
    capacity = 0;
}

void Order::ensureCapacity() {
    if (count < capacity) return;
    int newCap = (capacity == 0) ? 4 : capacity * 2;
    OrderItem** newItems = new OrderItem * [newCap];
    for (int i = 0; i < count; ++i) newItems[i] = items[i];
    delete[] items;
    items = newItems;
    capacity = newCap;
}

void Order::addItem(OrderItem* item) {
    if (!item) return;

    for (int i = 0; i < count; ++i) {
        if (items[i]->getArticle() == item->getArticle()) {
            items[i]->setQuantity(items[i]->getQuantity() + item->getQuantity());
            delete item;
            cout << "Количество товара в чеке обновлено!\n";
            return;
        }
    }

    ensureCapacity();
    items[count++] = item;
    cout << "Товар успешно добавлен в чек!\n";
}

bool Order::editQuantityByArticle(const string& art, int newQty) {
    if (newQty <= 0) return removeItemByArticle(art);

    for (int i = 0; i < count; ++i) {
        if (items[i]->getArticle() == art) {
            items[i]->setQuantity(newQty);
            return true;
        }
    }
    return false;
}

bool Order::removeItemByArticle(const string& art) {
    int idx = -1;
    for (int i = 0; i < count; ++i) {
        if (items[i]->getArticle() == art) {
            idx = i;
            break;
        }
    }

    if (idx < 0) return false;

    delete items[idx];
    for (int i = idx; i < count - 1; ++i) {
        items[i] = items[i + 1];
    }
    --count;
    return true;
}

void Order::printReceipt(ostream& os) const {
    if (count == 0) {
        os << "\nЧек пуст.\n";
        return;
    }

    
    os.unsetf(ios::scientific);
    os.setf(ios::fixed);
    os.precision(2);

    os << "\n==================================================================\n";
    os << "                           ЧЕК ЗАКАЗА                             \n";
    os << "==================================================================\n";
    os << setw(5) << "№"
        << setw(12) << "Артикул"
        << setw(22) << "Наименование"
        << setw(12) << "Цена (шт)"
        << setw(10) << "Кол-во"
        << setw(15) << "Сумма" << "\n";
    os << "------------------------------------------------------------------\n";

    double totalSum = 0;
    for (int i = 0; i < count; ++i) {
        items[i]->printItem(i + 1, os);
        totalSum += items[i]->getTotalPrice();
    }

    os << "------------------------------------------------------------------\n";
    os << "ИТОГО К ОПЛАТЕ: " << totalSum << " руб.\n";
    os << "==================================================================\n";
}