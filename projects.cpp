#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ios>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Event {
  int left, right;
  ll profit;
  bool operator<(const Event &other) const { return left < other.left; }
};

int n;
vector<Event> a;

void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].left >> a[i].right >> a[i].profit;
  }
  sort(all(a));

  vector<ll> dp(n + 1, -1);
  dp[n] = 0;

  for (int i = n - 1; i >= 0; --i) {
    auto [left, right, profit] = a[i];
    dp[i] = dp[i + 1];
    Event e = {right + 1, right + 1, 0};
    auto it = lower_bound(all(a), e);
    if (it == a.end()) {
      dp[i] = max(dp[i], profit);
    } else {
      dp[i] = max(dp[i], profit + dp[it - a.begin()]);
    }
  }

  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  auto chrono_start = chrono::high_resolution_clock::now();

  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }

  auto chrono_end = chrono::high_resolution_clock::now();
  chrono::duration<double, milli> chrono_duration = chrono_end - chrono_start;
  cerr << "Time Elapsed: " << fixed << setprecision(3)
       << chrono_duration.count() << "ms" << endl;
}
