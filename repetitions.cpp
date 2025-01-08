#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string input;
  cin >> input;

  int n = (int)input.size();

  int max_count = 0;
  for (int j = 0; j < n; ++j) {
    int i = j;
    while (j < n && input[i] == input[j]) {
      ++j;
    }
    max_count = max(max_count, j - i);
    --j;
  }

  cout << max_count << endl;

  return 0;
}
