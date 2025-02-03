#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> p(n);
  for (int &x : p) {
    cin >> x;
  }

  sort(p.begin(), p.end());

  long long result = 0;

  for (int i = 0; i < n; ++i) {
    result += abs(p[i] - p[n / 2]);
  }

  cout << result << endl;

  return 0;
}
