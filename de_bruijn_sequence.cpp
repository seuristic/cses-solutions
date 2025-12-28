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
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    path.push_back(u & 1);
}

void solve() {
    cin >> n;

    if (n == 1) {
        cout << "01" << endl;
        return;
    }

    adj.assign((1 << (n - 1)), {});
    path.clear();

    for (int i = 0; i < (1 << (n - 1)); ++i) {
        int j = (i << 1) % (1 << (n - 1));
        adj[i].push_back(j);
        adj[i].push_back(j | 1);
    }

    dfs(0);

    for (int i = 0; i < n - 2; ++i) {
        path.push_back(0);
    }

    for (int c : path) {
        cout << char(c + '0');
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