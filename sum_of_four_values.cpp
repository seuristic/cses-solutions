#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  unordered_map<long long, vector<pair<int, int>>> h;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      long long sum = a[i] + a[j];
      long long target = x - sum;

      if (h.count(target)) {
        for (auto [u, v] : h[target]) {
          if (u != i && u != j && v != i && v != j) {
            cout << u + 1 << ' ' << v + 1 << ' ' << i + 1 << ' ' << j + 1
                 << endl;
            return;
          }
        }
      }

      h[sum].push_back({i, j});
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
