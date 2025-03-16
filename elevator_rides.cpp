#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (ll &w : a) {
    cin >> w;
  }

  vector<pair<ll, ll>> dp(1 << n);
  dp[0] = {1, 0};

  for (int mask = 1; mask < (1 << n); ++mask) {
    dp[mask] = {21, 0};
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        auto [rides, weight] = dp[mask ^ (1 << i)];
        if (weight + a[i] > x) {
          ++rides;
          weight = min(weight, a[i]);
        } else {
          weight += a[i];
        }

        dp[mask] = min(dp[mask], {rides, weight});
      }
    }
  }

  cout << dp[(1 << n) - 1].first << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto chrono_start = high_resolution_clock::now();

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }

  auto chrono_end = high_resolution_clock::now();
  duration<double, milli> chrono_duration = chrono_end - chrono_start;
  cerr << fixed << setprecision(3) << chrono_duration.count() << "ms" << endl;
}
