#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long x;
  cin >> n >> x;

  long long sum = 0;
  map<long long, int> freq;

  freq[0] = 1; // if x is given array element

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    sum += num;
    result += freq[sum - x];
    ++freq[sum];
  }

  cout << result << endl;

  return 0;
}
