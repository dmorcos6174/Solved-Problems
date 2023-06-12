#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;
const double PI = 3.14159265359;
double pies[1000005];
int n, frnds = 0;

bool valid(double vol){
    int pieces = 0;
    for (int i = 0; i < n; ++i) {
        pieces += pies[i]*pies[i]*PI/vol;
    }
    return pieces >= frnds + 1;
}

double bs(double s, double sz){
    while(sz > EPS){
        if(valid(s + sz/2))
            s += sz/2;
        sz/=2;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> frnds;
        double sz = 0;
        for(int i=0; i<n; i++){
            cin >> pies[i];
            sz = max(sz, pies[i]*pies[i]*PI);
        }
        cout << fixed << setprecision(5) << bs(0, sz) << endl;
    }
}