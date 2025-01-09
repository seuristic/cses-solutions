#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    long long result = (i * i) * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1);
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
