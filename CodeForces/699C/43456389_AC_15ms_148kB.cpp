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
vi days;
vii dp;

ll solve(int i, int lastAct){
    if(i == n)
        return 0;
    ll &res = dp[i][lastAct];
    if(~res)
        return res;
    if(days[i] == 0){
        res = solve(i+1, 0) + 1;
    }
    else if(days[i] == 1){//either rest or contest
        if(lastAct == days[i]){
            res = solve(i+1, 0) + 1;
        }
        else{
            res = solve(i+1, 1);
        }
    }
    else if(days[i] == 2){//either rest or gym
        if (lastAct == days[i]){
            res = solve(i+1, 0) + 1;
        }
        else{
            res  = solve(i+1, 2);
        }
    }
    else if (days[i] == 3){
        //res = min(solve(i+1, 1), solve(i+1, 2)); //not efficient, as it traverses unnecessary routes
        int choice1 = lastAct == 1 ? INT_MAX : solve(i+1, 1);
        int choice2 = lastAct == 2 ? INT_MAX : solve(i+1, 2);
        int choice3 = solve(i+1, 0) + 1;
        res = min({choice1, choice2, choice3});
    }
    return res;
}

void Dowork() {
    cin >> n;
    days = vi(n);
    dp = vii(n + 5, vi(3,-1));
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }
    cout << solve(0, 0);
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