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

const int mod = 1e9 + 7;

void so(int test){
        int n,k,x;
        cin >> n >> k;
        vector<vi> ft(n+1,vi(63,0));// tam , mask
        vi fre(64,0);
        forn(i,n)cin >> x,fre[x]++;
        auto updt = [&](int tam, int pos, int add){
                while(pos <= n+1){
                        ft[tam][pos] += add;
                        ft[tam][pos] %= mod;
                        pos += (pos & -pos);
                }
        };
        auto query = [&](int tam, int pos)->int{
                ll ret = 0;
                while(pos){
                        ret += ft[tam][pos];
                        ret %= mod;
                        pos -= (pos&-pos);
                }
                return ret;
        };
        forsn(i,1,n){
                forn(mask,64){
                        // me di cuenta que va a dar tle
                }
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
