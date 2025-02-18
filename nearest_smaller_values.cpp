#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> stack;
  vector<int> result;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    while (stack.size() && stack.back().first >= x) {
      stack.pop_back();
    }

    if (stack.empty()) {
      result.push_back(0);
    } else {
      result.push_back(stack.back().second);
    }

    stack.push_back({x, i + 1});
  }

  for (int x : result) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}
