#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define endl '\n'
#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

// APPROACH 1: dfs
// int n, m;
// vector<vector<int>> adj;
// vector<int> visited, topo;

// bool dfs(int u) {
//     visited[u] = 1;
//     for (int v : adj[u]) {
//         if (visited[v] == 0) {
//             if (!dfs(v)) return false;
//         } else if (visited[v] == 1) {
//             return false;
//         }
//     }
//     visited[u] = 2;
//     topo.push_back(u);
//     return true;
// }

// void solve() {
//     cin >> n >> m;

//     adj.assign(n, {});
//     visited.assign(n, 0);

//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         cin >> u >> v;
//         --u, --v;
//         adj[u].push_back(v);
//     }

//     for (int u = 0; u < n; ++u) {
//         if (visited[u] == 0) {
//             if (!dfs(u)) {
//                 cout << "IMPOSSIBLE" << endl;
//                 return;
//             }
//         }
//     }

//     reverse(all(topo));
//     for (int& node : topo) {
//         cout << node + 1 << ' ';
//     }
//     cout << endl;
// }

// APPROACH 2: kahn's algorithm
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++indeg[v];
        adj[u].push_back(v);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (size(topo) < n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int& node : topo) {
            cout << node + 1 << ' ';
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}