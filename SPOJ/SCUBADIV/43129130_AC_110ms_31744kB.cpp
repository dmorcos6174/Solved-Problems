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
typedef pair<ll, ll> pii;

ll t, a, n;
vector<pii> oxnit;
vi benefit, weights;
vector<vector<vector<ll>>> dp;

//ll knapsack(int i, int remainder) {
//    if (i == -1)
//        return 0;
//    ll &res = dp[i][remainder];
//    if (~res)
//        return res;
//    ll choice1 = knapsack(i - 1, remainder);
//    ll choice2 = 0;
//
//    if (remainder >= weights[i])
//        choice2 = knapsack(i - 1, remainder - weights[i]) + benefit[i];
//    return res = max(choice1, choice2);
//}

ll mn;

ll solve(ll i, ll ti, ll ai) {
    if (i == n){
        if (ti >= t && ai >= a) {
            return 0;
        }
        return INT_MAX;
    }
    ll &res = dp[ti][ai][i];
    if(~res)
        return res;
    res = solve(i + 1, ti, ai);
    return res = min(res, solve(i + 1, min(t, ti + oxnit[i].first), min(a, ai + oxnit[i].second)) + weights[i]);
}

void Dowork() {
    mn = INT_MAX;
    cin >> t >> a >> n;
    oxnit = vector<pii>(n);
    weights = vi(n);
    dp = vector<vector<vector<ll>>>(22, vector<vector<ll>>(80, vector<ll>(1001, -1)));
    for (int i = 0; i < n; ++i) {
        cin >> oxnit[i].first;
        cin >> oxnit[i].second;
        cin >> weights[i];
    }
    mn = solve(0, 0, 0);
    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int c = 1;
    cin >> c;
    while (c--) {
        Dowork();
    }
    return 0;
}