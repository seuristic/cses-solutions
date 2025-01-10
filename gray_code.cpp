#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> code((1 << n), string(n, '0'));

  for (int i = 0; i < n; ++i) {
    bool reversed = false;
    for (int j = 0; j < (1 << n); ++j) {
      for (int k = 0; k < (1 << i); ++k) {
        if (reversed) {
          code[j][i] = '1';
        }
        ++j;
      }
      for (int k = 0; k < (1 << i) && j < (1 << n); ++k) {
        if (!reversed) {
          code[j][i] = '1';
        }
        ++j;
      }
      reversed = !reversed;
      --j;
    }
  }

  for (string c : code) {
    cout << c << endl;
  }

  return 0;
}
