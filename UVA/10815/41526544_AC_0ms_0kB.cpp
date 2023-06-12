#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
    set<string> s;
    string word;
    while (cin >> word){
        string curr = "";
        for (int i = 0; i < word.size(); ++i) {
            char ch = tolower(word[i]);
            if(ch >= 'a' && ch <= 'z')
                curr += ch;
            else if(curr != ""){
                s.insert(curr);
                curr = "";
            }
        }
        if(curr != "")
            s.insert(curr);
    }
    set<string>::iterator iter = s.begin();
    while (iter != s.end())
        cout << *iter++ << "\n";
}