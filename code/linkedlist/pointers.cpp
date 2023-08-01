#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18

int32_t main() {
    int a = 10;
    cout << &a << endl; // gives adress of a
    // to store address of a data type we need pointer
    // int b = &a;// invalid
    int* b = &a; // valid
    // initialize c with NULL, though we cannot initialize it with any other value
    int* c = 0; // valid
    // int* c = 968540986599999; // invalid
    cout << c << endl;

    // pointers have addresses too, int* == 4 bytes
    cout << &b << endl;
    // any way to store this address? so a pointer which stores address of another pointer
    // a pointer to pointer
    int **d = &b;
    cout << d << endl; // output same as &b

    // dereferencing of pointer b stores address of a, can we somehow use b to get value of a
    cout << *b << endl; // value of a = 10

    // using b we can also change the value of a
    *b = 11;
    cout << a << endl; // value of a = 11

    // pointer arithmetic can we change the address stored in b
    
    cout << b << endl;
    b = b + 1; // increments the address by 4 bytes
    cout << b << endl;
    // difference between int &a, int *a 
    // when you have a &something you have a reference and this is nothing more 
    // than a pointer which cannot change. In other words, it is a const pointer, so basically it’s like
    int x = 1;
    int &aa = x;
    int *bb = &x;
    cout << aa << " " << *bb;
}