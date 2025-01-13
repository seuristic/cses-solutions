#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void permute(size_t index, string s, set<string> &result) {
  if (index == s.length() - 1) {
    result.insert(s);
    return;
  }

  for (size_t i = index; i < s.length(); ++i) {
    swap(s[index], s[i]);
    permute(index + 1, s, result);
    swap(s[index], s[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  sort(s.begin(), s.end());

  set<string> result;
  permute(0, s, result);

  cout << result.size() << endl;
  for (string s : result) {
    cout << s << endl;
  }

  return 0;
}
