#include <iostream>
#include <cstring>
#include <cstdint>
#include "output.h"


using namespace std;



unsigned changeBit(unsigned x, int k, int op) {
    unsigned mask = 1u;
    mask = mask << k-1;

    if (op == 1)
        x |= mask;

    if (op == 2)
        x &= ~mask;

    if (op == 3)
        x ^= mask;

    return x;
}

uint64_t changeDoubleBit(uint64_t x, int k, int op) {
    uint64_t mask = 1;
    mask = mask << k;

    if (op == 1)
        x |= mask;

    if (op == 2)
        x &= ~mask;

    if (op == 3)
        x ^= mask;

    return x;
}

unsigned swapBits(unsigned x) {
    unsigned b3 = (x >> 3) & 1u;
    unsigned b7 = (x >> 7) & 1u;

    if (b3 != b7)
        x ^= (1u << 3) | (1u << 7);

    return x;
}

int main() {
    cout << "1. Размеры типов данных" << endl;
    cout << "bool: " << sizeof(bool) << " байт" << endl;
    cout << "char: " << sizeof(char) << " байт" << endl;
    cout << "short int: " << sizeof(short int) << " байт" << endl;
    cout << "int: " << sizeof(int) << " байт" << endl;
    cout << "long int: " << sizeof(long int) << " байт" << endl;
    cout << "long long: " << sizeof(long long) << " байт" << endl;
    cout << "float: " << sizeof(float) << " байт" << endl;
    cout << "double: " << sizeof(double) << " байт" << endl;
    cout << "long double: " << sizeof(long double) << " байт" << endl;

    cout << endl << "2. Двоичное представление целых чисел" << endl;

    int a = 42;
    int b = -3;
    int c = 0;

    cout << "Число 42: ";
    printIntBits(a);

    cout << "Число -3: ";
    printIntBits(b);

    cout << "Число 0: ";
    printIntBits(c);

    cout << endl << "3. Двоичное представление float" << endl;

    float f1 = 3.14f;
    float f2 = -2.5f;
    float f3 = 0.0f;
    float f4 = 1.0e-40f;

    uint32_t infF = 0x7F800000u;
    float f5;
    memcpy(&f5, &infF, sizeof(f5));

    printFloatBits(f1);
    printFloatBits(f2);
    printFloatBits(f3);
    printFloatBits(f4);
    printFloatBits(f5);

    cout << "4. Двоичное представление double" << endl;

    double d1 = 3.14;
    double d2 = -2.5;
    double d3 = 0.0;
    double d4 = 1.0e-310;

    uint64_t infD = 0x7FF0000000000000;
    double d5;
    memcpy(&d5, &infD, sizeof(d5));

    printDoubleBits(d1);
    printDoubleBits(d2);
    printDoubleBits(d3);
    printDoubleBits(d4);
    printDoubleBits(d5);

    cout << "5. Изменение отдельных битов целого числа" << endl;

    unsigned x = 42;

    cout << "Исходное число: ";
    printIntBits(x);

    x = changeBit(x, 1, 1);
    cout << "Установка бита 1: ";
    printIntBits(x);

    x = changeBit(x, 1, 2);
    cout << "Сброс бита 1: ";
    printIntBits(x);

    x = changeBit(x, 3, 3);
    cout << "Инверсия бита 3: ";
    printIntBits(x);

    cout << endl << "6. Изменение битов числа float" << endl;

    uint32_t fb;
    memcpy(&fb, &f1, sizeof(fb));

    cout << "Исходное представление: ";
    printIntBits(static_cast<int>(fb));

    fb = changeBit(fb, 1, 3);
    memcpy(&f1, &fb, sizeof(f1));

    printFloatBits(f1);

    cout << "7. Изменение битов числа double" << endl;

    uint64_t db;
    memcpy(&db, &d1, sizeof(db));

    db = changeDoubleBit(db, 0, 3);
    memcpy(&d1, &db, sizeof(d1));

    printDoubleBits(d1);

    cout << "8. Индивидуальное задание: обмен битов 3 и 7" << endl;

    unsigned n = 42;

    cout << "До обмена: ";
    printIntBits(n);

    n = swapBits(n);

    cout << "После обмена: ";
    printIntBits(n);

    return 0;
}
