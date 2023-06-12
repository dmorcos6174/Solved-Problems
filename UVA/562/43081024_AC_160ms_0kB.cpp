#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ll>> vii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;
typedef pair<ll , ll > pii;

int m, sum;
vi coins;
vii dp;

ll solve(int i, int s){
    if(i == m){
        return abs(sum - s - s);
    }
    ll &ret = dp[i][s];
    if(~ret)
        return ret;
    return ret = min(solve(i+1, s), solve(i+1, s+coins[i]));
}

void Dowork(){
    cin >> m;
    sum = 0;
    coins = vi(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
        sum += coins[i];
    }
    dp = vii(m, vi(sum + 1, -1));
    ll ans = solve(0, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while(t--){
        Dowork();
    }
    return 0;
}