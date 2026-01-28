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

const int N = 2e5 + 5;
int n;
ll ft[N];//1-indexded

void updt(int pos , int add){
        while(pos <= n){
                ft[pos] += add;
                pos += (pos & -pos);
        }
}

ll query(int pos){
        ll ret = 0;
        while(pos > 0){
                ret += ft[pos];
                pos -= (pos & -pos);
        }
        return ret;
}

void so(int test){
        cin >> n;
        vi color(n);
        forn(i,n)cin >> color[i];
        vi uwu =color;
        sort(all(uwu));
        uwu.erase(unique(all(uwu)),uwu.end());
        for(auto &x : color){
                x = lower_bound(all(uwu),x) - uwu.begin();
        }
        vector<vi> T(n);
        forn(i,n-1){
                int a,b;
                cin >> a >> b;
                a--;b--;
                T[a].push_back(b);
                T[b].push_back(a);
        }

        vi tin(n),tou(n),lin(n),sig(n+1,n+1),pos(n+1,n+1),dif(n),fre(n,0);
        int tim = 0;
        auto dfs = [&](auto && self, int nod, int pat) -> void{
                lin[tim] = nod;
                tin[nod] = tim++;
                for(auto x: T[nod]) if ( x != pat){
                        self(self,x, nod);
                }
                tou[nod] = tim;
        };
        tin[0] = 0;
        dfs(dfs,0,-1);
        dforn(i,n){
                sig[i] = pos[color[lin[i]]];
                pos[color[lin[i]]] = i;
        }
        int co = 0;
        forn(i,n){
                if(fre[color[lin[i]]] == 0)co++;
                dif[i] = co;
                fre[color[lin[i]]]++;
                int uwu = dif[i] -( i-1 >= 0 ? dif[i-1] : 0);
                ft[i+1] += uwu;
                if( i+1 + ((i+1)&-(i+1)) <= n ) ft[i+1 + ((i+1)&-(i+1))] += ft[i+1];
        }

        //dbg
        //forn(i,n)cout << lin[i] << ' ';
        //cout << '\n';
        //forn(i,n)cout << color[lin[i]] << ' ';
        //cout << '\n';
        //forn(i,n)cout << tin[lin[i]] << ' ';
        //cout << '\n';
        //forn(i,n)cout << tou[lin[i]] - 1 << ' ';
        //cout << '\n';


        vi ans(n);
        forn(ti,n){//index- 0
                ans[lin[ti]] = query(tou[lin[ti]]) ;
                updt(ti+1,-1);
                updt(sig[ti]+1,1);
        }
        forn(i,n){
                cout << ans[i] << ' ';
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
