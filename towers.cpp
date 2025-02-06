#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> tower_stack;
  for (int i = 0; i < n; ++i) {
    int tower;
    cin >> tower;
    auto it = lower_bound(tower_stack.begin(), tower_stack.end(), tower + 1);
    if (it == tower_stack.end()) {
      tower_stack.push_back(tower);
    } else {
      *it = tower;
    }
  }

  cout << tower_stack.size() << endl;

  return 0;
}
