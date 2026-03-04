#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
#define ll long long
int t;
ll a, b;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
void work(){
    cin>>a>>b;
    swap(a, b);
    ll g = gcd(a, b);
    ll ans = b * (a / g);
    if(ans == a) ans *= a / b;
    cout << ans << '\n';
}
int main(){
    // ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--) work();
    return 0;
}
