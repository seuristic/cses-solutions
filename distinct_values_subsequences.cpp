#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

const int m = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;

  int result = 1;
  unordered_map<ll, ll> freq;
  for (const ll &x : a) {
    ++freq[x];
  }

  for (const auto &[x, f] : freq) {
    result = (result * (f + 1)) % m;
  }

  --result;

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
