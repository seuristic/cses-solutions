#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pos[x] = i + 1;
  }

  int rounds = 1;
  for (int i = 2; i <= n; ++i) {
    if (pos[i - 1] > pos[i]) {
      ++rounds;
    }
  }

  cout << rounds << endl;

  return 0;
}
