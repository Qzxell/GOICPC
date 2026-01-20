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
#define sz(v) (v).begin(),(v).end()

void so(int test){
        int h,w,m,a,b;
        cin >> h >> w >> m;
        map<int,vi> mp;
        map<int,int> ver;
        forn(i,m){
                cin >> a >> b;
                mp[a].push_back(b);
                ver[b]++;
        }
        int ma = 0;
        multiset<ii> s;

        for(auto [u,v] : ver){
                s.insert({v,u});
        }

        int ans = 0;

        for(auto [c,v] : mp){
                for(auto e : v){
                        ans = max(ans,((int)v.size()) + ver[e] - 1);
                        auto it = s.find({ver[e],e});
                        if(it != s.end()) s.erase(it);
                }
                if(!s.empty()){
                        ans = max(ans,((int)v.size()) + ver[s.rbegin()->second]);
                }
                for(auto e : v){
                        s.insert({ver[e],e});
                }
        }
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


