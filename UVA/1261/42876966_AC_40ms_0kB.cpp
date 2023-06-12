#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long ull;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<ll>> vii;
typedef vector<vector<bool>> vbb;
typedef vector<vector<char>> vcc;

map<string, bool> vis;

bool dfs(string s) {
    if(s.empty())
        return true;
    if(vis[s])
        return false;
    int i = 0, j = 1;
    bool res = false;
    while (i < s.size() && j < s.size()){
        while(s[i] == s[j] && j < s.size())
            j++;
        if(j - i > 1){
            res = dfs(s.substr(0, i) + s.substr(j));
            if(res)
                return res;
        }
        i = j;
        j++;
    }
    vis[s] = true;
    return res;
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
    while (t--) {
        string s;
        cin >> s;
        if(dfs(s))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
        vis = map<string, bool>();
    }
}