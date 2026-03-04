#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int fp(int b,int e){
        ll ret = 1;
        while(e){
                if(e&1){
                        ret = ret * b%mod;
                }
                e >>= 1;
                b = b*1ll*b%mod;
        }
        return ret;
}

int inv(int nu){
        return fp(nu,mod-2);
}

const int N = 1e4 + 4;
int fac[N];

void init(){
        fac[0] =1;
        for(int i = 1; i < N ; i++)
                fac[i] = fac[i-1]*1ll*i%mod;
}

int co(int n, int k){
        return ((fac[n]*1ll*inv(fac[n-k])%mod)*1ll*inv(fac[k]))%mod;
}

void so(){
        int n,k;
        cin >> n >> k;
        vector<int> v(n),m(n+1,0);
        map<int,int> m_;
        for(int i = 0 ; i < n ; i++){
                cin >> v[i];
                m[v[i]]++;
        }
        sort(v.rbegin(),v.rend());
        for(int i = 0 ; i < k ; i++)
                m_[v[i]]++;
        int ans = 1;
        for(auto [a,b] : m_){
                ans = (ans*1ll*co(m[a],b))%mod;
        }
        cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        init();
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
