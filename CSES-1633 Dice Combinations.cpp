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
ll ff(ll sum){
    if (sum == 0) return 1;
    if (dp[sum] != -1) return dp[sum];
    ll ways = 0;
    for(int i = 1;i<=6;i++){
        if (sum - i >= 0)
            ways = ( ways%mod + ff(sum-i)%mod)%mod;
    }
    return dp[sum] = ways%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    ll n, x;
    cin >> x;
    cout << ff(x) << endl;
    return 0;
}