#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define endl '\n'
#define INF 214748364
//#define INF 9223372036854775807
#define null '\0'
const ll N = 1e6 + 10,mod = 1e9 + 7;
ll dp[1000010];
ll f(ll amount, vector<ll>& coin){
    if (amount == 0) return 1;
    if (dp[amount] != -1 ) return dp[amount] ;
    ll ways = 0;
    for(auto i : coin){
        if (amount - i >= 0){
            ways = (ways % mod + f(amount - i, coin) % mod) % mod;
        }
    }
    return dp[amount] = ways%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    ll n,x;
    cin>>n>>x;
    vll v(n);
    rep(i,0,n) cin>>v[i];
    ll ans = f(x,v);
    if (ans < 0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}