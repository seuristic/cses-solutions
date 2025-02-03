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

  long long max_sum = INT_MIN, sum = 0;
  for (long long x : a) {
    sum = max(x, sum + x);
    max_sum = max(max_sum, sum);
  }

  cout << max_sum << endl;

  return 0;
}
