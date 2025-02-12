#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define LSOne(x) ((x) & (-x))

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
  int left, right, index;

  bool operator<(const Range &other) const {
    if (left == other.left) {
      return right > other.right;
    }
    return left < other.left;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Range> ranges(n);
  vector<int> contained(n), contains(n);
  indexed_set<pair<int, int>> right_endpoints;

  for (int i = 0; i < n; ++i) {
    cin >> ranges[i].left >> ranges[i].right;
    ranges[i].index = i;
  }

  sort(ranges.begin(), ranges.end());

  // contained
  for (int i = 0; i < n; ++i) {
    right_endpoints.insert({ranges[i].right, -i});
    contained[ranges[i].index] =
        right_endpoints.size() -
        right_endpoints.order_of_key({ranges[i].right, -i}) - 1;
  }

  right_endpoints.clear();

  // contains
  for (int i = n - 1; i >= 0; --i) {
    right_endpoints.insert({ranges[i].right, -i});
    contains[ranges[i].index] =
        right_endpoints.order_of_key({ranges[i].right, -i});
  }

  for (int i = 0; i < n; ++i) {
    cout << contains[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << contained[i] << ' ';
  }
  cout << endl;

  return 0;
}
