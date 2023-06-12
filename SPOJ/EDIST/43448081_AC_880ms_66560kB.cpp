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

//const int N = 1125;
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
vii dp;
ll solve(string& a, string& b, ll m, ll n){
    if(m == 0)
        return n;
    if (n == 0)
        return m;
    ll &res = dp[m][n];
    if(~res)
        return res;
    if(a[m-1] == b[n-1])
        return res = solve(a, b, m-1, n-1);
    return res =  1 + min({solve(a, b, m-1, n), solve(a, b, m, n-1), solve(a, b, m-1, n-1)});
}

void Dowork() {
    string a, b;
    cin >> a >> b;
    dp = vii(a.size() + 1, vi(b.size() + 1, -1));
    cout << solve(a, b, a.size(), b.size()) << "\n";
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
    cin >> t;
    while (t--) {
        Dowork();
    }
    return 0;
}