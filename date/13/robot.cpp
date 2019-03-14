#include <iostream>
#include <queue>
using namespace std;
char keep[2005][2005];
int dp[2005][2005];
bool qcheck[2005][2005];
queue<pair<int, int>> finalcheck;
int ver[] = {-1, 0, 1, 0};
int hor[] = {0, 1, 0, -1};
queue<tuple<int, int, int>> Q;
int main() {
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M, i, j, a, w, x, y, point, count = 0, sum = 0, c, d, num = 1;
    cin >> N >> M;
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
        cin >> keep[i][j];
        if (keep[i][j] == 'X') {
            Q.push(make_tuple(0, i, j));
            num++;
        }
        if (keep[i][j] == 'A') finalcheck.push(make_pair(i, j));
    }
    while (!Q.empty()){
        w = get<0>(Q.front());
        x = get<1>(Q.front());
        y = get<2>(Q.front());
        Q.pop();
        dp[x][y] = (keep[x][y] == 'A') ? (dp[x][y] == 0) ? w : (min(dp[x][y], w)) :  w;
        for (i = 0; i < 4; ++i) {
            point = keep[x + hor[i]][y + ver[i]];
            if ((point == 'E' || point == 'A' || point == 'X')
            && x + hor[i] < N && x + hor[i] >= 0
            && y + ver[i] < M && y + ver[i] >= 0
            && qcheck[x + hor[i]][y + ver[i]] != true) {
                Q.push(make_tuple(w + 1, x + hor[i], y + ver[i]));
                qcheck[x + hor[i]][y + ver[i]] = true;
            }
        }
    }
    // for(i=1;i<=N;i++){
    //     for(j=1;j<=M;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (!finalcheck.empty()) {
        c = finalcheck.front().first;
        d = finalcheck.front().second;
        finalcheck.pop();
        if (dp[c][d] != 0) {
            count++;
            sum = sum + (2 * dp[c][d]);
        }
    }
    cout << count << " " << sum;
}