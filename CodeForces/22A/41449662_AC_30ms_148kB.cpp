#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    bool flag = true;
    cin >> n;
    if(n == 1){
        flag = false;
    }
    int temp;
    set<int> s;
    set<int>::iterator iter;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        s.insert(temp);
    }
    if (s.size() == 1)
        flag = false;
    if(!flag) cout << "NO\n";
    else{
        iter = s.begin();
        iter++;
        cout << *iter << "\n";
    }
}