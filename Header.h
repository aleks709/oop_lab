#pragma once

struct product {
    int bills;
    short int coins;
};

void plus(product *a, product b);
void multiply(product *a, short int x);
void rounding(product *a);
void output(product a);
void totalcalculate(const char* path);
void stonks(product *a);