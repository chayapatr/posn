// #include<iostream>
// #include<string>
// #include<queue>
// using namespace std;
// bool person[2010][2010] = {false};
// int main(){
//     int m, n, count=0;
//     cin >> m >> n;
//     for(int i=0;i<m;i++) {
//         string input; cin >> input;
//         for(int j=0;j<n;j++)
//         if(input[j]=='1') person[i][j] = true;
//     }
//     for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
//         if(i==0) {
//             if(j == 0 && person[i][j]) count++;
//             else if(person[i][j] && !person[i][j-1]) count++;
//         } else {
//             if (j ==0) {
//                 if (person[i][j] && !person[i-1][0] && !person[i-1][1]) count++;
//             } else {
//                 if(person[i][j] && !person[i][j-1]
//                 && !person[i-1][j-1] && !person[i-1][j]
//                 && !person[i-1][j+1]) count++;
//             }
//         }
//     }
//     cout << count;
// }

#include<iostream>
#include<queue>
#include<string>
using namespace std;
bool person[2005][2005];
vector<pair<int, int>> c;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    int m, n, count=0;
    cin >> m >> n;
    for(int i=0;i<m;i++) {
        string input; cin >> input;
        for(int j=0;j<n;j++)
        if(input[j]=='1') {
            c.push_back({i+1, j+1});
            Q.push({i+1, j+1});
            person[i+1][j+1] = true;
        }
    }
    while(!Q.empty()) {
        bool check = true;
        queue<pair<int, int>> q;
        // for(int i=1;i<m;++i) {
        //     for(int j=1;j<n;++j) if(person[i][j]) {
        //         check = false; q.push({i,j});
        //         // cout << "push" << i << " " << j << endl;
        //         count++; break;
        //     } if(!check) break;
        // }
        for(int i=0;i<c.size();i++){
            if(person[c[i].first][c[i].second]) {
                //cout << "push" <<c[i].first << " " << c[i].second << endl;
                q.push({c[i].first, c[i].second});
                count++;check = false;
                break;
            }
        }
        if(check) break;
        while(!q.empty()){
            int i = q.front().first; int j = q.front().second; q.pop();
            // cout << i << " " << j << endl;
            person[i][j] = false;
            if(person[i-1][j-1]) q.push({i-1,j-1});
            if(person[i-1][j]) q.push({i-1,j});
            if(person[i-1][j+1]) q.push({i-1,j+1});
            if(person[i][j-1]) q.push({i,j-1});
            if(person[i][j+1]) q.push({i,j+1});
            if(person[i+1][j-1]) q.push({i+1,j-1});
            if(person[i+1][j]) q.push({i+1,j});
            if(person[i+1][j+1]) q.push({i+1,j+1});
        }
    }
    cout << count;
}