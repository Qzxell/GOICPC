#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i = 1;i <= (int)sqrt(n);i++)v.push_back(i);

    for(int i = (int)v.size() - 1;i>=0;i--){
        if(n/v[i] == v[i])continue;
        v.push_back(n/v[i]);
    }
    cout << (int)v.size() << '\n';
    for(auto x : v)cout  << x << ' ';
    return 0;
}
