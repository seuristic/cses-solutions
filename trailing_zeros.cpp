#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int result = 0;
  long power5 = 5;
  while (n >= power5) {
    result += n / power5;
    power5 *= 5;
  }
  cout << result << endl;

  return 0;
}
