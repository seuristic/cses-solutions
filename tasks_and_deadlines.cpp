#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end());

  long long result = a[0].second - a[0].first;
  for (int i = 1; i < n; ++i) {
    a[i].first += a[i - 1].first;
    result += a[i].second - a[i].first;
  }

  cout << result << endl;

  return 0;
}
