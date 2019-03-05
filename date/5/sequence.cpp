#include<iostream>
#include<vector>
#include<utility>
using namespace std;
bool sort_seq(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first || (a.first==b.first && a.second > b.second);
}
int main(){
	vector<pair<int,int> > seq;
	vector<pair<int,int> > res;
    seq.push_back(make_pair(10,20));
    seq.push_back(make_pair(12,25));
    seq.push_back(make_pair(20,30));
    seq.push_back(make_pair(40,60));
    seq.push_back(make_pair(10,30));
    sort(seq.begin(), seq.end(), sort_seq);
    for(i=0;i<seq.size()-1;i++){
    }
    for(int i=0;i<seq.size();i++){
        cout << seq[i].first << " " << seq[i].second << endl;
    }
}