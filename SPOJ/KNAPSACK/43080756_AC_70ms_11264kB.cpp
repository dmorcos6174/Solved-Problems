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

int s, n;
vi benefit, weight;
vii dp;

ll knapsack(int i, int remainder){
    if(i == -1)
        return 0;
    ll &res = dp[i][remainder];
    if(~res)
        return res;
    ll choice1 = knapsack(i-1, remainder);
    ll choice2 = 0;

    if(remainder >= weight[i])
        choice2 = knapsack(i-1, remainder - weight[i]) + benefit[i];
    return res = max(choice1, choice2);
}

void Dowork(){
    cin >> s >> n;
    benefit = vi(n);
    weight = vi(n);
    dp = vii(n, vi(s+1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> benefit[i];
    }
    ll ans = knapsack(n-1, s);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while(t--){
        Dowork();
    }
    return 0;
}