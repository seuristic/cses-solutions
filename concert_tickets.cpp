#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  multiset<int> tickets;
  while (n--) {
    int ticket;
    cin >> ticket;
    tickets.insert(ticket);
  }

  while (m--) {
    int max_price;
    cin >> max_price;

    auto it = tickets.upper_bound(max_price);

    int result = -1;
    if (it != tickets.begin()) {
      --it;
      result = *it;
      tickets.erase(it);
    }

    cout << result << endl;
  }

  return 0;
}
