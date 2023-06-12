#include<bits/stdc++.h>
using namespace std;

vector<int> getFactors(int n){
    vector<int> ret;
    for(int i=2; i<=n/i; i++){
        while(n % i == 0){
            ret.push_back(i);
            n /= i;
        }
    }
    if(n != 1){
        ret.push_back(n);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    seive();
    int n;
    while(cin >> n && n){
        vector<int> factors;
        factors = getFactors(n);
        sort(factors.begin(), factors.end());
        cout << factors[0] << "\n";
    }
}