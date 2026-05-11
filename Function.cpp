#include <iostream>
#include <cstdio>
#include "Header.h"

void plus(product *a, product b) {
    a->bills += b.bills;
    a->coins += b.coins;
}

void multiply(product *a, short int x) {
    a->bills *= x;
    a->coins *= x;
}

void rounding(product *a) {
    if (a->coins >= 100) {
        a->bills += a->coins / 100;
        a->coins = a->coins % 100;
    }
}

void stonks(product *a) {
    a->coins = ((a->coins + 6) / 10) * 10;
}

void output(product a) {
    rounding(&a);
    std::cout << "Ціна продукту: " << a.bills << " Гривень " << a.coins << " Копійок" << std::endl;
}

void totalcalculate(const char* path) {
    product total;
    total.bills = 0;
    total.coins = 0;

    FILE* list = fopen(path, "r");
    if (list == nullptr) return;

    product temp;
    short int x;

    while (fscanf(list, "%*s %d %hi %hi", &temp.bills, &temp.coins, &x) == 3) {
        multiply(&temp, x);
        plus(&total, temp);
    }

    rounding(&total);
    std::cout << "Сума чеку: " << total.bills << " Гривень " << total.coins << " Копійок" << std::endl;
    stonks(&total);
    rounding(&total); 
    std::cout << "Сума до оплати з заокругленням: " << total.bills << " Гривень " << total.coins << " Копійок" << std::endl;
    fclose(list);
}
