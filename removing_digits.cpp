#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

vector<int> memo;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> dp(n + 1, INT_MAX);
  dp[0] = 0;

  for (int num = 1; num <= n; ++num) {
    for (int m = num; m > 0; m /= 10) {
      dp[num] = min(dp[num], 1 + dp[num - m % 10]);
    }
  }

  cout << dp[n] << endl;

  return 0;
}
