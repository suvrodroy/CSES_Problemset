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
const int N = 1e3 + 2,mod = 1e9 + 7;
char g[N][N];
int n;
ll dp[N][N];
bool isValid(int x, int y){
    if (x >=0 && x < n && y >= 0 && y < n &&  g[x][y] != '*') return true;
    return false;
}
ll f(int x , int y){
    if (x == 0 && y == 0){
        if (g[x][y] == '*') return 0;
        return 1;
    }
    if (dp[x][y] != -1) return dp[x][y];
    ll ways = 0;
    if (isValid(x-1,y))
        ways = (ways%mod + f(x-1,y)%mod)%mod ;
    if (isValid(x,y-1))
        ways = (ways%mod + f(x,y-1)%mod)%mod ;
    return dp[x][y] = ways;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    rep(i,0,n){
        rep(j,0,n){
            cin>>g[i][j];
        }
    }
    if (g[n-1][n-1] == '*') cout<<0<<endl;
    else cout<<f(n-1,n-1)<<endl;

    return 0;
}