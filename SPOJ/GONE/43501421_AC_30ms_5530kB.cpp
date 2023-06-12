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

const int N = 1000;
bool notprime[N + 5];
vector<int> primes;
void seive(){
    notprime[0] = notprime[1] = 1;
    for(int i=1; i<=N/i; i++){
        if(notprime[i])
            continue;
        for(int j=i*i; j<=N; j+=i)
            notprime[j] = 1;
    }
    for(int i=2; i<=N; i++)
        if(!notprime[i])
            primes.push_back(i);
}

string l, r;
ll dp[10][2][2][1000];

ll solve(int i = 0, bool LB = true, bool UB = true, int curr = 0){
    if(i == l.size())
        return !notprime[curr];
    ll &res = dp[i][LB][UB][curr];
    if(~res)
        return res;
    int s = LB ? l[i] - '0' : 0;
    int e = UB ? r[i] - '0' : 9;
    res = 0;
    for (int d = s; d <= e; ++d) {
        res += solve(i+1, LB && (d == s), UB && (d == e), curr + d);
    }
    return res;
}

void Dowork() {
    cin >> l >> r;
    l = string(r.size() - l.size(), '0') + l;
    memset(dp, -1, sizeof dp);
    cout << solve() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
    int tt = 1;
    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}