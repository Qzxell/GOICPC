#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define iii pair<ii,int>
#define viii vector<iii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        ll n,q,a,b;
        cin >> n >> q;
        viii punt,uni;
        map<iii,int> M;
        map<iii,int> gru;
        vi led(n);

        auto uwu = [&](ii p)->bool{
                return p.se < 0 || (p.se == 0 && p.fi < 0);
        };
        auto pen = [&](ii p)->iii{
                int gc = gcd(p.se,p.fi);
                auto &[ra,rb] = p;
                if(gc){
                        ra /= gc;
                        rb /= gc;
                }
                return {{rb,ra},uwu(p)};
        };
        auto ga = [&](auto x, auto y){
                ii x1 = x.fi;
                ii x2 = y.fi;
                int pos1 = uwu(x1);
                int pos2 = uwu(x2);
                if(uwu(x1) != uwu(x2))return pos1 < pos2;
                return x1.fi*x2.se - x1.se*x2.fi > 0;
        };

        forn(i,n){
                cin >> a >> b;
                punt.push_back({{a,b},i});
                auto m = pen({a,b});
                if( M[m] == 0){
                        uni.push_back({{a,b},i});
                        gru[m] = i;
                }
                M[m]++;
                led[i] = gru[m];
        }
        sort(all(uni),ga);
        reverse(all(uni));
        int co = 0;
        vi pos(n);
        vl ps(n+1,0);
        for(auto [_,id]:uni){
                pos[id] = co;
                co++;
        }
        forsn(i,1,sz(uni)+1){
                ps[i] = ps[i-1] + M[pen(uni[i-1].fi)];
        }
        //cout << "-------------\n";
        //for(auto [a,b] : punt){
                //cout << a.fi << ' ' << a.se << '\n';
        //}
        //cout << "-------------\n";
        //cout << "-------------\n";
        //for(auto [xy,s] :M){
                //auto [x,y] = xy.fi;
                //cout << x <<  ' ' << y << "  " << xy.se  << ": " << s<< '\n';
        //}
        //cout << "-------------\n";
        forn(i,q){
                cin >> a >> b;
                a--;b--;
                a = led[a];b = led[b];
                ll po1,po2,ans;
                po1 = pos[a];
                po2 = pos[b];
                //cout << po1 << ' ' << po2 << '\n';
                if(po1 <= po2){
                        ans = ps[po2+1] - ps[po1] ;
                }else{
                        ans = (ps[sz(uni)] - ps[po1]) + ps[po2+1];
                }
                cout << ans << '\n';
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
