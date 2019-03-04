#include<iostream>
#include<vector>
using namespace std;
int main(){
    int q,n;
    cin >> n >> q;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for(int i=0;i<q;i++){
        int l,r,c,count=0;
        cin >> l >> r >> c;
        for(int j=l-1;j<r;j++){
            if(vec[j]==c){
                count = count + 1;
            }
        }
        cout << count << endl;
    }
}