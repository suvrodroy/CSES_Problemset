#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef vector<string> vstr;
typedef pair<int, int> pint;
#define rep(i, j, k) for(int i=j;i<k;i++)
#define endl '\n'
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const ll N = 1000005, mod = 1e9 + 7;
ll dp[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ll n, x;
    cin >> n >> x;
    vll v(n);
    rep(i, 0, n) cin >> v[i];
    for (auto coin: v) {
        for (ll i = coin; i <= x; i++) {
            dp[i]  = (dp[i]%mod + dp[i - coin]%mod)%mod;
        }
    }
    cout << dp[x] << endl;
    return 0;
}