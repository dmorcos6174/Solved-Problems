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
    int n, x;
    cin >> n >> x;
    int res = 0;
    set<int> s;
    if(n == 1){
        cout << "YES\n" << x;
        return 0;
    }
    int N = 1e6;
    for (int i = 0; i < n - 2; ++i){
        res ^= N - i;
        s.insert(N - i);
    }
    for (int i = N - s.size(); i >= 0 ; --i) {//0 inclusive
        int temp = res ^ i ^ x;
        if(temp < N - s.size()){//check if nth element not already in set
            s.insert(i);
            s.insert(temp);
            break;
        }
    }
    if(s.size() == n){
        cout << "YES\n";
        auto iter = s.begin();
        while (iter != s.end())
            cout << *iter++ << " ";
    }
    else
        cout << "NO\n";
}