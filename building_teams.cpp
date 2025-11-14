#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define ll long long
#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

bool dfs(int u, int teamId, const vector<vector<int>>& adj, vector<int>& teams) {
    if (teams[u] != -1) return teams[u] == teamId;
    teams[u] = teamId;
    for (int v : adj[u]) {
        if (!dfs(v, 1 - teamId, adj, teams)) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> teams(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (teams[i] != -1) continue;

        // queue<int> q;
        // q.push(i);
        // teams[i] = 0;

        // while (!q.empty()) {
        //     auto u = q.front();
        //     q.pop();
        //     for (int v : adj[u]) {
        //         if (teams[v] == -1) {
        //             teams[v] = 1 - teams[u];
        //             q.push(v);
        //         } else if (teams[u] == teams[v]) {
        //             cout << "IMPOSSIBLE" << endl;
        //             return;
        //         }
        //     }
        // }

        if (!dfs(i, 1, adj, teams)) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << teams[i] + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}