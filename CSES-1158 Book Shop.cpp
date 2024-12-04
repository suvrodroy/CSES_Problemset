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
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e5 + 10;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[100002] = {0};
    int n,w;
    cin>>n>>w;
    vint wt(n),v(n);
    rep(i,0,n) cin>>wt[i];
    rep(i,0,n) cin>>v[i];
    for(int i = 0;i < n;i++){
        for(int j = w; j >= wt[i];j--){
            dp[j] = max(dp[j], dp[j - wt[i]] + v[i]);
        }
    }
    cout<<dp[w]<<endl;

    return 0;
}

/** Generic Knapsack **/
/*

int n ,w, dp[1002][N] ,a[N],v[N];
int f(int i, int amount){
    if (i<0 || amount == 0) return 0;
    if (dp[i][amount]) return dp[i][amount];
    int ans = 0;
    ans = max(ans, f(i-1,amount));
    if (amount >= a[i])ans = max(ans, f(i-1,amount - a[i]) + v[i]);
    return dp[i][amount] = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i =0 ;i<N;i++) dp[0][i] = 0;
    for(int i =0 ;i<102;i++) dp[i][0] = 0;
    cin>>n>>w;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n) cin>>v[i];
    for(int i = 1;i<=n;i++){
        for(int amount = 1;amount <= w; amount++){
            int value_0 = dp[i-1][amount];
            int value_1 = 0;
            if (amount >= a[i-1]){
                value_1 = v[i-1];
                value_1 += dp[i-1][amount - a[i-1] ];
            }
            int maxValue = max(value_0 , value_1);
            dp[i][amount] = maxValue;
        }
    }

    cout<<dp[n][w]<<endl;
    //cout<<f(n-1,w);

    return 0;
}

*/