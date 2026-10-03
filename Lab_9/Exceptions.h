#pragma once
#include <string>
#include <iostream>
using namespace std;

class MyException {
protected:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    virtual const char* what() const { return message.c_str(); }
    virtual ~MyException() {}
};


class CustomServiceException : public MyException {
public:
    CustomServiceException(const string& msg) : MyException(msg) {}
};

class InvalidInputException : public MyException {
public:
    InvalidInputException() : MyException("Некорректные входные данные!") {}
    InvalidInputException(const string& msg) : MyException(msg) {}
};

class NoWorkersException : public MyException {
public:
    NoWorkersException() : MyException("В команде нет работников! Обслуживание невозможно.") {}
};

class NoManagerException : public MyException {
public:
    NoManagerException() : MyException("В команде нет менеджера!") {}
};

class MemoryAllocationException : public MyException {
public:
    MemoryAllocationException() : MyException("Ошибка выделения памяти!") {}
};

class BuildingLimitException : public MyException {
public:
    BuildingLimitException() : MyException("Достигнут лимит зданий на территории (максимум 10)!") {}
};