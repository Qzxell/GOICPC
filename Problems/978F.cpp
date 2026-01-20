#include<bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
void so(){
        int n,k,x,u,b,nu,nv;
        cin >> n >> k;
        vector<ii> v(n);
        vector<int> f(n+1);
        vector<int> f_(n+1);
        vector<int> ans(n+1,0);
        for(int id = 0 ; id < n ;id++){
                cin >> x;
                v[id] = {x,id};
        }
        sort(v.rbegin(),v.rend());
        int lo,lf,mid;
        for(int i = 0 ; i < n ;i++){
                auto [x,id] = v[i];
                f[id] = i;
                f_[i] = id;
                lo = i+1,lf = n-1;
                while(lo < lf){
                        mid = (lo+lf)/2;
                        if(v[mid].first < x) lf = mid;
                        else lo = mid + 1;
                }
                if(v[lo].first >= x)lo = n;
                ans[i] = n - lo;
        }

        for(int i = 0 ; i < k ;i++){
                cin >> u >> b;
                u--;b--;
                nu = f[u];
                nv = f[b];
                if(nu > nv){
                        swap(u,b);
                        swap(nu,nv);
                }
                if(v[nv].first < v[nu].first){
                        ans[nu]--;
                }
        }
        vector<int> ret(n);
        for(int i = 0;  i < n ; i++){
                ret[f_[i]] = ans[i];
        }
        for(int i = 0;  i < n ; i++){
                cout << ret[i] << ' ';
        }
        cout << '\n';

}

int main(){
        so();
        return 0;
}
