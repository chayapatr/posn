#include<iostream>
#include<vector>
using namespace std;
int main() {
    long long int num, sol=0, multiply=1, minus=0;
    bool c = false;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        char type;
        long long int amount;
        cin >> type >> amount;
        if(type=='+') sol+=amount;
        else if(type=='-') minus+=amount;
        else if(type=='x') (amount != 0) ? multiply *= amount : c = true;
    }
    sol*=multiply;
    if(!c) sol-=minus;
    cout << sol;
}