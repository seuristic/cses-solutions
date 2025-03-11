#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define MOD 1000000007

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 5;
vector<ll> dp1(N), dp2(N);

void solve() {
  int n;
  cin >> n;
  ll result = (dp1[n] + dp2[n]) % MOD;
  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  dp1[1] = dp2[1] = 1;
  for (int i = 2; i < N; ++i) {
    dp1[i] = (2 * dp1[i - 1] + dp2[i - 1]) % MOD;
    dp2[i] = (4 * dp2[i - 1] + dp1[i - 1]) % MOD;
  }

  int tc = 1;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
