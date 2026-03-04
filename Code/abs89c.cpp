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
        map<char,int> m;
        string uwu = "MARCH";
        forn(i,n){
                string s;
                cin >> s;
                for(auto c : uwu){
                        if(s[0] == c){
                                m[c]++;
                                break;
                        }
                }
        }
        vi v;
        for(auto [a,b] : m){
                v.push_back(b);
        }
        ll ans = 0;
        forn(i,sz(v))
        forn(j,sz(v))
        forn(k,sz(v))
        if( i != k and i != j and k != j){
                ans += 1ll*v[i]*v[j]*v[k];
        }
        cout << ans/6 << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
