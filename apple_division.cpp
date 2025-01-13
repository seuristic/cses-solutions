#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve(size_t index, long sum, long &total, vector<int> &a, long &result) {
  if (index == a.size()) {
    result = min(result, abs(total - 2 * sum));
    return;
  }

  solve(index + 1, sum + a[index], total, a, result);
  solve(index + 1, sum, total, a, result);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  long total = 0;
  for (int &x : a) {
    cin >> x;
    total += x;
  }

  long result = INT_MAX;
  solve(0, 0, total, a, result);
  cout << result << endl;

  return 0;
}
