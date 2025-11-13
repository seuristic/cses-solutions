#include <algorithm>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> arrive(n + 1);
    q.push(1);
    arrive[1] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (arrive[v] == 0) {
                q.push(v);
                arrive[v] = u;
            }
        }
    }

    if (arrive[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int i = n;
    vector<int> result{n};
    while (i != 1) {
        i = arrive[i];
        result.push_back(i);
    }

    reverse(all(result));

    cout << size(result) << endl;
    for (int x : result) {
        cout << x << ' ';
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