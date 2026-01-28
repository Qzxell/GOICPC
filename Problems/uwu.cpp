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
#define vii vector<ii> #define fi first #define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

const int N = 3e4 + 5;
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
        vi v(n), dif(n+1,0);
        vi sig(n+1,n+1);
        forn(i,n)cin >> v[i];

        int maxn = *max_element(all(v));
        vi fre(maxn+1,0);
        vi pos(maxn+1,n+1);

        dforn(i,n){
                sig[i+1] = pos[v[i]];
                pos[v[i]] = i + 1;
        }

        forsn(i,1,n+1){
                dif[i] = dif[i-1] + (fre[v[i-1]] == 0);
                fre[v[i-1]]++;
        }
        vi aux(n+1,0);
        forsn(i,1,n+1){
                aux[i] = dif[i] - dif[i-1];
                ft[i] += aux[i];
                int pat = i+(i & -i);
                if(pat <= n)ft[pat] += ft[i];
                        
        }

        int q;
        cin >> q;
        vector<pair<ii,int>> qu(q);
        int co = 0;
        for(auto &[ab,id] : qu){
                auto &[a,b] = ab;
                cin >> a >> b;
                id = co++;
        }
        sort(all(qu));
        int ind = 1;
        vi ans(q);
        for(auto [ab,id] : qu){
                auto [a,b] = ab;
                //cout <<"query : " <<  a << ' ' << b << '\n';
                forsn(i,ind,a){
                        updt(i+1,-1);
                        updt(sig[i],1);
                }
                ind = a;
                //forsn(i,a,n+1){
                        //cout << query(i) << ' ';
                //}
                //cout << '\n';
                ans[id] = query(b);
        }
        forn(i,q)cout << ans[i] << '\n';
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
