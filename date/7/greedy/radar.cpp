#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
double area(pair<int, int> a, int d){
    return sqrt(pow(d,2) - pow((a.second),2));
}
int main(){
    int i, d = 5, count = 0;
    vector<pair<int, int> > island;
    vector<pair<double, double> > length;
    vector<pair<double, double> > res;
    cin >> i >> d;
    for(int j=0;j<i;j++){
        int x,y;
        cin >> x >> y;
        island.push_back({x,y});
    }
    for(auto a : island){
        double l = area(a, d);
        if(isnan(l)) {
            count = -1;
            break;
        }
        length.push_back({a.first-l, a.first+l});
    }
    if(count!=-1) {
        sort(length.begin(), length.end());
        res.push_back(length[0]); cout << res.back().first << " " << res.back().second << endl;
        for(int i=1;i<length.size();i++) {
            if(length[i].second > res.back().second) {
                res.push_back(length[i]);
            }
        }
        cout << res.size();
    } else cout << -1;
}