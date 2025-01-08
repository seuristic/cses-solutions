#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  long long result = 0;
  int prev = a[0];
  for (int i = 1; i < n; ++i) {
    if (prev > a[i]) {
      result += 1LL * (prev - a[i]);
    } else {
      prev = a[i];
    }
  }

  cout << result << endl;

  return 0;
}
