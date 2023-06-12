#include <bits/stdc++.h>
using namespace std;

vector<int> carSpeeds;

int bs(int q, int n){
    int s = 0; int e = n;
    while(s < e){
        int mid = s + (e-s)/2;
        if(carSpeeds[mid] > q)
            e = mid;
        else
            s = mid + 1;
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        carSpeeds = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> carSpeeds[i];
        }
        sort(carSpeeds.begin(), carSpeeds.end());
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            long long q;
            cin >> q;
            if(i < m -1){
//                if (bs(q, n) == n && carSpeeds)
//                    if (carSpeeds[n-1] > q)
//
//                else
                cout << n - bs(q, n) << " ";
            }
            else
                cout << n - bs(q, n)  << "\n";
        }
    }
}