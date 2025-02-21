#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<long long> freq(N);
  freq[0] = 1;
  long long psum = 0, result = 0;
  for (int i = 0; i < N; ++i) {
    long long x;
    cin >> x;
    psum += x;
    ++freq[(psum % N + N) % N];
  }

  for (long long x : freq) {
    result += x * (x - 1) / 2;
  }

  cout << result << endl;

  return 0;
}
