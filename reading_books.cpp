#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) {
    cin >> x;
  }

  sort(a.begin(), a.end());

  long long sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += a[i];
  }

  if (sum <= a.back()) {
    cout << 2 * a.back() << endl;
  } else {
    cout << sum + a.back() << endl;
  }

  return 0;
}
