#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define size(x) (int)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  multiset<ll> minset, maxset;
  ll sum_min = 0, sum_max = 0;
  for (int i = 0; i < n; ++i) {
    if (size(minset) == 0 || a[i] <= *minset.rbegin()) {
      minset.insert(a[i]);
      sum_min += a[i];
    } else {
      maxset.insert(a[i]);
      sum_max += a[i];
    }
    if (size(minset) > size(maxset) + 1) {
      sum_min -= *minset.rbegin();
      sum_max += *minset.rbegin();
      maxset.insert(*minset.rbegin());
      minset.erase(prev(minset.end()));
    } else if (size(minset) < size(maxset)) {
      sum_min += *maxset.begin();
      sum_max -= *maxset.begin();
      minset.insert(*maxset.begin());
      maxset.erase(maxset.begin());
    }

    if (i >= k - 1) {
      ll median = *minset.rbegin();
      ll cost = sum_max - sum_min + median * (size(minset) - size(maxset));
      cout << cost << ' ';

      ll out = a[i - k + 1];
      if (minset.find(out) != minset.end()) {
        minset.erase(minset.find(out));
        sum_min -= out;
      } else {
        maxset.erase(maxset.find(out));
        sum_max -= out;
      }

      if (size(minset) < size(maxset)) {
        sum_min += *maxset.begin();
        sum_max -= *maxset.begin();
        minset.insert(*maxset.begin());
        maxset.erase(maxset.begin());
      }
    }
  }

  cout << endl;

  return 0;
}
