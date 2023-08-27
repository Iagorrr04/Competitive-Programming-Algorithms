/*
 * s: first term
 * d: common difference
 * n: number of terms
 */
ll arithmeticProgressionSum(ll s, ll d, ll n) {
  return (s + (s + d * (n - 1))) * n / 2ll;
}
