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

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dp[20][10][2][2];

ll rec(string &s, int n, int x, bool lz, bool tight) {
  if (n == 0) {
    return 1;
  }

  if (x != -1 && dp[n][x][lz][tight] != -1) {
    return dp[n][x][lz][tight];
  }

  ll lb = 0, ub = tight ? (s[s.length() - n] - '0') : 9;
  ll result = 0;
  for (int d = lb; d <= ub; ++d) {
    if (d == x && !lz) {
      continue;
    }
    result += rec(s, n - 1, d, lz & (d == 0), tight & (d == ub));
  }

  return dp[n][x][lz][tight] = result;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  string A = to_string(a - 1);
  string B = to_string(b);

  memset(dp, -1, sizeof dp);
  ll result = rec(B, B.length(), -1, true, true);
  memset(dp, -1, sizeof dp);
  result -= rec(A, A.length(), -1, true, true);

  cout << result << endl;
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
