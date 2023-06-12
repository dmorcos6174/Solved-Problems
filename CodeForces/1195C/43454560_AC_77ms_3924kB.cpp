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
int n;
vii dp;

ll solve(vii& input){
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + input[0][i]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] + input[1][i]);
    }
}

void Dowork() {
    cin >> n;
    vii input(2, vi(n+1,0));
    dp = vii(2, vi(n+1,0));
    for (int i = 1; i <= n; ++i) {
        cin >> input[0][i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> input[1][i];
    }
    solve(input);
    cout << max(dp[0][n], dp[1][n]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    seive();
    int t = 1;
//    cin >> t;
    while (t--) {
        Dowork();
    }
    return 0;
}