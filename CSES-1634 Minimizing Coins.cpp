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
const int N = 1e6 + 10;
ll dp[N],n,x;
vll coin;
ll f(int amount){
    if (amount == 0) return 0;
    if (dp[amount] != -1 ) return dp[amount] ;
    ll ans = INF;
    for(auto i : coin){
        if (amount - i >= 0){
            ans = min(ans, f(amount - i)+1);
        }
    }
    return dp[amount] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin>>n>>x;
    vll v(n);
    rep(i,0,n) cin>>v[i];
    coin = v;
    int ans = f(x);
    if (ans >= INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}