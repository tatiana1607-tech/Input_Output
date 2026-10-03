#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
class Catalog {
private:
    T* items;      
    int size;      
    int capacity;  

   
    void resize() {
        int newCapacity = capacity * 2;  
        T* newItems = new T[newCapacity]; 

        
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }

        delete[] items;     
        items = newItems;   
        capacity = newCapacity; 

        cout << "Массив расширен! Новая вместимость: " << capacity << endl;
    }

public:
   
    Catalog() {
        capacity = 10;      
        size = 0;          
        items = new T[capacity];
        cout << "Создан каталог (вместимость: " << capacity << ")" << endl;
    }

   
    Catalog(int initialCapacity) {
        capacity = initialCapacity;
        size = 0;
        items = new T[capacity];
        cout << "Создан каталог (вместимость: " << capacity << ")" << endl;
    }

    
    Catalog(const Catalog& other) {
     
        this->capacity = other.capacity;
        this->size = other.size;
        this->items = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->items[i] = other.items[i];
        }

        cout << "Создана копия каталога" << endl;
    }
   
    ~Catalog() {
        delete[] items;  
        cout << "Каталог удален" << endl;
    }

   
    Catalog& operator=(const Catalog& other) {
        if (this != &other) { 
            delete[] items;

            
            this->capacity = other.capacity;
            this->size = other.size;

            
            this->items = new T[capacity];

       
            for (int i = 0; i < size; i++) {
                this->items[i] = other.items[i];
            }
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне границ!" << endl;
            exit(1);
        }
        return items[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне границ!" << endl;
            exit(1);
        }
        return items[index];
    }

    
    void addItem(const T& item) {
        if (size >= capacity) {
            resize();  
        }
        items[size] = item;  
        size++;               
        cout << "Элемент добавлен. Всего элементов: " << size << endl;
    }

    
    int getSize() const {
        return size;
    }

    
    int getCapacity() const {
        return capacity;
    }

    
    T* getItems() const {
        return items;
    }

   
    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        delete[] items;
        capacity = 10;
        size = 0;
        items = new T[capacity];
        cout << "Каталог очищен" << endl;
    }

   
    double getTotalSum() const {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += items[i].getSum();  
        }
        return sum;
    }

   
    void printTable() const {
        if (size == 0) {
            cout << "\nКаталог пуст!" << endl;
            return;
        }

        cout << "\n" << string(80, '=') << endl;

        for (int i = 0; i < size; i++) {
            items[i].printRow(); 
            cout << endl;
        }

        cout << string(80, '=') << endl;
        cout << "ИТОГОВАЯ СУММА: " << fixed << setprecision(2) << getTotalSum() << " руб." << endl;
        cout << string(80, '=') << endl;
    }

   
    void saveToFile(const string& filename) const {
        if (size == 0) {
            cout << "Каталог пуст, нечего сохранять!" << endl;
            return;
        }

        ofstream file(filename);

        if (!file.is_open()) {
            cout << "Ошибка: не удалось открыть файл " << filename << endl;
            return;
        }

        file << string(80, '=') << endl;
        file << "ОТЧЕТ ПО ПРОДАЖАМ" << endl;
        file << string(80, '=') << endl;

        for (int i = 0; i < size; i++) {
            items[i].printRowToFile(file);  
            file << endl;
        }

        file << string(80, '=') << endl;
        file << "ИТОГОВАЯ СУММА: " << fixed << setprecision(2) << getTotalSum() << " руб." << endl;
        file << string(80, '=') << endl;

        file.close();
        cout << "Данные сохранены в файл: " << filename << endl;
    }
};

