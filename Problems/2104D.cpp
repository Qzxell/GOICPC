#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)


void so(int test){
        int n;
        cin >> n;
        vector<int> v(n);
        map<int,int> m;
        forn(i,n)
                cin >> v[i],m[v[i]]++;
        ll ans = 0;
        vector<int> im;
        int co = 0;
        for(auto [a,b] : m){
                if(b%2 == 0){
                        ans += a*1ll*b;
                        co ++;
                }else{
                        ans += a*1ll*(b-1);
                        co++;
                        im.push_back(a);
                }
        }
        for(auto x : im){
                cout << x << ' ';
        }
        cout << '\n';
        cout << ans << ' ';
        int ci =0 ;
        for(int i =im.size() -1; i >= 0; i--){
                if(ans){
                        if(ci >= 2)break;
                        if(co > 2)ans += v[i];
                        else{
                                if(v[i] < ans){
                                        ans += v[i];
                                        co++;
                                        ci++;
                                }
                        }

                }
        }
        if(co <= 2)ans = 0;
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
//        init();
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


