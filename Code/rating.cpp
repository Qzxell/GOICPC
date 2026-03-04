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

struct FT{
        int n;
        vl ft;
        FT (int n_) : n(n_),ft(n_+1,0){};

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
};

void so(int test){
        int n;
        cin >> n;
        vector<pair<ii,int>> v(n);
        int i= 0;
        map<ii,int> m;
        for(auto &[ab,ind] : v){
                ind = i++;
                cin >> ab.fi >> ab.se;
        }
        sort(all(v));
        const int N = 100001;
        FT ft1(N),ft2(N);
        vl ans(n);
        for(auto [ab,ind] : v){
                auto [a,b] = ab;
                ft1.updt(a,1);
                ft2.updt(b,1);
                m[ab]++;
                auto &res = ans[ind];
                res = min(ft1.query(a), ft2.query(b))  - (m.count(ab) ? m[ab] : 0);
        }
        forn(i,n)cout << ans[i] << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
