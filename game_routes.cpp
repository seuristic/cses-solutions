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

const ll M = 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<ll> paths;

ll dfs(int u) {
    if (u == n - 1) return paths[n - 1] = 1;
    if (paths[u] != -1) return paths[u];

    ll ans = 0;
    for (int v : adj[u]) {
        ans = (ans + dfs(v)) % M;
    }

    return paths[u] = ans;
}

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    paths.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }

    cout << dfs(0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}