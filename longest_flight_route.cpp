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

const int NEG_INF = INT_MIN;

int n, m;
vector<vector<int>> adj, radj;
vector<int> dist, parent, ts, path;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    ts.push_back(u);
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    radj.assign(n, {});
    dist.assign(n, NEG_INF);
    parent.assign(n, -1);
    visited.assign(n, 0);
    ts.clear();
    path.clear();

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    dfs(0);
    reverse(all(ts));

    dist[0] = 1;
    for (int v : ts) {
        for (int u : radj[v]) {
            if (dist[u] == NEG_INF) continue;
            if (dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dist[n - 1] == NEG_INF) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int curr = n - 1;
    path.push_back(curr);
    while (curr != 0) {
        curr = parent[curr];
        path.push_back(curr);
    }

    reverse(all(path));

    cout << size(path) << endl;
    for (int p : path) {
        cout << p + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}