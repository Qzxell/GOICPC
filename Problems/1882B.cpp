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
        vector<vi> fre_num(51);
        vector<vi> fre_row(n);
        vi fre_tot(51,0);
        forn(id,n){
                int tam;
                cin >> tam;
                vi fre_cur(51,0);
                forn(j,tam){
                        int x;
                        cin >> x;
                        fre_tot[x]++;
                        fre_cur[x]++;
                }
                forn(j,51) if(fre_cur[j] != 0){
                        fre_num[j].push_back(id);
                }
                fre_row[id] = fre_cur;
        }
        int tot = 0;
        forn(i,51)tot += (fre_tot[i] > 0);
        int ans = 0;
        forn(i,51) if(!fre_num[i].empty()){
                vi su = fre_tot;
                for(auto id : fre_num[i]){
                        forn(j,51){
                                su[j] -= fre_row[id][j];
                        }
                }
                int ret = 0;
                forn(j,51)ret += (su[j] > 0);
                ans = max(ans,ret);
        }
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


