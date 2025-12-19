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

const int M = 30;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> succ(n + 1, vector<int>(M));
    for (int i = 1; i <= n; ++i) {
        cin >> succ[i][0];
    }

    for (int j = 1; j < M; ++j) {
        for (int i = 1; i <= n; ++i) {
            succ[i][j] = succ[succ[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < M; ++j) {
            if (k & (1 << j)) {
                x = succ[x][j];
            }
        }
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}