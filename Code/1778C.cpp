#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        int n,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;

        vector<int> abc(26,0),tab;
        int lo = 0;
        for(int i = 0 ;i < n ;i++){
                if(abc[a[i]-'a'] == 0){
                        lo++;
                        tab.push_back(a[i]-'a');
                }
                abc[a[i]-'a'] = 1;
        }
        if(lo <= k){
                cout << (n*1ll*(n+1))/2 << '\n';
                return;
        }
        string p(lo-k,'0');
        string pp(k,'1');
        p += pp;
        ll ans = 0;
        //cout << lo << ' ' << p << ' ';
        do{
                vector<bool> ga(26,0);
                for(int i = 0 ; i < lo ;i++){
                        if(p[i] == '1')ga[tab[i]] = 1;
                }
                int c = 0;
                ll sc = 0;
                for(int i = 0 ; i < n ;i++){
                        if(ga[a[i]-'a'] or a[i] == b[i]){
                                c++;
                        }else{
                                sc += (c*1ll*(c+1))/2;
                                c = 0;
                        }
                }
                if(c) sc += (c*1ll*(c+1))/2;
                ans= max(ans,sc);
        }while(next_permutation(p.begin(),p.end()));
        cout << ans << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
