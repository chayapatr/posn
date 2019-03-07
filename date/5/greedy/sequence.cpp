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
    int count = 1;
    seq.push_back(make_pair(10,30));
    seq.push_back(make_pair(12,25));
    seq.push_back(make_pair(20,30));
    seq.push_back(make_pair(30,40));
    seq.push_back(make_pair(30,60));
    seq.push_back(make_pair(55,70));
    seq.push_back(make_pair(35,40));
    sort(seq.begin(), seq.end(), sort_seq);
    res.push_back(seq[0]); cout << res[0].first << " " << res[0].second << endl;
    for(int i=1;i<seq.size();i++){
        if(seq[i].first==seq[i-1].first) continue;
        if(seq[i].first<=res.back().second && seq[i].second>res.back().second) {
            res.push_back(seq[i]);
            count++;
            cout << seq[i].first << " " << seq[i].second << endl;
        }
    }
    cout << count;
}