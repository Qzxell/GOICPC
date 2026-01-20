#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        int n,m,nu;
        cin >> n >> m;
        vector<int> M(m,0),M_(m,0),v(n);
        bool ok = 1;
        for(int &i : v){
                cin >> i;
                M_[i%m]++;
                if(M_[i%m] > 1){
                        ok = 0;
                }
        }
        if(!ok){
                cout << 0 << '\n';
                return;
        }
        sort(v.rbegin(),v.rend());

        auto mul = [&](int a, int b) -> int{
                return a*1ll*b%m;
        };
        auto fp = [&](int b, int e) -> int{
                ll ret = 1;
                while(e){
                        if(e&1){
                                ret = ret*b%m;
                        }
                        e >>= 1;
                        b = b*b%m;
                }
                return ret;
        };

        for(int i = 0 ; i < n ;i++)v[i] = v[i]%m;

        int ans = 1;
        for(int i = 0 ; i < n ;i++){
                for(int j = 0 ; j < m ;j++){
                        nu = (j-v[i] +m)%m;
                        ans = mul(ans,fp(nu,M[j]));
                }
                M[v[i]]++;
                //cout << ans << ' ';
        }
        //cout << '\n';
        cout << ans << '\n';
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        //cin >> tt;
        while(tt--)so();
        return 0;
}
