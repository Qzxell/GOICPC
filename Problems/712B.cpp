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
        string s;
        cin >> s;
        if(sz(s)&1){
                cout << -1 << '\n';
                return;
        }

        int a,b,c,d;
        a = b =c=d=0;
        for(auto x:s){
                if(x == 'R'){
                        a++;
                }
                if(x == 'L'){
                        b++;
                }
                if(x == 'U'){
                        c++;
                }
                if(x == 'D'){
                        d++;
                }
        }
        int uwu =min(a,b);
        a -= uwu;
        b -= uwu;
        uwu = min(c,d);
        c -= uwu;
        d -= uwu;
        a = max(a,b);
        c = max(c,d);
        int ans = min(a,c);
        a -= ans;
        c -= ans;
        ans += max(a,c)/2;
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


