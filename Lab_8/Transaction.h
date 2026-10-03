#pragma once
#include <iostream>
using namespace std;

template <class T>
class Transaction {
    T* currentState;
    T* prevState;

public:
   
    Transaction() : prevState(nullptr), currentState(new T) {}

    
    Transaction(const T& initialState) : prevState(nullptr), currentState(new T(initialState)) {}

    Transaction(const Transaction& obj)
        : currentState(new T(*(obj.currentState))), prevState(nullptr) {
    }

    ~Transaction() {
        delete currentState;
        delete prevState;
    }

    Transaction& operator=(const Transaction& obj) {
        if (this != &obj) {
            delete currentState;
            currentState = new T(*(obj.currentState));
        }
        return *this;
    }

    T* operator->() { return currentState; }
    T& operator*() { return *currentState; }

   
    bool beginTransaction(const T& newState) {
        delete prevState;
        prevState = new T(*currentState);  
        *currentState = newState;          
        return true;
    }

    void commit() {
        delete prevState;
        prevState = nullptr;
    }

    void rollback() {
        if (prevState) {
            delete currentState;
            currentState = prevState;
            prevState = nullptr;
        }
    }

    T getState() const { return *currentState; }
};