#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> ps(n+1,0);
        map<int,int> m;
        for(int i = 1; i <= n ;i++)ps[i] = ps[i-1] + (s[i-1] - '0') - 1,m[ps[i]]++;
        int acu = 0;
        ll ans = 0;
        for(int i = 0 ; i < n;i++){
                ans += m[acu];
                m[ps[i+1]]--;
                acu += (s[i] - '0') - 1;
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--) so();
        return 0;
}
