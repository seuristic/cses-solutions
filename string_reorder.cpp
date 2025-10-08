#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define size(x) (int)(x).size()
#define all(x) begin(x), end(x)

void solve() {
  string s;
  cin >> s;

  int n = size(s);
  vector<int> freq(26);

  for (char &c : s) {
    ++freq[c - 'A'];
    if (freq[c - 'A'] > (n + 1) / 2) {
      cout << -1 << endl;
      return;
    }
  }

  string result = "";
  int totalFreq = n;
  while (totalFreq > 0) {
    int maxCharFreq = 0, maxCharIndex = -1;
    for (int i = 0; i < 26; ++i) {
      if (maxCharFreq < freq[i]) {
        maxCharFreq = freq[i];
        maxCharIndex = i;
      }
    }

    if (2 * maxCharFreq == totalFreq + 1) {
      result += char('A' + maxCharIndex);
      --freq[maxCharIndex];
    } else {
      for (int i = 0; i < 26; ++i) {
        if (freq[i] == 0) {
          continue;
        }
        if (result.empty() || result.back() - 'A' != i) {
          result += char('A' + i);
          --freq[i];
          break;
        }
      }
    }
    --totalFreq;
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
