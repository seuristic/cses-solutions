#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;
  ll total = 0;
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total += a[i];
  }

  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      if (l == r) {
        dp[l][r] = a[l];
      } else {
        dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
      }
    }
  }

  cout << (total + dp[0][n - 1]) / 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
