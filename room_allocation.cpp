#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct Range {
  int left, right, index;

  bool operator<(const Range &other) const { return left < other.left; }
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

  priority_queue<pair<int, int>> pq;

  int k = 0;
  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    if (pq.empty() || -pq.top().first >= ranges[i].left) {
      ++k;
      pq.push({-ranges[i].right, k});
      result[ranges[i].index] = k;
    } else {
      auto [right, curr_k] = pq.top();
      pq.pop();
      pq.push({-ranges[i].right, curr_k});
      result[ranges[i].index] = curr_k;
    }
  }

  cout << k << endl;
  for (int i = 0; i < n; ++i) {
    cout << result[i] << ' ';
  }
  cout << endl;

  return 0;
}
