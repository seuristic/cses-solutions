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

// int n;
// vector<vector<int>> adj;
// vector<int> path;

// APPROACH 1: bitmanip + dfs (Hierholzer's algo) => eulerian circuit
// void dfs(int u) {
//     while (!adj[u].empty()) {
//         int v = adj[u].back();
//         adj[u].pop_back();
//         dfs(v);
//     }
//     path.push_back(u & 1);
// }

// void solve() {
//     cin >> n;

//     if (n == 1) {
//         cout << "01" << endl;
//         return;
//     }

//     adj.assign((1 << (n - 1)), {});
//     path.clear();

//     for (int i = 0; i < (1 << (n - 1)); ++i) {
//         int j = (i << 1) % (1 << (n - 1));
//         adj[i].push_back(j);
//         adj[i].push_back(j | 1);
//     }

//     dfs(0);

//     for (int i = 0; i < n - 2; ++i) {
//         path.push_back(0);
//     }

//     for (int c : path) {
//         cout << char(c + '0');
//     }
//     cout << endl;
// }

// APPROACH 2: backtracking
int n;
vector<bool> visited;
vector<int> path;

void search(int pos, int part, int n) {
    if (pos == (1 << n) + n - 1) {
        for (int p : path) {
            cout << p;
        }
        cout << endl;
        exit(0);
    }

    int next_part0 = ((part << 1) & ((1 << n) - 1));
    if (!visited[next_part0]) {
        visited[next_part0] = true;
        path[pos] = 0;
        search(pos + 1, next_part0, n);
        visited[next_part0] = false;
    }

    int next_part1 = (((part << 1) & ((1 << n) - 1)) | 1);
    if (!visited[next_part1]) {
        visited[next_part1] = true;
        path[pos] = 1;
        search(pos + 1, next_part1, n);
        visited[next_part1] = false;
    }
}

void solve() {
    cin >> n;

    visited.assign(1 << n, false);
    path.assign((1 << n) + n - 1, 0);

    visited[0] = true;
    search(n, 0, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}