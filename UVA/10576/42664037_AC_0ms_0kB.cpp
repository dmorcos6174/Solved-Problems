#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
typedef vector<ll> vi;

int s, d;
vector<int> mreport;

//ll ans = -1;
//bool valid(double mid){
//    double laptimeX = mid/x;
//    double laptimeY = mid/y;
//    if(abs(laptimeX - laptimeY) >= 1)
//        return true;
//    else
//        return false;
//}
//DOUBLE
//const double EPS = 1e-7;
//double bs(double s, double sz){
//    for (int i = 0; i < 100; ++i) {
//        double mid = s + ((sz - s) / 2);
//        if(valid(mid))
//            sz = mid;
//        else
//            s = mid;
//    }
//    return s;
//}
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

bool valid(int m){
    int posting = 0;
    for (int i = m; i > m-5; --i) {
        posting += mreport[i];
    }
    if(posting < 0)//if posting indicates deficit
        return true;
    else
        return false;
}

int recurse(int m){
    if(m == 12){
        int ans = 0;
        for (int i = 0; i < mreport.size(); ++i) {
            ans += mreport[i];
        }
        return ans;
    }
    int ans = -2e9;
    mreport.push_back(s);
    if(m < 4 || valid(m)){
        ans = max(ans, recurse(m+1));
    }
    mreport.pop_back();
    mreport.push_back(-d);
    if(m < 4 || valid(m)){
        ans = max(ans, recurse(m+1));
    }
    mreport.pop_back();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(cin >> s >> d){
        int ans = recurse(0);
        if(ans >= 0)
            cout << ans << "\n";
        else
            cout << "Deficit\n";
        mreport.clear();
    }
}