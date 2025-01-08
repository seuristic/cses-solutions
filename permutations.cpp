#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (i < n / 2)
      cout << 2 * (i + 1) << ' ';
    else
      cout << 2 * (i - n / 2) + 1 << " \n"[i == n - 1];
  }

  return 0;
}
