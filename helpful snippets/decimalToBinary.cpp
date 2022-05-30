#include <iostream>
using namespace std;

int decimalToBinary(int decimal) {
    long long int binary = 0, product = 1, remainder;
    while (decimal != 0) {
        remainder = decimal % 2;
        binary += remainder * product;
        decimal /= 2;
        product *= 10;
    }
    return binary;
}

int main(){
    int decimal;
    cout<<"Enter decimal number : "; cin>>decimal;
    cout<<"The deciamal number "<<decimal<<" in binary is : "<<decimalToBinary(decimal);
    return 0;
}