#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> line_sweep;

  while (n--) {
    int a, b;
    cin >> a >> b;
    line_sweep.push_back({a, 1});
    line_sweep.push_back({b, -1});
  }

  sort(line_sweep.begin(), line_sweep.end());

  int result = 0, sum = 0;
  for (auto p : line_sweep) {
    sum += p.second;
    result = max(result, sum);
  }

  cout << result << endl;

  return 0;
}
