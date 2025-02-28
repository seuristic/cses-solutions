#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }

  multiset<ll> ms;
  ll result = LLONG_MIN;

  for (int i = a; i <= n; ++i) {
    if (i > b) {
      ms.erase(ms.find(pref[i - b - 1]));
    }
    ms.insert(pref[i - a]);
    result = max(result, pref[i] - *ms.begin());
  }

  cout << result << endl;

  return 0;
}
