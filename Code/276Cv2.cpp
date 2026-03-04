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

void read(vi &v){
        for(auto &x : v)cin >> x;
}
void so(int test){
        int n,q;
        cin >> n >> q;
        vi v(n);
        read(v);
        vi anti(n,0);
        forn(i,q){
                int l,r;
                cin >> l >> r;
                l--;r--;
                anti[l]++;
                if(r+1<n)anti[r+1]--;
        }
        forsn(i,1,n)
                anti[i] += anti[i-1];
        sort(all(anti));
        sort(all(v));
        ll ans = 0;
        forn(i,n){
                //cout << anti[i] << ' ' << v[i] << '\n';
                ans += anti[i]*1ll*v[i];
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
