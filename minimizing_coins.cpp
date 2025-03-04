#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

const int INF = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<int> dp(x + 1, INF);
  dp[0] = 0;

  for (int amount = 1; amount <= x; ++amount) {
    for (int i = 0; i < n; ++i) {
      if (amount >= c[i]) {
        dp[amount] = min(dp[amount], 1 + dp[amount - c[i]]);
      }
    }
  }

  cout << (dp[x] == INF ? -1 : dp[x]) << endl;

  return 0;
}
