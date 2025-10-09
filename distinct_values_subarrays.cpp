#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  long long result = 0;
  int left = 0;
  unordered_map<int, int> freq;

  for (int right = 0; right < n; ++right) {
    ++freq[a[right]];

    while (freq[a[right]] > 1) {
      --freq[a[left]];
      ++left;
    }

    result += (long long)(right - left + 1LL);
  }

  cout << result << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
