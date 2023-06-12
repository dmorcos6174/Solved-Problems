#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
typedef vector<ll> vi;

int x, y;
//ll ans = -1;

bool valid(double mid){
    double laptimeX = mid/x;
    double laptimeY = mid/y;
    if(abs(laptimeX - laptimeY) >= 1)
        return true;
    else
        return false;
}
//DOUBLE
const double EPS = 1e-7;
double bs(double s, double sz){
    for (int i = 0; i < 100; ++i) {
        double mid = s + ((sz - s) / 2);
        if(valid(mid))
            sz = mid;
        else
            s = mid;
    }
    return s;
}
////LAST TRUE
//ll bs(ll s, ll e) {
//    while (s <= e) {
//        ll mid = s + (e - s + 1) / 2;
//        if (valid(mid)){
//            s = mid + 1;
//            ans = mid;
//        }
//        else
//            e = mid - 1;
//    }
//    return s;
//}
////FIRST TRUE
//ll bs(ll s, ll e) {
//    while (s <= e) {
//        ll mid = (s + (e - s) / 2);
//        if (valid(mid)){
//            e = mid + 1;
//            ans = mid;
//        }
//        else
//            s = mid + 1;
//    }
//    return s;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
   while(cin >> x >> y){
       double ans = bs(1, 1e10);//number of laps at which the faster will overlap
       cout << ceil(ceil(ans) / x) << "\n";
   }
}