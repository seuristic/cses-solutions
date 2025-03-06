#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<ll> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int amount = c[i]; amount <= x; ++amount) {
      dp[amount] += dp[amount - c[i]];
      dp[amount] %= MOD;
    }
  }

  cout << dp[x] << endl;

  return 0;
}
