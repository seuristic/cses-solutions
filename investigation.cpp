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

const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const int M = 1e9 + 7;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<ll> dist;
vector<int> num, minf, maxf;

void solve() {
    cin >> n >> m;

    adj.assign(n, {});
    visited.assign(n, false);
    dist.assign(n, LINF);
    num.assign(n, 0);
    minf.assign(n, 0);
    maxf.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;

    dist[0] = 0;
    num[0] = 1;
    q.push({dist[0], 0});
    visited[0] = true;

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (dist[u] != d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] == LINF) continue;
            ll newDist = d + w;
            if (newDist == dist[v]) {
                num[v] = (num[v] + num[u]) % M;
                minf[v] = min(minf[v], minf[u] + 1);
                maxf[v] = max(maxf[v], maxf[u] + 1);
            } else if (newDist < dist[v]) {
                num[v] = num[u];
                minf[v] = minf[u] + 1;
                maxf[v] = maxf[u] + 1;
                dist[v] = newDist;
                q.push({dist[v], v});
            }
        }
    }

    cout << dist.back() << ' ';
    cout << num.back() << ' ';
    cout << minf.back() << ' ';
    cout << maxf.back() << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}