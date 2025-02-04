#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> nums(n + 1), pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
    pos[nums[i]] = i;
  }

  int rounds = 1;

  for (int i = 2; i <= n; ++i) {
    if (pos[i - 1] > pos[i]) {
      ++rounds;
    }
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    int min_index = min(nums[a], nums[b]);
    int max_index = max(nums[a], nums[b]);

    // element < pos[min_index]
    if (min_index > 1) {
      if (pos[min_index - 1] > pos[min_index] &&
          pos[min_index - 1] < pos[max_index]) {
        --rounds;
      } else if (pos[min_index - 1] < pos[min_index] &&
                 pos[min_index - 1] > pos[max_index]) {
        ++rounds;
      }
    }

    // pos[min_index] < element < pos[max_index]
    if (min_index + 1 == max_index) {
      if (pos[min_index] > pos[max_index]) {
        --rounds;
      } else {
        ++rounds;
      }
    } else {
      if (pos[min_index] > pos[min_index + 1] &&
          pos[max_index] < pos[min_index + 1]) {
        --rounds;
      } else if (pos[min_index] < pos[min_index + 1] &&
                 pos[max_index] > pos[min_index + 1]) {
        ++rounds;
      }
      if (pos[max_index - 1] > pos[max_index] &&
          pos[max_index - 1] < pos[min_index]) {
        --rounds;
      } else if (pos[max_index - 1] < pos[max_index] &&
                 pos[max_index - 1] > pos[min_index]) {
        ++rounds;
      }
    }

    // pos[max_index] < element
    if (max_index < n) {
      if (pos[max_index] > pos[max_index + 1] &&
          pos[min_index] < pos[max_index + 1]) {
        --rounds;
      } else if (pos[max_index] < pos[max_index + 1] &&
                 pos[min_index] > pos[max_index + 1]) {
        ++rounds;
      }
    }

    swap(pos[min_index], pos[max_index]);
    swap(nums[a], nums[b]);

    cout << rounds << endl;
  }

  return 0;
}
