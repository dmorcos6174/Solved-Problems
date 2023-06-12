#include<bits/stdc++.h>
using namespace std;
 
vector<int> a, b;
 
int bs(int s, int e, int value) {
    while (s < e) {
        int mid = s + (e - s + 1) / 2;
        if (a[mid] <= value) s = mid;
        else e = mid - 1;
    }
    if(s == 0){
        if(a[s] <= value)
            return s;
        else
            return -1;
    }
    else
        return s;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        if(i < m - 1)
            cout << bs(0, n-1, b[i]) + 1<< " ";
        else
            cout << bs(0, n-1, b[i]) + 1;
 
    }
}