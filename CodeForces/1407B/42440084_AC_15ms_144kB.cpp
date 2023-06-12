#include <bits/stdc++.h>
using namespace std;
#define ll long long


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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        swap(a[0], a[max_element(a.begin(),a.end()) - a.begin()]);
        int ans = a[0];
        for (int i = 1; i < n - 1; ++i) {
            int c = __gcd(ans, a[i]);
            int ind = i;
            for (int j = i + 1; j < n; ++j) {
                int temp = __gcd(ans, a[j]);
                if(temp >= c){
                    c = temp;
                    ind = j;
                }
            }
            swap(a[ind], a[i]);
            ans = __gcd(ans, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            if(i < n-1)
                cout << a[i] << " ";
            else
                cout << a[i];
        }
        cout << "\n";
    }
}