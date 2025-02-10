#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

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

  for (int i = 0; i < n; ++i) {
    cin >> ranges[i].left >> ranges[i].right;
    ranges[i].index = i;
  }

  sort(ranges.begin(), ranges.end());

  vector<int> contains(n), contained(n);

  int minRight = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    if (ranges[i].right >= minRight) {
      contains[ranges[i].index] = 1;
    }
    minRight = min(minRight, ranges[i].right);
  }

  int maxRight = INT_MIN;
  for (int i = 0; i < n; ++i) {
    if (ranges[i].right <= maxRight) {
      contained[ranges[i].index] = 1;
    }
    maxRight = max(maxRight, ranges[i].right);
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
