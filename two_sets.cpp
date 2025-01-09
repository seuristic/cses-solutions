#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if ((n + 1) % 4 > 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    ll target_sum = n * (n + 1LL) / 4;
    vector<int> first;
    for (int i = n; i > 0 && target_sum > 0; --i) {
      if (i <= target_sum) {
        target_sum -= i;
        first.push_back(i);
      }
    }

    sort(first.begin(), first.end());

    vector<int> second;
    int prev = 0;
    for (int x : first) {
      for (int i = prev + 1; i < x; ++i) {
        second.push_back(i);
      }
      prev = x;
    }

    // first
    cout << first.size() << endl;
    for (int x : first)
      cout << x << ' ';

    cout << endl;

    // second
    cout << second.size() << endl;
    for (int x : second)
      cout << x << ' ';

    cout << endl;
  }

  return 0;
}
