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

vector<int> parent, num;

int find(int x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

bool same(int u, int v) {
    return find(u) == find(v);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (num[u] > num[v]) {
        swap(u, v);
    }
    parent[u] = v;
    num[v] += num[u];
}

bool cmp(tuple<int, int, ll>& e1, tuple<int, int, ll>& e2) {
    return get<2>(e1) < get<2>(e2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, ll>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[i] = {u, v, w};
    }

    sort(all(edges), cmp);

    parent.resize(n);
    num.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    ll result = 0;
    for (auto& [u, v, w] : edges) {
        if (!same(u, v)) {
            unite(u, v);
            result += w;
        }
    }

    if (num[find(0)] != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}