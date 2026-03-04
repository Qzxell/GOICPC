#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        int n;
        cin >> n;
        vector<int> v(n+n);
        vector<ll> ps(n+n+1),in(n+n+1);
        for(auto &x:v)cin >> x;
        for(int i = 1; i <= n+n ; i++){
                ps[i] = ps[i-1] + v[i-1];
                in[i] = in[i-1] + (i&1?v[i-1] : -v[i-1]);
        }
        for(int i = 1; i <= n ;i++){
                ll owo = in[n+n-i] - in[i];
                ll ans = -ps[i] + (ps[n+n] - ps[n+n-i]) + (i&1 ? -owo: owo);
                cout << ans << ' ';
        }
        cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
