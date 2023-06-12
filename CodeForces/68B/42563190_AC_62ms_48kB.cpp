#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
vector<int> a;

bool valid(double x){
    double store = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] > x)
            store += a[i] - x;
        else if(a[i] < x)
            store -= (x - a[i]) / (1.0 - ((double)k / 100.0));
    }
    if(store < 0)
        return false;
    else
        return true;
}

const double EPS = 1e-7;
double bs(double s, double sz){
    for (int i = 0; i < 100; ++i) {
        double mid = s + ((sz - s) / 2);
        if(!valid(mid))
            sz = mid;
        else
            s = mid;
    }
    return s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double ans = 0;
    ans = bs(0, 1e4);
    cout << setprecision(9) << fixed << ans << "\n";
}