#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    q.push(i);
  }

  bool flag = false;

  while (!q.empty()) {
    int num = q.front();
    q.pop();

    if (flag) {
      cout << num << ' ';
    } else {
      q.push(num);
    }

    flag = !flag;
  }

  cout << endl;

  return 0;
}
