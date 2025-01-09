#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  long long result = 1;
  for (int i = 0; i < n; ++i) {
    result = (result << 1) % MOD;
  }

  cout << result << endl;

  return 0;
}
