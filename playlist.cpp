#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  int result = 0;

  map<int, int> pos;

  for (int i = 0, j = 0; j < n; ++j) {
    i = max(pos[a[j]], i);
    result = max(result, j - i + 1);
    pos[a[j]] = j + 1;
  }

  cout << result << "\n";

  return 0;
}
