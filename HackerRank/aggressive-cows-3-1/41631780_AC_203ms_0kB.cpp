#include <bits/stdc++.h>
using namespace std;

int n, cows;
int loc[100005];

bool valid(int dist){
    int prev = 0; int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (loc[i] - loc[prev] >= dist){
            cnt++;
            prev = i;
        }
    }
    return cnt >= cows;
}

int bs(int s, int e) {
    while (s < e){
        int mid = s + (e - s +1)/2;
        if (valid(mid))
            s = mid;
        else
            e = mid - 1;
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
        cin >> n >> cows;
        for(int i=0; i<n; i++){
            cin >> loc[i];
        }
        sort(loc, loc + n);
        cout << bs(1, 1000000000) << endl;
    }
}