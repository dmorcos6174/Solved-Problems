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

ll n, k;
vector<pii> oxnit;
vi benefit, heights;
ll dp[15][200][1121];
ll visdp[15][200][1121];
ll vid;
const int N = 1125;
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

//ll knapsack(int i, int remainder) {
//    if (i == -1)
//        return 0;
//    ll &res = dp[i][remainder];
//    if (~res)
//        return res;
//    ll choice1 = knapsack(i - 1, remainder);
//    ll choice2 = 0;
//
//    if (remainder >= heights[i])
//        choice2 = knapsack(i - 1, remainder - heights[i]) + benefit[i];
//    return res = max(choice1, choice2);
//}

ll solve(ll i, ll ni, ll ki){
    if(ni == n && ki == k){
        return 1;
    }
    if(ni > n || ki > k || i == primes.size()){
        return 0;
    }
    ll &res = dp[ki][i][ni];
    if(visdp[ki][i][ni] == vid){
        return res;
    }
    visdp[ki][i][ni] = vid;
    return res = solve(i+1, ni, ki) + solve(i+1, ni + primes[i], ki + 1);
}

void Dowork() {
    while (cin >> n && n){
        cin >> k;
//        dp = viii(15, vii(200, vi(1121, -1)));
        vid++; // memset alternative
        ll ans = solve(0, 0, 0);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
    int c = 1;
//    cin >> c;
    while (c--) {
        Dowork();
    }
    return 0;
}