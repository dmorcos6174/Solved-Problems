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

const int N = 1e5+5;
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

string s;
ll mod = 1e9 + 7;
vi dp;

void solve(){
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.length(); ++i) {
        if((s.substr(i-2, 2) == "uu") || (s.substr(i-2, 2) == "nn"))
            dp[i] = dp[i-1] + dp[i-2] % mod;
        else
            dp[i] = dp[i-1];
    }
}

void Dowork() {
    cin >> s;
    dp = vi(N);
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0;
            return;
        }
    }
    solve();
    cout << dp[s.length()] % mod;
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