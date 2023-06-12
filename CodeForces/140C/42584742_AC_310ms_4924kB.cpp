#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<int> r;
map<int, int> mp;

bool valid(int x){
    ll res = 0;
    for (auto it : mp){
        res += min(x, it.second);
    }
    if(res/3 >= x)
        return true;
    else
        return false;
}

int bs(int s, int e) {
    while (s < e) {
        int mid = s + (e - s + 1) / 2;
        if (valid(mid)) s = mid;
        else e = mid - 1;
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
    cin >> n;
    r = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        mp[r[i]]++;
    }
    int ans = 0;
    ans = bs(0, 1e7);
    cout << ans << "\n";
    int balls = ans * 3;
    vector<vector<int>> snowmen(ans);
    int j = 0;
    for (auto it : mp){
        for (int i = 0; i < min(ans, it.second) && balls > 0; ++i) {
            while (snowmen[j % ans].size() > 2)
                j++;
            snowmen[j % ans].push_back(it.first);
            j++;
            balls--;
        }
        if(balls == 0)
            break;
    }
    for (int i = 0; i < snowmen.size(); ++i) {
        for (int j = 2; j >= 0 ; --j) {
            cout << snowmen[i][j] << " ";
        }
        cout << "\n";
    }
}