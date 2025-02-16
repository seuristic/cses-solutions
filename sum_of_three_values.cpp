#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve() {
  long long n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  for (long long i = 0; i < n - 2; ++i) {
    long long target = x - a[i].first;
    long long left = i + 1, right = n - 1;
    while (left < right) {
      long long sum = a[left].first + a[right].first;
      if (sum == target) {
        vector<int> pos = {a[i].second, a[left].second, a[right].second};
        sort(pos.begin(), pos.end());
        for (long long p : pos) {
          cout << p << ' ';
        }
        cout << endl;
        return;
      } else if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
