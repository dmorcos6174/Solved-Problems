#include<bits/stdc++.h>
using namespace std;

int n; int ans; int mskans; int numTracks;
vector<int> tracks(25);

void fun(int i, int sum, int msk){
    if(sum > n)//invalid subtree/leaf
        return;
    if(i == numTracks){//maximize ans
        if (sum > ans){
            ans = sum;
            mskans = msk;
        }
        return;
    }
    fun(i+1, sum + tracks[i], msk | (1 << i));//include
    fun(i+1, sum, msk);//exclude
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(cin >> n >> numTracks){
        ans = 0; mskans = 0;
        for (int i = 0; i < numTracks; ++i) {
            cin >> tracks[i];
        }
        fun(0, 0, 0);
        for (int i = 0; i < numTracks; ++i) {
            if(mskans >> i & 1)
                cout << tracks[i] << " ";
        }
        cout << "sum:" << ans << "\n";
    }
}