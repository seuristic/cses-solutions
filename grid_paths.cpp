#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 7;
const int dir[] = {0, 1, 0, -1, 0};

bool visited[N][N];
string path;
vector<int> p(48);

int result = 0;

bool is_valid(int r, int c) {
  if (r < 0 || r >= N || c < 0 || c >= N || visited[r][c])
    return false;
  return true;
}

void solve(int r, int c, int index) {
  if (!is_valid(r + 1, c) && !is_valid(r - 1, c) && is_valid(r, c - 1) &&
      is_valid(r, c + 1))
    return;

  if (!is_valid(r, c + 1) && !is_valid(r, c - 1) && is_valid(r - 1, c) &&
      is_valid(r + 1, c))
    return;

  if (r == N - 1 && c == 0) {
    if (index == 48)
      ++result;
    return;
  }

  if (index == 48) {
    return;
  }

  visited[r][c] = true;

  if (p[index] < 4) {
    int nr = r + dir[p[index]];
    int nc = c + dir[p[index] + 1];
    if (is_valid(nr, nc)) {
      solve(nr, nc, index + 1);
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      int nr = r + dir[i];
      int nc = c + dir[i + 1];
      if (is_valid(nr, nc)) {
        solve(nr, nc, index + 1);
      }
    }
  }

  visited[r][c] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> path;

  for (int i = 0; i < 48; ++i) {
    if (path[i] == 'R')
      p[i] = 0;
    else if (path[i] == 'D')
      p[i] = 1;
    else if (path[i] == 'L')
      p[i] = 2;
    else if (path[i] == 'U')
      p[i] = 3;
    else
      p[i] = 4;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      visited[i][j] = false;
    }
  }

  solve(0, 0, 0);

  cout << result << endl;

  return 0;
}
