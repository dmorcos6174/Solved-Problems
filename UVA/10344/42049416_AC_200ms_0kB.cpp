#include<bits/stdc++.h>
using namespace std;

vector<int> vec(5);

bool fun(int sum, int msk){
    if (msk == (1<< 5) -1){
        if (sum == 23)
            return true;
        else
            return false;
    }
    for (int i = 0; i < 5; ++i) {
        if(!(msk & (1 << i))){
            int newmsk = msk | (1 << i);
            if(fun(sum + vec[i], newmsk))
                return true;
            if(msk != 0){
                if(fun(sum - vec[i], newmsk))
                    return true;
                if(fun(sum * vec[i], newmsk))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);//comment in case of interactive problem (endl)
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(cin >> vec[0] && vec[0]){
        for (int i = 1; i < 5; ++i) {
            cin >> vec[i];
        }
        if(fun(0, 0)){
            cout << "Possible\n";
        }
        else
            cout << "Impossible\n";

    }
}