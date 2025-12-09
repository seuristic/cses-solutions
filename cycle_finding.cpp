#include <algorithm>
#include <bitset>
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

int n, m;
vector<ll> dist;
vector<tuple<int, int, ll>> edges;
vector<int> parent;

void solve() {
    cin >> n >> m;

    dist.assign(n, 0);
    parent.assign(n, -1);
    edges.clear();

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w});
    }

    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto& [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }
        vector<int> cycle;
        int curr = x;
        while (true) {
            cycle.push_back(curr);
            if (curr == x && size(cycle) > 1) {
                break;
            }
            curr = parent[curr];
        }
        reverse(all(cycle));
        for (int& node : cycle) {
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