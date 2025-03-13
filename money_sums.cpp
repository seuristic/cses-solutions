#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define INF 1000000007
#define MOD INF

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  int max_sum = n * 1000;
  vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; ++i) {
    for (int sum = 0; sum <= max_sum; ++sum) {
      dp[i][sum] = dp[i - 1][sum];
      int left = sum - a[i - 1];
      if (left >= 0 && dp[i - 1][left]) {
        dp[i][sum] = true;
      }
    }
  }

  vector<int> result;
  for (int x = 1; x <= max_sum; ++x) {
    if (dp[n][x]) {
      result.push_back(x);
    }
  }

  cout << sz(result) << endl;
  for (int r : result) {
    cout << r << ' ';
  }
  cout << endl;

  return 0;
}
