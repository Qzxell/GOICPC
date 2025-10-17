#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define point complex<long long>

void so(int test){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cer = 0;
        int un = 0;
        vi v;
        if(s[n-1] == '0')s = s + "1";
        else s = s+ "0";
        f(i,0,sz(s)){
                if(s[i] == '0'){
                        if(un)v.pb(un);
                        un = 0;
                        cer++;
                }else{
                        if(cer)v.pb(cer);
                        cer = 0;
                        un++;
                }
        }
        int last = -1;
        int ans = 0;
        int add = 0;
        f(i,0,sz(v)){
                if(v[i]&1){
                        if(last == -1){
                                last = i;
                        }else{
                                int punt1 = last;
                                int punt2 = i;
                                while(punt1+1 < sz(v) and v[punt1+1] == 2){
                                        punt1 +=2;
                                }
                                while(punt2-1 >= 0 and v[punt2-1] == 2 and punt2 -2 >= punt1){
                                        punt2 -=2;
                                }
                                if(punt2 == punt1 ){
                                        add += (i - last);
                                }else{
                                        if(punt1 == last and punt2 == last+1 and v[last] == 1){
                                                add += (i-last);
                                        }else if(punt2 == i and punt1+1 == i and v[i] == 1){
                                                add += (i-last);
                                        }else{
                                                add += (i-last+1);
                                                add -= (punt2 - punt1+1);
                                        }
                                }
                                ans += (i-last);
                                last = -1;
                        }
                }
        }
        cout << ans << ' ' << sz(v) - add << ln;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



