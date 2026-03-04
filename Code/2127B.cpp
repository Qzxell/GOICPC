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
        int n,x;
        cin >> n >> x;
        x--;
        string s;
        cin >> s;
        int co = 0;
        forn(i,n)co += (s[i] == '#');
        if(x == 0 or x == n-1 or co == 0){
                cout << 1 << '\n';
                return;
        }
        vi pref(n),suf(n);
        forn(i,n){
                if(s[i] == '#'){
                        pref[i] = i;
                }else{
                        if(i == 0)pref[i] = -1;
                        else pref[i] = pref[i-1];
                }
        }
        dforn(i,n){
                if(s[i] == '#'){
                        suf[i] = i;
                }else{
                        if(i == n-1)suf[i] = n;
                        else suf[i] = suf[i+1];
                }
        }
        int ans1 = x+1;
        if(suf[x] == n){
                ans1 = min(ans1,1);
        }else{
                ans1 = min(ans1,n-suf[x]+1);
        }
        int ans2 = n-x;
        if(pref[x] == -1){
                ans2 = min(ans2,1);
        }else{
                ans2 = min(ans2,pref[x]+2);
        }
        //cout << ans2 << ' ' << ans1 << '\n';
        cout << max(ans2,ans1) << '\n';

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


