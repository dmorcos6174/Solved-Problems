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
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        vector<int> correct_leaked;
        vector<int> incorrect_unleaked;
        int count = 0;

        for (int i = 0; i < q; ++i) {
            int d, s;
            char r;
            cin >> d >> s >> r;
            if(r == 'c' && s == 1)
                correct_leaked.push_back(d);
            else if(r == 'i' && s == 0)
                incorrect_unleaked.push_back(d);
        }
        sort(correct_leaked.begin(), correct_leaked.end());
        sort(incorrect_unleaked.begin(), incorrect_unleaked.end());
        for (int i = 0; i < correct_leaked.size(); ++i) {
            auto lower = lower_bound(incorrect_unleaked.begin(), incorrect_unleaked.end(), correct_leaked[i]);
            count += lower - incorrect_unleaked.begin();
        }
        cout << count << "\n";
    }
}