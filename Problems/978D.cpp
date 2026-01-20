#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        int n;
        cin >> n;
        vi v(n),gen;
        forn(i,n)cin>> v[i];
        int ans = 1e9;
        auto f = [&](int au1,int au2){
                int ret = abs(au1) + abs(au2);
                gen = v;
                gen[0] += au1;
                gen[1] += au2;
                int dif = gen[1] - gen[0];
                forsn(i,2,n){
                        gen[i] = gen[i-1] + dif;
                        if(abs(gen[i] - v[i]) > 1){
                                return;
                        }
                        ret += abs(gen[i]-v[i]);
                }
                ans = min(ans,ret);
        };
        for(int i = -1 ; i < 2; i++)
        for(int j = -1 ; j < 2; j++)
                f(i,j);
        if(ans == 1e9)ans = -1;
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


