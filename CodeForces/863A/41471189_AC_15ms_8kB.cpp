#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    for (int i = 0; i < s.size()/2; ++i) {
        if(s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("word.in", "r", stdin);
//    freopen("word.out", "w", stdout);
    int n;
    bool flag = false;
    bool quasi = false;
    cin >> n;
    string s = to_string(n);
    if(isPalindrome(s)){
        quasi = true;
    }
    else{
        while(!flag){
            if(s[s.size()-1] == '0')
               s.pop_back();
            else{
                flag = true;
            }
        }
        if(isPalindrome(s))
            quasi = true;
    }
    if(quasi) cout << "YES\n";
    else cout << "NO\n";
}