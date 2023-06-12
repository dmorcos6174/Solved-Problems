#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ll>> vii;
typedef vector<vector<vector<ll>>> viii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;
typedef pair<ll, ll> pii;

const int N = 1e6+5;
//bool notprime[N + 5];
//vector<int> primes;
//void seive(){
//    notprime[0] = notprime[1] = 1;
//    for(int i=1; i<=N/i; i++){
//        if(notprime[i])
//            continue;
//        for(int j=i*i; j<=N; j+=i)
//            notprime[j] = 1;
//    }
//    for(int i=2; i<=N; i++)
//        if(!notprime[i])
//            primes.push_back(i);
//}

int n;
vi input, dp;

ll solve(int idx){
    ll &res = dp[idx];
    if(~res)
        return res;
    res = 1;
    for (int i = 0; i < idx; ++i) {
        if(input[i] < input[idx])
            res = max(res, 1 + solve(i));
    }
    return res;
}

void Dowork() {
    cin >> n;
    input = vi(n);
    dp = vi(n+1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        res = max(res, solve(i));
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
//    seive();
    int tt = 1;
//    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}