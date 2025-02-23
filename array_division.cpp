#include <bits/stdc++.h>

#define endl '\n'
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

bool isPossible(vector<ll> &a, int &k, ll &mid) {
  ll sum = 0;
  int count = 0;
  for (ll &x : a) {
    if (x > mid)
      return false;
    if (sum + x > mid) {
      ++count;
      sum = 0;
    }
    sum += x;
  }
  if (sum <= mid)
    ++count;

  return count <= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }

  ll low = *max_element(a.begin(), a.end());
  ll high = accumulate(a.begin(), a.end(), 0LL);
  while (low < high) {
    ll mid = low + (high - low) / 2;
    if (isPossible(a, k, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low << endl;

  return 0;
}
