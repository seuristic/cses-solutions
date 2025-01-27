#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);
  for (int &x : a)
    cin >> x;
  for (int &y : b)
    cin >> y;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int result = 0;
  int i = 0, j = 0;

  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) {
      ++i, ++j;
      ++result;
    } else {
      if (a[i] - b[j] > k) {
        ++j;
      } else {
        ++i;
      }
    }
  }

  cout << result << endl;

  return 0;
}
