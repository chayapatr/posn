#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool dfs_num[10005];
vii AdjList[10005];

void dfs(int u) {
  dfs_num[u] = true; // mark this vertex as visited

  cout << u << " ";

  for (int i = 0; i < AdjList[u].size(); ++i) {
    ii v = AdjList[u][i]; // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == false) // check to avoid cycle
      dfs(v.first); // recursively visits unvisited neighbors of vertex u
  }
}

int main() {

  /*
  input:
  7
  0 1 1
  0 3 1
  0 2 1
  1 3 1
  1 4 1
  3 4 1
  2 4 1

  output:
  0 1 3 4 2
  */
  int M, u, v, w;
  cin >> M; // M is the number of edges
  for(int i = 0; i < M; ++i) {
    cin >> u >> v >> w;
    AdjList[u].push_back(make_pair(v, w));
  }
  dfs(0); // start from vertex 0
  return 0;
}
