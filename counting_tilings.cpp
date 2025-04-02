#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

const int MOD = 1e9 + 7;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vi> comp(1 << n, vi(1 << n));

  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      int inactive = (~i) & (~j);
      int last = -1;
      bool ok = true;
      for (int k = 0; k < n; ++k) {
        if ((1 << k) & inactive) {
          if (last == -1) {
            last = k;
          }
        } else {
          if (last != -1) {
            ok &= (k - last) % 2 == 0;
            last = -1;
          }
        }
      }
      if (last != -1) {
        ok &= (n - last) % 2 == 0;
      }

      comp[i][j] = ok;
    }
  }

  vector<vl> dp(m + 2, vl(1 << n));
  dp[1][0] = 1;

  for (int i = 2; i <= m + 1; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      int poss = (~mask) & ((1 << n) - 1);
      for (int sub = poss; sub; sub = (sub - 1) & poss) {
        dp[i][mask] += dp[i - 1][sub] * comp[mask][sub];
      }
      dp[i][mask] += dp[i - 1][0] * comp[mask][0];
      dp[i][mask] %= MOD;
    }
  }

  cout << dp[m + 1][0] << endl;
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
