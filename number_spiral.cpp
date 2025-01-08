#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long y, x;
    cin >> y >> x;

    long long result = 0;

    if (y > x) {
      result = (y - 1) * (y - 1);
      if (y % 2 == 0) {
        result += (2 * y - x);
      } else {
        result += x;
      }
    } else {
      result = (x - 1) * (x - 1);
      if (x % 2 == 0) {
        result += y;
      } else {
        result += (2 * x - y);
      }
    }

    cout << result << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
