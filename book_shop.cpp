#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  for (int &val : h) {
    cin >> val;
  }
  for (int &val : s) {
    cin >> val;
  }

  vector<int> dp(x + 1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = x; j >= h[i]; --j) {
      dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
    }
  }

  cout << dp[x] << endl;

  return 0;
}
