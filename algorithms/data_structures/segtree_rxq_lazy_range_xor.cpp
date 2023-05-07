// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

struct SegTree {
  int N;
  std::vector<ll> ns, lazy;

  SegTree(const std::vector<ll> &xs)
      : N(xs.size()), ns(4 * N, 0), lazy(4 * N, 0) {
    for (size_t i = 0; i < xs.size(); ++i)
      update(i, i, xs[i]);
  }

  void update(int a, int b, ll value) { update(1, 0, N - 1, a, b, value); }

  void update(int node, int L, int R, int a, int b, ll value) {
    // Lazy propagation
    if (lazy[node]) {
      ns[node] ^= lazy[node];

      if (L < R) // Se o nó não é uma folha, propaga
      {
        lazy[2 * node] ^= lazy[node];
        lazy[2 * node + 1] ^= lazy[node];
      }

      lazy[node] = 0;
    }

    // [a, b] ∩ [L, R] = {∅}
    if (a > R or b < L)
      return;

    // [L, R] ⊂ [a, b] está contido; é subconjunto de
    if (a <= L and R <= b) {
      ns[node] ^= value;

      if (L < R) {
        lazy[2 * node] ^= value;
        lazy[2 * node + 1] ^= value;
      }

      return;
    }

    update(2 * node, L, (L + R) / 2, a, b, value);
    update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);

    ns[node] = ns[2 * node] ^ ns[2 * node + 1];
  }

  ll RSQ(int a, int b) { return RSQ(1, 0, N - 1, a, b); }

  ll RSQ(int node, int L, int R, int a, int b) {
    if (lazy[node]) {
      ns[node]  ^= lazy[node];

      if (L < R) {
        lazy[2 * node] ^= lazy[node];
        lazy[2 * node + 1] ^= lazy[node];
      }

      lazy[node] = 0;
    }

    if (a > R or b < L)
      return 0;

    if (a <= L and R <= b)
      return ns[node];

    ll x = RSQ(2 * node, L, (L + R) / 2, a, b);
    ll y = RSQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);

    return x ^ y;
  }
};


int main(){

}
