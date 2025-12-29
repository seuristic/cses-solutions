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

int n;
vector<vector<int>> adj;
vector<int> dist;

void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);
        dist[u] += 1 + dist[v];
    }
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n, {});
    dist.assign(n, 0);

    for (int i = 1; i < n; ++i) {
        int node;
        cin >> node;
        --node;
        adj[node].push_back(i);
    }

    dfs(0);

    for (int i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
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