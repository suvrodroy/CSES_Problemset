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
#define all(a) a.begin(),a.end()
#define endl '\n'
#define INF 2147483647
//#define INF 9223372036854775807
#define null '\0'
const int N = 1e5 + 10, Mod = 1e9 + 7;
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};
char dir[] = {'R','L','U','D'};
void solve(){
    int n,m;
    cin >> n >> m;
    char g[n][m],v[n][n];
    deque <pii> q;
    rep(i,0,n) {
        rep(j,0,m){
            cin >> g[i][j];
            if (g[i][j] == 'A') q.push_back({i,j});
            if (g[i][j] == 'M') q.push_front({i,j});
        }
    }
    while(!q.empty()){
        //cout <<'g';
        int r = q.front().first, c = q.front().second;
        q.pop_front();
        rep(i,0,4) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (rr >= n || rr < 0 || cc >= m || cc < 0) continue;
            if(g[rr][cc] == '.') {
                //cout <<'f';
                q.push_back({rr,cc});
                if(g[r][c] == 'M') g[rr][cc] = 'M';
                else g[rr][cc] = dir[i];
            }
        }
    }
//    cout << endl;
//    rep(i,0,n){
//        rep(j,0,m) cout << g[i][j];
//        cout << endl;
//    }
//    cout << "\n\n";
    bool yes = false;
    pii pos;
    rep(i,0,n) {
        if(isalpha(g[i][0]) && g[i][0] != 'M') {
            yes = true;
            pos = {i,0};
            break;
        }
        if(isalpha(g[i][m-1]) && g[i][m-1] != 'M') {
            yes = true;
            pos = {i,m-1};
            break;
        }
    }
    rep(i,0,m) {
        if (yes) break;
        if(isalpha(g[0][i]) && g[0][i] != 'M') {
            yes = true;
            pos = {0,i};
            break;
        }
        if(isalpha(g[n-1][i]) && g[n-1][i] != 'M') {
            yes = true;
            pos = {n-1,i};
            break;
        }
    }
    if (!yes) {
        cout << "NO\n";
        return;
    }
    cout <<"YES\n";
    string ans;
    int r = pos.first, c = pos.second;
    while(g[r][c] != 'A') {
        ans.push_back(g[r][c]);
        if (g[r][c] == 'R') c--;
        else if (g[r][c] == 'L') c++;
        else if (g[r][c] == 'U') r++;
        else r--;
    }
    cout << ans.size() << endl;
    for(auto it = ans.rbegin();it != ans.rend();++it) cout <<*it;
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_n = 1;
    //cin>>test_n;
    for(int t_c = 1;t_c <= test_n;t_c ++){
        solve();
    }

    return 0;
}