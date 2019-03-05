#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string input;
    stack<int> s;
    cin >> input;
    for (int i=0;input[i]!='\0';i++) {
        if(input[i]>=48 && input[i]<=57) s.push(input[i]-'0');
        if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            char op = input[i];
            s.push(op == '+' ? a+b : op == '-' ? a-b : op == '*' ? a*b : a/b);
        }
    }
    int ans = s.top(); s.pop();
    s.empty()? cout << ans : cout << "error";
    return 0;
}