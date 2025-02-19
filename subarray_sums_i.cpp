#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long x;
  cin >> n >> x;

  int left = 0;
  long long sum = 0;
  vector<long long> a(n);

  int result = 0;
  for (int right = 0; right < n; ++right) {
    cin >> a[right];

    sum += a[right];

    while (sum > x && left <= right) {
      sum -= a[left];
      ++left;
    }

    if (sum == x) {
      ++result;
    }
  }

  cout << result << endl;

  return 0;
}
