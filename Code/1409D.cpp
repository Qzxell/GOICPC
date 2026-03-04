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
#define re real()
#define im imag()

int su(string s){
        int ret = 0;
        for (char x :s) {
                ret += int(x - '0');
        }
        return ret;
}
void so(int test){
        ll num;int s;
        cin >> num >> s;
        int punt = su(to_string(num));
        if(punt <= s){
                cout << 0 << ln;
                return;
        }
        string f_s = to_string(num);
        f_s = "0" + f_s;
        ll ans = LLONG_MAX;
        f(i,0,sz(f_s)){
                string aux = f_s;
                string sum = "1";
                f(j,i+1,sz(aux)){
                        aux[j] = '0';
                        sum += '0';
                }
                string nu_aux = to_string(stoll(aux) + stoll(sum));
                if(su(nu_aux) <= s){
                        ans = min(ans,stoll(nu_aux) - num);
                }
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



