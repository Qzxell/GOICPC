#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n ;i++)cin >> a[i];
        int li,lf,inf= (1<<30);
        li = lf = -1;
        int cnt = 0;
        auto fun = [&](int l , int r){
                int lo = r-l +1;
                if(lo <= 0)return;
                int neg[lo+1],dos[lo+1];
                neg[0] = dos[0] = 0;
                for(int i = 1; i <= lo; i++){
                        neg[i] = neg[i-1] + (a[i+l-1] < 0);
                        dos[i] = dos[i-1] + (abs(a[i+l-1]) == 2);
                }
                int i_li = -1,i_lf = -1;
                int p_li = -1,p_lf = -1;
                for(int i = 1; i <= lo;i++){
                        if(neg[i] % 2 == 0){
                                p_li = 1;
                                p_lf = i;
                        }
                }
                int negas = 0;
                for(int i = lo ; i >= 1;i--){
                        negas += (a[l+i-1] < 0);
                        if(negas%2==0){
                                i_lf = lo;
                                i_li = i;
                        }
                }
                if(i_li != -1){
                        int cnt1 = dos[i_lf] - dos[i_li-1];
                        if(cnt1 > cnt){
                                cnt = cnt1;
                                li = i_li+l;
                                lf = i_lf+l;
                        }
                }
                if(p_li != -1){
                        int cnt1 = dos[p_lf] - dos[p_li-1];
                        if(cnt1 > cnt){
                                cnt = cnt1;
                                li = p_li+l;
                                lf = p_lf+l;
                        }
                }
        };
        vector<int> ono;
        for(int i = 0 ; i < n;i++){
                if(a[i] == 0)ono.push_back(i);
        }
        for(int i = 0 ; i + 1 < ono.size() ;i++){
                fun(ono[i]+1,ono[i+1]-1);
        }
        if(ono.empty()){
                fun(0,n-1);
        }else{
                fun(0,ono[0]-1);
                fun(ono.back()+1,n-1);
        }
        if(li == -1){
                cout << 0 << ' ' << n << '\n';
                return;
        }
        cout << li - 1 << ' ' << n - lf << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
