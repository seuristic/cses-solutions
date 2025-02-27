#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()

struct Range {
  int left, right;
  bool operator<(Range const &other) const { return right < other.right; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<Range> a(n);
  for (auto &r : a) {
    cin >> r.left >> r.right;
  }

  sort(a.begin(), a.end());

  multiset<int> end_times;
  for (int i = 0; i < k; ++i) {
    end_times.insert(0);
  }

  int result = 0;

  for (int i = 0; i < n; ++i) {
    auto it = end_times.upper_bound(a[i].left);
    if (it == end_times.begin()) {
      continue;
    }
    end_times.erase(--it);
    end_times.insert(a[i].right);
    ++result;
  }

  cout << result << endl;

  return 0;
}
