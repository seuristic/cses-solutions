#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

void setIO(string filename = "") {
    cin.tie(nullptr)->sync_with_stdio(false);
    if (size(filename) > 0) {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if ((a != b && (a == 0 || b == 0)) || a + b > n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int num = 1; num <= n; ++num) {
      cout << num << ' ';
    }
    cout << endl;

    int countSame = n - a - b;
    for (int num = 1; num <= countSame; ++num) {
      cout << num << ' ';
    }

    int aStart = countSame + 1;
    int bStart = aStart + a;
    for (int num = bStart, count = 0; count < b; ++count, ++num) {
      cout << num << ' ';
    }
    for (int num = aStart, count = 0; count < a; ++count, ++num) {
      cout << num << ' ';
    }
    cout << endl;
  }
}

int main() {
  setIO("file");
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
