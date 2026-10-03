#include"Phone.h"
#include<iostream>
#include<string>
using namespace std;

Phone::Phone() : model("0"), price(0.0) {
}

Phone::Phone(string m, double p) : model(m), price(p) {
}

Phone::Phone(const Phone& other) {
    this->model = other.model;
    this->price = other.price;
}

Phone::~Phone() {
}

string Phone::get_model() const {
    return model;
}

double Phone::get_price() const {
    return price;
}

void Phone::set_model(string m) {
    this->model = m;
}

void Phone::set_price(double p) {
    this->price = p;
}