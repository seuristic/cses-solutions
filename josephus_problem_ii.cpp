#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n, k;
  cin >> n >> k;

  indexed_set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  int index = k % n;
  while (s.size() > 0) {
    int r = *s.find_by_order(index);
    s.erase(r);
    if (s.size() > 0) {
      index = (index + k) % s.size();
    }
    cout << r << ' ';
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
