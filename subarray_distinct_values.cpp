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

  int prevR = -1;
  int currL = 0, currR = 0;

  while (currR < n) {
    while (currR < n && (int)freq.size() <= k) {
      ++freq[a[currR]];
      ++currR;
    }
    if ((int)freq.size() > k) {
      --currR;
      --freq[a[currR]];
    }

    long long m = currR - currL;
    result += m * (m + 1LL) / 2;
    if (prevR > currL) {
      m = prevR - currL;
      result -= m * (m + 1LL) / 2;
    }

    prevR = currR;

    while (currL < currR && (int)freq.size() > k) {
      if (freq[a[currL]] == 1) {
        freq.erase(a[currL]);
      } else {
        --freq[a[currL]];
      }
      ++currL;
    }
  }

  cout << result << endl;

  return 0;
}
