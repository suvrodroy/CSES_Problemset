#include "bits/stdc++.h"
using namespace std;

#define int long long
#define dub long double
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef unordered_map<int,int> umap;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define endl '\n'
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e5 + 2, Mod = 1e9 + 7;
int dp[102][N];
void solve(){
    int n,m;
    cin>>n>>m;
    vint a(n);
    rep(i,0,n) {
        cin>>a[i];
        //dp[a[i]][i] ++;
    }

    if (a[0] == 0)
        rep(i,1,m+1) dp[i][0] ++;
    else dp[a[0]][0] ++;
    //cout<<dp[2][0]<<endl;
    rep(i,0,n-1){
        if (a[i] != 0){
            dp[a[i]][i+1] = (dp[a[i]][i+1] + dp[a[i]][i])%Mod;
            dp[a[i] + 1][i+1] = (dp[a[i] + 1][i+1]+ dp[a[i]][i])%Mod;
            dp[a[i] - 1][i+1] =(dp[a[i] - 1][i+1] + dp[a[i]][i])%Mod;
            continue;
        }
        rep(j,1,m+1){
            //if (dp[j][i] == 0) continue;
            //if (a[i+1] == 0 || abs(a[i+1] - j + 1) <= 1)
                dp[j-1][i+1] =(dp[j-1][i+1] + dp[j][i])%Mod;
            //if (a[i+1] == 0 || abs(a[i+1] - j) <= 1)
                dp[j][i+1] = (dp[j][i] + dp[j][i+1])%Mod;
            //if (a[i+1] == 0 || abs(a[i+1] - j - 1) <= 1)
                dp[j+1][i+1] = (dp[j][i] + dp[j+1][i+1])%Mod;
        }
    }
//    cout<< "printing dp\n";
//    rep(i,1,m+1){
//        rep(j,0,n) cout<<" "<<dp[i][j];
//        cout<<endl;
//    }
    int ans = 0;
    if (a[n-1] != 0) ans = dp[a[n-1]][n-1];
    else
        rep(i,1,m+1) ans += dp[i][n-1],ans %= Mod;
    cout<< ans <<endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,0,sizeof(dp));
    solve();

    return 0;
}