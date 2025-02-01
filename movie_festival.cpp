#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> movies(n);
  for (auto &[a, b] : movies) {
    cin >> a >> b;
  }

  sort(movies.begin(), movies.end(),
       [](auto a, auto b) { return a.second < b.second; });

  int result = 0, last_end = 0;

  for (auto [start, end] : movies) {
    if (last_end <= start) {
      last_end = end;
      ++result;
    }
  }

  cout << result << endl;

  return 0;
}
