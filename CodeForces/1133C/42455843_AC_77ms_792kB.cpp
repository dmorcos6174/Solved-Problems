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
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
//    for (int i = 0; i < n; ++i) {
//        cout << vec[i] << " ";
//    }
    int MX = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while(j < n && vec[j] - vec[i]  <= 5){
            j++;
            MX = max(MX, j-i);
        }
    }
    cout << MX << "\n";
}