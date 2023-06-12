#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n = 0;
    int diff = 0;
    while(cin >> n){
        int arr[n];
        vector<bool> found(3000);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n-1; ++i) {
            diff = abs(arr[i] - arr[i+1]);
            if (diff > n-1){
                continue;
            }
            else{
                found[diff] = true;
            }
        }
        bool jolly = true;
        for (int i = 1; i < n; ++i) {
            if (found[i] == false){
                jolly = false;
            }
        }
        if (jolly) cout << "Jolly\n";
        else cout<< "Not jolly\n";
    }
}