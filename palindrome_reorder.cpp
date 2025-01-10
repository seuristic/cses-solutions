#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  vector<int> freq(26);
  for (char c : s) {
    ++freq[c - 'A'];
  }

  int count_single_occurrence = 0;
  for (int f : freq) {
    if (f % 2 == 1)
      ++count_single_occurrence;
  }

  if (count_single_occurrence > 1) {
    cout << "NO SOLUTION" << endl;
  } else {
    int n = s.length();
    string result = string(n, ' ');
    for (int i = 0, j = 0; i < 26; ++i) {
      int count = freq[i] / 2;
      while (count--) {
        result[j] = result[n - j - 1] = char('A' + i);
        ++j;
      }
      if (freq[i] % 2 == 1) {
        result[n / 2] = char('A' + i);
      }
    }
    cout << result << endl;
  }

  return 0;
}
