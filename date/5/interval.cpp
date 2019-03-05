#include<iostream>
#include<vector>
#include<utility>
using namespace std;
bool sort_by_sec(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
int main(){
    int count=1;
    vector<pair<int, int> > work;
    vector<pair<int, int> > result;
    work.push_back(make_pair(10,20));
    work.push_back(make_pair(12,25));
    work.push_back(make_pair(20,30));
    work.push_back(make_pair(40,60));
    sort(work.begin(), work.end(), sort_by_sec);
    result.push_back(work[0]);
    for(int i=0;i<work.size()-1;i++){
        pair<int, int> prev = result[0];
        if(prev.second<= work[i+1].first) {
            result.push_back(work[i+1]);
            prev = work[i+1];
            count++;
        }
    }
    cout << count << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i].first << " " << result[i].second << endl;
    }
}