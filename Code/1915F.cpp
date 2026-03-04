#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        cout << "====================\n";
        int n;
        cin >> n;
        vector<pair<int,pair<int,int>>> v(n+n);
        for(int i =0 ; i < n +n ; i+=2){
                int x,y;
                cin >> x >> y;
                v[i] = {x,{1,i/2}};
                v[i+1] = {y,{-1,i/2}};
        }
        sort(v.begin(),v.end());
        vector<int> dp(n+n+2,0),in(n),ou(n);
        vector<int> su(n+n+2,0);
        forn(i,n+n){
                if(v[i].second.first == 1)
                        in[v[i].second.second] = i+1;
                else 
                        ou[v[i].second.second] = i+1;
        }
        forsn(i,1,n+n+1){
                dp[i] = dp[i-1] + v[i-1].second.first;
        }
        //dforsn(i,n+n+1,1){
        for(int i = n+n; i >= 1; i--){
                su[i] = su[i+1] + v[i-1].second.first;
        }
        forn(i,n+n){
                cout << v[i].first << ' ';
        }
        cout << '\n';
        forn(i,n+n){
                cout << v[i].second.second << ' ';
        }
        cout << '\n';
        forsn(i,1,n+n+1){
                cout << su[i] << ' ';
        }
        cout << '\n';

        ll ans = 0;
        forn(i,n){
                cout << in[i] << ' ' << ou[i] << "   ; ";
        }
        cout << '\n';
        forn(i,n){
                int uwu = su[in[i] + 1] - su[ou[i]] ;
                cout <<  dp[in[i]-1] << ';' << (uwu < 0 ? uwu : 0)<< "  ";
                ans += dp[in[i]-1] + (uwu < 0 ? uwu : 0);
        }
        cout << '\n';
        cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


