/* seuristic */

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;

    while (n != 1) {
      cout << n << ' ';
      if (n % 2 == 0)
        n >>= 1;
      else
        n = 3 * n + 1;
    }

    cout << n << endl;
  }

  return 0;
}
