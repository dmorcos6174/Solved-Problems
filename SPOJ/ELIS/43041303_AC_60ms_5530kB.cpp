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

int n;
vi input;
vi dp;

ll recur(int i){
    if (i == n)
        return 0;
    ll &res = dp[i];
    if(~res)//if calculated, prune
        return res;
    res = 1;
    for (int j = i+1; j < n; ++j) {
        if(input[j] > input[i])
            res = max(res, 1 + recur(j));
    }
    return res;
}

void Dowork(){
    cin >> n;
    input = vi(n);
    dp = vi(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    ll res = INT_MIN;
    for (int i = 0; i < n; ++i) {
        res = max(res, recur(i));
    }
    cout << res;
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