#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;

  multiset<int> ms;
  ms.insert(x);

  set<int> s;
  s.insert(0);
  s.insert(x);

  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;

    auto it = s.lower_bound(p);
    auto it2 = it;
    --it;

    ms.erase(ms.find(*it2 - *it));
    ms.insert(p - *it);
    ms.insert(*it2 - p);

    cout << *(--ms.end()) << ' ';

    s.insert(p);
  }

  cout << endl;

  return 0;
}
