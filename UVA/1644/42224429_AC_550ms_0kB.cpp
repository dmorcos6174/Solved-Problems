#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7;
bool notprime[N + 5];
vector<int> primes;
void seive(){
    notprime[0] = notprime[1] = 1;
    for(int i=1; i<=N/i; i++){
        if(notprime[i])
            continue;
        for(int j=i*i; j<=N; j+=i)
            notprime[j] = 1;
    }
    for(int i=2; i<=N; i++)
        if(!notprime[i])
            primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    seive();
//    cout << primes[primes.size()-1] << "\n";
    int k;
    while(cin >> k && k){
        bool flag = false;
        int n = 0;
        for (int i = 0; i < primes.size()-1; ++i) {
            if(primes[i] < k && k < primes[i+1]){
                flag = true;
                n = primes[i+1] - primes[i];
            }
        }
        cout << n << "\n";
    }
}