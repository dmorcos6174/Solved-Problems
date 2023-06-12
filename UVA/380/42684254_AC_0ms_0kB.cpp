#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
typedef vector<ll> vi;

map<string, vector<tuple<string, int, int>>> mp;

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

string recurse(string source, string ext, int time){
    if(ext != "" && mp[ext].size() == 0)
        return ext;
    if(source == ext)
        return "9999";
    if(ext == "")
        ext = source;
    for (int i = 0; i < mp[ext].size(); ++i) {
        if(time >= get<1>(mp[ext][i]) && time <= get<2>(mp[ext][i]))
            return recurse(source, get<0>(mp[ext][i]), time);
    }
    return ext;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cout << "CALL FORWARDING OUTPUT\n";
    int test = 1;
    int N;
    cin >> N;
    while (N--){
        string source, target;
        int time, duration;
        while(cin >> source && source != "0000"){
            cin >> time >> duration >> target;
            mp[source].push_back({target, time, time + duration});
        }
        string ctime, tobecalled;
        cout << "SYSTEM " << test++ << "\n";
        while(cin >> ctime && ctime != "9000"){
            cin >> tobecalled;
            string dest = recurse(tobecalled, "", stoi(ctime));
            cout << "AT " << ctime << " CALL TO " << tobecalled << " RINGS " << dest << "\n";
        }
        mp.clear();
    }
    cout << "END OF OUTPUT\n";
}
