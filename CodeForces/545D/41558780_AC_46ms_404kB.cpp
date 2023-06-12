#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;int temp;
    cin >> n;
    int count = 0;int time=0;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; ++i) {
        if(time <= vec[i]){
            time += vec[i];
            count++;
        }
    }
    cout << count << "\n";
}