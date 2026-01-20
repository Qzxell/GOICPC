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
#define sz(v) (int)(v).size()

void so(int test){
        int n;
        cin >> n;
        map<int,vi> m;
        vi v(n);
        vi ans(n,0);
        forn(i,n){
                cin >> v[i];
                m[v[i]].push_back(i);
        }
        vi uni;
        vi multi;
        for(auto [c,va] : m){
                if(sz(va) == 1){
                        uni.push_back(c);
                        continue;
                }
                if(sz(va) == 2){
                        ans[va[0]] = 0;//A
                        ans[va[1]] = 1;//B
                        continue;
                }
                multi.push_back(c);
        }
        for(int i = 1; i < sz(uni) ;i += 2){
                ans[m[uni[i]][0]] = 1;
        }
        if(sz(uni)&1){
                if(multi.empty()){
                        cout << "NO\n";
                        return;
                }
                ans[m[multi[0]][0]] = 1;
        }
        cout << "YES\n";
        forn(i,n){
                cout << (ans[i] ? 'A' : 'B');
        }
        cout << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


