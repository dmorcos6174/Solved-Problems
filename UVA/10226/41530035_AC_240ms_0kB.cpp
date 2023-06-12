#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while (n--){
        map<string, int> mp;
        string word;
        auto iter = mp.begin();
        int pop = 0;
        while(getline(cin, word)){
            if(word.empty())
                break;
            iter = mp.find(word);
            if(iter == mp.end())
                mp[word] = 1;
            else
                iter->second++;
            pop++;
        }
        iter = mp.begin();
        while(iter != mp.end()){
            cout << iter->first << " " << fixed << setprecision(4) << ((double)(iter->second)/pop)*100 << "\n";
            iter++;
        }
        if(n > 0)
            cout << "\n";
    }
}