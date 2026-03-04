#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

int mask_t = 0;
int n;
int st ;
const int N = (1<<16);
int inf = (1<<30);
bool vis[N][16];
int dis[N][16];

void on(int &mask,int ind){
        mask |= (1<<ind);
}
void of(int &mask,int ind){
        mask &= ~(1<<ind);
}

int back(int mas, int ix){
        forn(i,(1<<(n+2))) forn(j,16) dis[i][j] = inf;
        queue<pair<int,int>> qu;
        qu.push({mas,ix});
        dis[mas][ix] = 0;
        while(!qu.empty()){
                auto [mask,ind] = qu.front();qu.pop();
                int cur = dis[mask][ind];
                forn(i,ind-1) if(i+1 < n + 2){
                        int new_mask = mask;
                        if((mask>>i)&1){
                                on(new_mask,ind);
                        }else{
                                of(new_mask,ind);
                        }
                        if((mask>>(i+1))&1){
                                on(new_mask,ind+1);
                        }else{
                                of(new_mask,ind+1);
                        }
                        of(new_mask,i);
                        of(new_mask,i+1);
                        if(cur + 1 < dis[new_mask][i]){
                                dis[new_mask][i] = cur + 1;
                                qu.push({new_mask,i});
                        }
                }
                forsn(i,ind+2,n+1)if(i+1 < n + 2){
                        int new_mask = mask;
                        if((mask>>i)&1){
                                on(new_mask,ind);
                        }else{
                                of(new_mask,ind);
                        }
                        if((mask>>(i+1))&1){
                                on(new_mask,ind+1);
                        }else{
                                of(new_mask,ind+1);
                        }
                        of(new_mask,i);
                        of(new_mask,i+1);
                        if(cur + 1 < dis[new_mask][i]){
                                dis[new_mask][i] = cur + 1;
                                qu.push({new_mask,i});
                        }
                }
        }
        return dis[mask_t][n];
}

void so(int test){
        cin >> n;
        string s,t;
        cin >> s >> t;
        st = n;
        int mask_s = 0,ss= n;
        forn(i,n)mask_t |= ((t[i] == 'B')<<i);
        forn(i,n)mask_s |= ((s[i] == 'B')<<i);
        int ans = back(mask_s,ss);
        if(ans == inf)ans = -1;
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

