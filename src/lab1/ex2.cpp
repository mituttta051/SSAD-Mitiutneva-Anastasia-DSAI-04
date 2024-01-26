#include <iostream>
using namespace std;

void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main () {
    int n1 = 1;
    int n2 = 2;
    cout << n1 << " " << n2 << endl;
    int* ptr1 = &n1;
    int* ptr2 = &n2;

    int& ref1 = n1;
    int&ref2 = n2;

    swapByPointer(ptr1, ptr2);
    cout << n1 << " " << n2 << endl;

    swapByReference(ref1, ref2);
    cout << n1 << " " << n2 << endl;
    
    return 0;
}