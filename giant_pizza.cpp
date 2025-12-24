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
#define all(x) begin(x), end(x)

int n, m;
vector<vector<int>> adj, radj;
vector<bool> visited;
vector<int> ts, component;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    ts.push_back(u);
}

void dfs2(int u, int id) {
    visited[u] = true;
    for (int v : radj[u]) {
        if (!visited[v]) {
            dfs2(v, id);
        }
    }
    component[u] = id;
}

void solve() {
    cin >> n >> m;

    adj.assign(2 * m, {});
    radj.assign(2 * m, {});
    ts.clear();
    component.assign(2 * m, -1);

    for (int i = 0; i < n; i++) {
        char c1, c2;
        int u, v;
        cin >> c1 >> u >> c2 >> v;
        --u, --v;
        if (c1 == '-') u += m;
        if (c2 == '-') v += m;

        int nu = (u < m) ? u + m : u - m;
        int nv = (v < m) ? v + m : v - m;

        adj[nu].push_back(v);
        radj[v].push_back(nu);
        adj[nv].push_back(u);
        radj[u].push_back(nv);
    }

    visited.assign(2 * m, false);
    for (int i = 0; i < 2 * m; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    reverse(all(ts));
    visited.assign(2 * m, false);
    int components = 0;
    for (int node : ts) {
        if (!visited[node]) {
            dfs2(node, ++components);
        }
    }

    for (int i = 0; i < m; i++) {
        if (component[i] == component[i + m]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    vector<int> result(m);
    for (int i = 0; i < m; i++) {
        result[i] = (component[i] > component[i + m]) ? 1 : -1;
    }

    for (int i = 0; i < m; i++) {
        cout << (result[i] == 1 ? '+' : '-') << " ";
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