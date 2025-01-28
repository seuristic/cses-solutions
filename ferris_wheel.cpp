#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  unordered_map<int, int> freq;
  vector<int> a(n);
  for (int &num : a) {
    cin >> num;
    ++freq[num];
  }

  sort(a.begin(), a.end());

  int result = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    int sum = a[i] + a[j];
    if (sum <= x) {
      ++i;
    }
    --j;
    ++result;
  }

  cout << result << endl;

  return 0;
}
