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

void run(){
  int n; cin >> n;
  string s; cin >> s;

  bool in = false;
  bool ans =  false;
  for(auto c : s) {
    if(c == '|') {
      if(in) in = false;
      else in = true;
    }

    if(c == '*') {
      if(in == true) {
        ans = true;
      }
    }
    
  }

  cout << (ans ? "in" : "out") << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation