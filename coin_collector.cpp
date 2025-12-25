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
vector<vector<int>> adj, radj, adj_scc;
vector<int> coin, order, comp, ts;
vector<bool> visited;
vector<ll> dp, coin_scc;

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
    comp[u] = id;
    for (int v : radj[u]) {
        if (comp[v] == -1) {
            dfs2(v, id);
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    radj.assign(n, {});
    coin.assign(n, 0);
    order.clear();
    visited.assign(n, false);
    comp.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    int components = 0;
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) {
            dfs2(u, components++);
        }
    }

    adj_scc.assign(components, {});
    coin_scc.assign(components, 0);
    for (int u = 0; u < n; ++u) {
        coin_scc[comp[u]] += coin[u];
        for (int v : adj[u]) {
            if (comp[u] != comp[v]) {
                adj_scc[comp[u]].push_back(comp[v]);
            }
        }
    }

    dp.assign(components, 0);
    ll ans = 0;
    for (int u = 0; u < components; ++u) {
        dp[u] = max(dp[u], coin_scc[u]);
        for (int v : adj_scc[u]) {
            dp[v] = max(dp[v], dp[u] + coin_scc[v]);
        }
        ans = max(ans, dp[u]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}