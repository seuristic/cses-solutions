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

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define SIZE(x) (int)(x).size()
#define ENDL '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }

    ll missing = 1LL * n * (n + 1) / 2 - sum;
    cout << missing << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}