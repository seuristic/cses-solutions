#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;

    long long digits = 1, count = 9, start = 1;
    while (k > digits * count) {
      k -= digits * count;
      ++digits;
      count *= 10;
      start *= 10;
    }

    long long num = start + (k - 1) / digits;
    string number = to_string(num);
    cout << number[(k - 1) % digits] << endl;
  }

  return 0;
}
