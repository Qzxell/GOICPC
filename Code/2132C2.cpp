#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define all(v) (v).begin(),(v).end()

ll fp[30];

void init (){
        fp[0] = 1;
        forsn(i,1,30)
                fp[i] = fp[i-1]*3;
}

void so(int test){
        int n,k;
        cin >> n >> k;
        ll ans = 0;
        int nu = n ;
        int acu = 0;
        vector<int> v;
        while(nu){
                v.push_back(nu%3);
                acu += nu % 3;
                nu /= 3;
        }
        if(acu > k){
                cout << -1 << '\n';
                return;
        }
        auto f=[&](int x)->ll{
                return fp[x+1] + x*1ll*fp[x-1];
        };
        ll res = 0;
        forn(i,v.size()){
                res += v[i]*1ll*f(i);
        }
        k -= acu;
        dforsn(i,1,v.size()){
                int uwu = k/2;
                int pa = min(uwu,v[i]);
                v[i-1] += 3*pa;
                k -= 2*pa;
                res -= pa*1ll*fp[i-1];
        }
        cout << res << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        init();
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


