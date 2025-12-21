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
vector<int> parent, num;
int max_num, components;

int find(int x) {
    return (parent[x] == x ? x : parent[x] = find(parent[x]));
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    if (same(x, y)) return;
    x = find(x);
    y = find(y);
    if (num[x] > num[y]) swap(x, y);
    parent[x] = y;
    num[y] += num[x];
    max_num = max(max_num, num[y]);
    components--;
}

void solve() {
    cin >> n >> m;

    parent.resize(n);
    num.assign(n, 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
    max_num = 1;
    components = n;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        unite(a, b);
        cout << components << ' ' << max_num << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}