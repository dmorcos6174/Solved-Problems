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

int n, k;
vi benefit, weight;
vii dp;

ll knapsack(int i, int curr){
    if(i == n)
        return 0;
    ll &res = dp[i][curr];
    if(~res)
        return res;
    ll choice1 = knapsack(i+1, curr);
    ll choice2 = 0;

    if(curr + weight[i] <= k)
        choice2 = knapsack(i+1, curr + weight[i]) + (benefit[i] - weight[i]);
    return res = max(choice1, choice2);
}

void Dowork() {
    cin >> n >> k;
    benefit = vi(n);
    weight = vi(n);
    dp = vii(n, vi(k+1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> benefit[i];
    }
    ll ans = knapsack(0, 0);
    cout << ans << "\n";
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
    cin >> tt;
    while (tt--) {
        Dowork();
    }
    return 0;
}