#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Status {
    T* ptr;
    int counter;
};

template <typename T>
class SmartPointer {
    Status<T>* smartPtr;

public:
    SmartPointer(T* ptr = nullptr) {
        if (!ptr) smartPtr = nullptr;
        else {
            smartPtr = new Status<T>();
            smartPtr->ptr = ptr;
            smartPtr->counter = 1;
        }
    }

    SmartPointer(const SmartPointer& obj) {
        smartPtr = obj.smartPtr;
        if (smartPtr) smartPtr->counter++;
    }

    ~SmartPointer() {
        if (smartPtr) {
            smartPtr->counter--;
            if (smartPtr->counter == 0) {
                delete smartPtr->ptr;
                delete smartPtr;
            }
        }
    }

    SmartPointer& operator=(const SmartPointer& obj) {
        if (this == &obj) return *this;

        if (smartPtr) {
            smartPtr->counter--;
            if (smartPtr->counter == 0) {
                delete smartPtr->ptr;
                delete smartPtr;
            }
        }

        smartPtr = obj.smartPtr;
        if (smartPtr) smartPtr->counter++;

        return *this;
    }

    T* operator->() const {
        return smartPtr ? smartPtr->ptr : nullptr;
    }

    T& operator*() const {
        return *(smartPtr->ptr); 
    }
};
