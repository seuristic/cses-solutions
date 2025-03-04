#include <bits/stdc++.h>
#include <cstring>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (int x = 1; x <= n; ++x) {
    for (int d = 1; d <= 6; ++d) {
      if (x >= d) {
        dp[x] = (dp[x] + dp[x - d]) % MOD;
      }
    }
  }

  cout << dp[n] << endl;

  return 0;
}
