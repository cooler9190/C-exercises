#include <iostream>
#include <string>

int main() {
    int decimal = 10;
    int binary = 0b1010;
    int octal = 012;
    int hexadecimal = 0xA;

    signed x = 10;
    signed int s = 10;
    unsigned int u = 10u;
    short int si = 10;
    signed short ss = 10;
    signed short int ssi = 10;
    unsigned short int us = 10;
    long l = 10l;
    long int li = 10l;
    signed long sl = 10l;
    signed long int sli = 10l;
    unsigned long ul = 10ul;
    unsigned long int uli = 10ul;
    long long ll = 10ll;
    long long int lli = 10ll;
    signed long long sll = 10ll;
    signed long long int slli = 10ll;
    unsigned long long ull = 10ull;
    unsigned long long int ulli = 10ull;

    double d = 10.5;
    float f = 10.5f;
    long double ld = 10.5l;

    char c = 'c';
    signed char sc = 'c';
    unsigned char uc = 'c';
    wchar_t wideChar = 'c';

    std::string s = "Hello, CodeAcademy!";

    bool setTrue = true;
    bool setFalse = false;

    return 0;
}