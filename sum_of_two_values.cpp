#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  int left = 0, right = n - 1;
  bool flag = false;

  while (left < right) {
    int sum = a[left].first + a[right].first;
    if (sum == x) {
      int i = a[left].second + 1;
      int j = a[right].second + 1;
      if (i > j) {
        swap(i, j);
      }
      cout << i << ' ' << j << endl;
      flag = true;
      break;
    } else if (sum < x) {
      ++left;
    } else {
      --right;
    }
  }

  if (!flag) {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
