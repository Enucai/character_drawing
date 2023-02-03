/*
* Author: Enucai
* Date: 2022-12-14 08:47:28
* LastEditTime: 2023-02-03 13:36:04
*/

#include <bits/stdc++.h>
#ifdef dbg
#define D(...) fprintf(stderr, __VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ " = "), debug_helper::debug(__VA_ARGS__), D("\n")
#include "C:\Users\wsyear\Desktop\OI\templates\debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define gc getchar
#define pc putchar
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

template <class T = int> T read() {
  T x = 0; bool f = 0; char ch = gc();
  while (!isdigit(ch)) f = ch == '-', ch = gc();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
  return f ? -x: x;
}
template <class T> void write(T x) {
  if (x >= 0) { if (x > 9) write(x / 10); pc(x % 10 + 48); }
  else { pc('-'); if (x < -9) write(-x / 10); pc(48 - x % 10); }
}

int n;
string s, str[600];
vector<char> vec, tmp = {' ', '!', '?', ',', '.', '~', '`', '@',
                         '#', '$', '%', '^', '&', '*', '(', ')',
                         '-', '+', '=', '{', '}', '[', ']', '|',
                         '/', '\\', '\'', '"', ':', ';', '<', '>'};
map<char, int> mp;

int main() {
  freopen("result.out", "w", stdout);
  rep (i, 0, 9) vec.emplace_back(i + '0');
  rep (i, 0, 25) vec.emplace_back(i + 'A');
  for (char i : tmp) vec.emplace_back(i);
  rep (i, 0, SZ(vec) - 1) mp[vec[i]] = i;
  ifstream fin;
  fin.open("font.info");
  rep (i, 1, 543) getline(fin, str[i]);
  while (1) {
    getline(cin, s), n = s.size();
    rep (i, 0, n - 1) if (s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
    rep (i, 1, 7) {
      for (char ch : s) {
        string cur = str[8 * mp[ch] + i];
        rep (j, 1, 11) cout << cur[j];
      }
      cout << endl;
    }
    cout << endl;
  }
}