#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool notprime[N + 5];
vector<int> primes;

void seive(){
    notprime[0] = notprime[1] = 1;
    for (int i = 1; i <= N/i; ++i) {
        if(notprime[i])
            continue;
        for (int j = i*i; j <= N; j+=i) {
            notprime[j] = 1;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if(!notprime[i])
            primes.push_back(i);
    }
}

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

int f(int x){
    if (!(x & 1))
        return x;
    else{
//        if(isprime(x))
//            return 0;
        if(!notprime[x])
            return 0;
        else
            return x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);// comment in case of interactive problem (endl)
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    seive();
    int x;
    cin >> x;
    vector<int> factors;
    factors = getFactors(x);
    int sum = 0;
    for (int i = 0; i < factors.size(); ++i) {
        sum += f(factors[i]);
    }
    cout << sum << "\n";
}