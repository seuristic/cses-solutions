#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);

  int count = 0;
  int element = 0;
  for (int i = 0; i < n; ++i) {
    if (element != a[i]) {
      element = a[i];
      ++count;
    }
  }

  cout << count << endl;

  return 0;
}
