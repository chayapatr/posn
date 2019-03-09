#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
priority_queue<ii> PQ;
bool visited[5];
int main(){
    vii adj[5];
    int total=0;
    adj[0].push_back(make_pair(4,1));
    adj[0].push_back(make_pair(6,2));
    adj[0].push_back(make_pair(5,3));
    adj[1].push_back(make_pair(3,2));
    adj[3].push_back(make_pair(7,4));
    PQ.push(make_pair(0,0));
    while(!PQ.empty()){
        int u = -PQ.top().first;
        int v = PQ.top().second;
        PQ.pop();
        if(visited[v]) continue;
        cout << v << " " << u << endl;
        for(int i=0;i<adj[v].size();i++)
        PQ.push(make_pair(-adj[v][i].first, adj[v][i].second));
        total+=u;
        visited[v] = true;
    }
    cout << total;
    return 0;
}