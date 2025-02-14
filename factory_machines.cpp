#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool possible(vector<long long> &a, long long total, long long T) {
  long long sum = 0;
  for (int x : a) {
    sum += T / x;
    if (sum >= total) {
      return true;
    }
  }

  return sum >= total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, t;
  cin >> n >> t;
  vector<long long> a(n);
  for (long long &x : a) {
    cin >> x;
  }

  long long low = 0, high = 1e18;
  while (low < high) {
    long long mid = low + (high - low) / 2;
    if (possible(a, t, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low << endl;

  return 0;
}
