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

void Dowork() {
    int n;
    cin >> n;
    vii web(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int point;
            cin >> point;
            web[i].push_back(point);
        }
        sort(web[i].begin(), web[i].end());
    }
    int ans = 0, p1 = 0, p2 = 0, p3 = 0;
    for (int i = 0; i < n; ++i) {
        while(p1 < web[i].size()-1){
            int lower = web[i][p1];
            int upper = web[i][p1+1];
            int preIntersect = 0;
            int postIntersect = 0;

            while(p2 < web[(i-1 + n) % n].size()){
                if(web[(i-1 + n) % n][p2] < lower){
                    p2++;
                }
                else if(web[(i-1 + n) % n][p2] > lower && web[(i-1 + n) % n][p2] < upper){
                    preIntersect++;
                    p2++;
                }
                else{
                    break;
                }
            }

            while(p3 < web[(i+1) % n].size()){
                if(web[(i+1) % n][p3] < lower){
                    p3++;
                }
                else if(web[(i+1) % n][p3] > lower && web[(i+1) % n][p3] < upper){
                    postIntersect++;
                    p3++;
                }
                else{
                    break;
                }
            }
            if (preIntersect != postIntersect){
                ans++;
            }
            p1++;
        }
        p1 = 0;
        p2 = 0;
        p3 = 0;
    }
    cout << ans;
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
//    cin >> c;
    while (t--) {
        Dowork();
    }
    return 0;
}