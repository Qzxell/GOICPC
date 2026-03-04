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

vector<string> ma(8);
bool ban[8][8];

bool check(vi wasa){
        vii pro ;
        forn(i,sz(wasa))pro.push_back({i,wasa[i]});
        int lon = sz(wasa);
        forn(i,lon) forn(j,lon)if(i!=j){
                if( abs(pro[i].se - pro[j].se) == abs(pro[i].fi - pro[j].fi))return false;
                if(pro[i].se == pro[j].se or 
                pro[i].fi == pro[j].fi )return false;
        }
        return true;
}
int ans = 0;

void show(vi wal){
        vector<string> uwu = ma;
        forn(i,sz(wal))uwu[i][wal[i]] = 'x';
        cout << "=====\n";
        for(auto x : uwu){
                cout << x << '\n';
        }
}

void rec(vi &wal , int x){
        if(x == 8){
                //show(wal);
                ans++;
                return;
        }
        forn(i,8)if(!ban[x][i]){
                wal.push_back(i);
                if(!check(wal)){
                        wal.pop_back();
                        continue;
                }
                rec(wal,x+1);
                wal.pop_back();
        }
}

void so(int test){
        forn(i,8)cin >> ma[i];

        forn(i,8) forn(j,8) 
                ban[i][j] = (ma[i][j] == '*');
        vi wasa;
        rec(wasa,0);
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
