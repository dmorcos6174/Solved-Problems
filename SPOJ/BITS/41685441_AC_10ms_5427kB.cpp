#include<bits/stdc++.h>
using namespace std;

int popCount(int num){
    int res = 0;
    while (num > 0){
        res += num &1;
        num >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n; int count = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            count += popCount(i);
        }
        cout << count << "\n";
    }
}