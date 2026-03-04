#include<bits/stdc++.h>

using namespace std;

#define ll long long

void so(){
        int n;
        cin >> n;
        vector<int> v(n);

        ll ans = 0;
        for(auto &x : v)cin >> x,ans += x;
        ans = ans - v[n-1] + n + n;

        ll ma = 0,acu = 0;
        ll dp_p[n],dp_s[n];
        dp_p[0] = 0;
        dp_s[n-1] = 0;
        for(int i = 0 ; i < n-1;i++){
                acu +=(v[i] - 2*(i+1));
                dp_p[i+1] = max(acu,dp_p[i]);
        }
        ma = acu = 0;
        for(int i = n-1; i > 0; i--){
                acu += (v[i] - 2*(i+1));
                dp_s[i-1] = max(acu,dp_s[i]);
        }
        ll tot = (1+n)*1ll*n;
        for(int i = 0 ; i < n ; i++){
                ans = max(ans,dp_p[i] + dp_s[i] + tot);
        }
        cout << ans << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
