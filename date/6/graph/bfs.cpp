#include<iostream>
#include<queue>
using namespace std;
typedef vector<pair<int,int> > vii;
int main(){
    vii adj[5];
    bool visited[5] = {false};
    int level[5] = {0};
    int num;
    queue <pair<int, int> > Q;
    cin >> num;
    for(int i=0;i<num;i++){
        int n,v,w;
        cin >> n >> v >> w;
        adj[n].push_back(make_pair(v,w));
    }
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        int u = Q.front().first;
        int v = Q.front().second;
        Q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(int i=0;i<adj[u].size();i++) Q.push(adj[u][i]);
        cout << u << " ";
    }
    //for(int i=0;i<5;i++) cout << i << " : level = " << level[i] << endl;
}