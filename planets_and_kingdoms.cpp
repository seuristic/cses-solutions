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
vector<int> order, component;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
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

    adj.assign(n, {});
    radj.assign(n, {});
    order.clear();
    component.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited.assign(n, false);
    int components = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!visited[order[i]]) {
            components++;
            dfs2(order[i], components);
        }
    }

    cout << components << endl;
    for (int i = 0; i < n; i++) {
        cout << component[i] << " ";
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