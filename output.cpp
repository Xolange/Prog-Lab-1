#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;

void printIntBits(const int& x, int w) {
    unsigned u = static_cast<unsigned>(x);

    for (int i = w - 1; i >= 0; --i) {
        if (i == w - 1) cout << "[знак]";
        cout << ((u >> i) & 1u);
        if ((w - 1 - i) % 8 == 7) cout << " ";
    }
    cout << endl;
}

void printFloatBits(const float& f) {
    uint32_t b;
    memcpy(&b, &f, sizeof(b));

    int s = (b >> 31) & 1u;
    int e = (b >> 23) & 0xFFu;
    uint32_t m = b & 0x7FFFFFu;

    cout << "Число float: " << f << endl;
    cout << "[знак] " << s << endl;

    cout << "[порядок] ";
    for (int i = 30; i >= 23; --i)
        cout << ((b >> i) & 1u);

    cout << endl << "[мантисса] ";
    for (int i = 22; i >= 0; --i)
        cout << ((b >> i) & 1u);

    cout << endl;
    cout << "Поле порядка: " << e << endl;
    cout << "Поле мантиссы: " << m << endl;
    cout << endl;
}

void printDoubleBits(const double& d) {
    uint64_t b;
    memcpy(&b, &d, sizeof(b));

    int s = (b >> 63) & 1u;
    uint64_t e = (b >> 52) & 0x7FFu;
    uint64_t m = b & 0xFFFFFFFFFFFFFu;

    cout << "Число double: " << d << endl;
    cout << "[знак] " << s << endl;

    cout << "[порядок] ";
    for (int i = 62; i >= 52; --i)
        cout << ((b >> i) & 1u);

    cout << endl << "[мантисса] ";
    for (int i = 51; i >= 0; --i)
        cout << ((b >> i) & 1u);

    cout << endl;
    cout << "Поле порядка: " << e << endl;
    cout << "Поле мантиссы: " << m << endl;
    cout << endl;
}
