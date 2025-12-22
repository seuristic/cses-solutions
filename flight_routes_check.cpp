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

void dfs(int u, bool reversed) {
    visited[u] = true;
    auto& g = reversed ? radj : adj;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, reversed);
        }
    }
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    radj.assign(n, {});
    visited.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    dfs(0, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << ' ' << i + 1 << endl;
            return;
        }
    }

    visited.assign(n, false);
    dfs(0, true);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i + 1 << ' ' << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}