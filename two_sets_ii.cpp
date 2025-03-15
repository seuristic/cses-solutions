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
  ll n;
  cin >> n;

  if ((n + 1LL) % 4 > 1) {
    cout << 0 << endl;
    return;
  }

  ll half_sum = n * (n + 1LL) / 4;
  vector<ll> dp(half_sum + 1, 0);

  dp[0] = 1;

  for (int x = 1; x < n; ++x) {
    for (int sum = half_sum; sum >= x; --sum) {
      (dp[sum] += dp[sum - x]) %= MOD;
    }
  }

  cout << dp[half_sum] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
}
