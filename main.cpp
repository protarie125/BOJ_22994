#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vs = vector<string>;

ll R, C;
vs img;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> R >> C;
  img = vs(R);
  for (auto&& s : img) cin >> s;

  auto dr = vl{};
  for (auto i = 1; i <= R; ++i) {
    if (R % i == 0) dr.push_back(i);
  }
  auto dc = vl{};
  for (auto i = 1; i <= C; ++i) {
    if (C % i == 0) dc.push_back(i);
  }

  vector<pair<ll, ll>> area_n{};
  for (const auto& n : dr) {
    for (const auto& m : dc) {
      auto subimg = vs(R, string(C, ' '));
      for (auto i = 0; i < R / n; ++i) {
        for (auto j = 0; j < C / m; ++j) {
          const auto& x = img[i * n][j * m];
          for (auto rr = 0; rr < n; ++rr) {
            for (auto cc = 0; cc < m; ++cc) {
              subimg[i * n + rr][j * m + cc] = x;
            }
          }
        }
      }

      auto is_eq = true;
      for (auto i = 0; i < R; ++i) {
        if (img[i] != subimg[i]) {
          is_eq = false;
          break;
        }
      }

      if (is_eq) {
        const auto& an = R / n;
        const auto& am = C / m;
        area_n.push_back({an * am, an});
      }
    }
  }

  sort(area_n.begin(), area_n.end());
  const auto& [area, an] = area_n.front();
  const auto& am = area / an;
  cout << an << ' ' << am << '\n';
  for (auto i = 0; i < an; ++i) {
    for (auto j = 0; j < am; ++j) {
      cout << img[i * (R / an)][j * (C / am)];
    }
    cout << '\n';
  }

  return 0;
}