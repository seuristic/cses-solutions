#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long result = 0;
  map<long long, int> freq;

  int left = 0, right = 0;
  int count_unique = 0;
  while (right < n) {
    ++freq[a[right]];
    if (freq[a[right]] == 1) {
      ++count_unique;
    }
    if (count_unique > k) {
      result += (right - left) * (right - left + 1LL) / 2;
      while (left <= right && count_unique > k) {
        --freq[a[left]];
        if (freq[a[left]] == 0) {
          --count_unique;
        }
        ++left;
      }
      result -= (right - left) * (right - left + 1LL) / 2;
    }

    ++right;
  }

  result += (right - left) * (right - left + 1LL) / 2;
  cout << result << endl;

  return 0;
}
