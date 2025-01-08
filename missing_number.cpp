#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    a[x - 1] = 1;
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}
