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
        int p1[n],p2[n];
        vector<int> t(n+1,-1),posb(n+1),posa(n+1),vis(n+1,0);
        forn(i,n)cin >> p1[i],posa[p1[i]] = i;
        forn(i,n)cin >> p2[i],posb[p2[i]] = i;
        int eq = 0;
        forn(i,n) eq += (p1[i] == p2[i]);
        if(eq != (n&1)){
                cout << -1 << '\n';
                return;
        }
        forn(i,n){
                if(t[p1[i]] == -1 and t[p2[i]] == -1){
                        t[p1[i]] = p2[i];
                        t[p2[i]] = p1[i];
                        continue;
                }
                if(t[p1[i]] == -1 or t[p2[i]] == -1){
                        cout << -1 << '\n';
                        return;
                }
                if(t[p1[i]] != p2[i] or 
                t[p2[i]] != p1[i] ){
                        cout << -1 << '\n';
                        return;
                }
        }
        vector<pair<int,int>> ans;
        forn(i,n){
                if(p1[i] == p2[i]){
                        if(i+1 != n/2 + 1){
                                ans.push_back({i+1,n/2 + 1});
                                swap(p1[i],p1[n/2]);
                                swap(p2[i],p2[n/2]);
                                posa[p1[i]] = i;
                                posa[p1[n/2]] = n/2;
                        }
                }
        }
        forn(i,n)posa[p1[i]] = i;
        forn(i,n)posb[p2[i]] = i;
        forn(i,n/2){
                int ind = posa[p2[i]];
                vis[p1[i]] = vis[p2[i]] = 1;
                int ind_r = n - i - 1;
                if(ind == ind_r)continue;
                ans.push_back({ind+1,ind_r+1});
                swap(p1[ind],p1[ind_r]);
                swap(p2[ind],p2[ind_r]);
                posa[p1[ind]] = ind;
                posa[p1[ind_r]] = ind_r;
        }
        cout << ans.size() << '\n';
        for(auto [a,b] : ans)cout << a << ' ' << b << '\n';
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



