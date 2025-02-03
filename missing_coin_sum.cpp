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

  sort(a.begin(), a.end());

  long long result = 1;
  for (int x : a) {
    if (x > result) {
      break;
    }
    result += x;
  }

  cout << result << endl;

  return 0;
}
