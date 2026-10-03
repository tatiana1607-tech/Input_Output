#pragma once
#include "Purchase.h"
#include "Sale.h"

class IO {
public:
    static void savePurchase(const Purchase& p);
    static void saveSale(const Sale& s);

    static void printPurchases();
    static void printSales();
};
