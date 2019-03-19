#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
    map<string, int> keep;
    string input, temp, maxword;
    int num, max=0;
    cin >> num >> input;
    for(int i=0;i<=input.length()-num;i++){
        temp = input.substr(i, num); keep[temp]++;
        if(keep[temp]>=max) {
            max = keep[temp]; maxword=temp;
        }
    }
    cout << maxword;
}