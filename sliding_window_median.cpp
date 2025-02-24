#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define endl '\n'
#define LSOne(x) ((x) & (-x))
#define size(x) (int)x.size()

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  indexed_set<pair<ll, int>> iset;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    iset.insert({a[i], i});
    if (size(iset) > k) {
      iset.erase(iset.find({a[i - k], i - k}));
    }
    if (size(iset) == k) {
      cout << iset.find_by_order((k - 1) / 2)->first << ' ';
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
