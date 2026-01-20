#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define all(v) (v).begin(),(v).end()

void so(int test){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        map<pair<int,int>,vector<int>> m;

        forn(i,n){
                auto &[a,b] = v[i];
                cin >> a >> b;
        }

        sort(all(v));

        forn(i,n)
        forsn(j,i+1,n)
        {
                auto [a,b] = v[i];
                auto [x,y] = v[j];
                int nu = y - b;
                int de = x - a;
                int gc = gcd(nu,de);
                if(gc){
                        nu /= gc;
                        de /= gc;
                }
                m[{nu,de}].push_back(abs(b-y) + abs(x-a));
        }
        ll ans = 0;
        for(auto [x,gru] : m){
                sort(all(gru));
                for(int i = 0 ; i < gru.size() ;){
                        int j = upper_bound(all(gru),gru[i]) - gru.begin();
                        int cnt = j - i;
                        ans += (cnt*1ll*(cnt-1))/2;
                        i = j;
                }
        }
        cout << ans/2 << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


