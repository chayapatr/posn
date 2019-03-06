#include<iostream>
using namespace std;

long long fac(long long i) {
    return i==0 ? 1 : i * fac(i-1);
}

int main(){
    long long input;
    cin >> input;
    cout << fac(input);
}