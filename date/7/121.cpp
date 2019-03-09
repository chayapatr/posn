#include<iostream>

#include<queue>

#include<vector>

using namespace std;
vector < int > Adjlist[10000];
int qcheck[1000];
priority_queue < pair < int, int > > PQ;
int main() {
    int N, M, X, Y, u, v, i, j;
    cin >> N;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        Adjlist[N].push_back(M);
    }
    while (true) {
        cin >> X >> Y;
        memset(qcheck, 0, sizeof(qcheck));
        while (!PQ.empty()) PQ.pop();
        PQ.push(make_pair(0, X));
        while (!PQ.empty()) {
            u = -PQ.top().first;
            v = PQ.top().second;
            PQ.pop();
            cout << " u = " << u << " v = " << v << endl;
            if (v == Y) {
                cout << u;
                break;
            }
            if (qcheck[v] == true) continue;
            qcheck[v] = true;
            for (j = 0; j < Adjlist[v].size(); j++)
            PQ.push(make_pair(-u - 1, Adjlist[v][j]));
        }
    }
}