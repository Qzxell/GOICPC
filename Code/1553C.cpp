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

void so(int test){
        string s;
        cin >> s;
        vi pos;
        f(i,0,sz(s))if(s[i] == '?')pos.pb(i);
        auto cal = [&](string s) -> int{
                int va1 = 0;
                int va2 = 0;
                int sob1,sob2;
                sob1 = sob2 = 5;
                f(i,0,sz(s)){
                        if(i&1){
                                va2 += (s[i] == '1');
                                sob2--;
                                if(va2 > va1 + sob1 or va1 > va2 + sob2){
                                        return i+1;
                                }
                        }else{
                                va1 += (s[i] == '1');
                                sob1--;
                                if(va2 > va1 + sob1 or va1 > va2 + sob2){
                                        return i+1;
                                }
                        }

                }
                return 10;
        };
        int ans = 10;
        if(sz(pos) == 0){
                cout << cal(s) << ln;
                return;
        }
        f(mask,0,(1<<sz(pos))){
                string aux = s;
                f(i,0,sz(pos)){
                        aux[pos[i]] = ((mask>>i) & 1 ? '1' : '0');
                }
                ans = min(ans,cal(aux));
        }
        cout << ans << ln;
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



