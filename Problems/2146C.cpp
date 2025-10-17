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
#define x real()
#define y imag()

void so(int test){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi ans(n+2);
        f(i,1,n+1)ans[i] = i;
        if(s[n-1] == '0'){
                s = s + "1";
        }
        int cer = 0;
        f(i,0,sz(s)){
                if(s[i] == '1'){
                        if(cer == 1){
                                cout << "NO" << ln;
                                return;
                        }
                        cer = 0;
                }else cer++;
        }
        int last = 0;
        f(i,0,sz(s)){
                if(s[i] == '1'){
                        reverse(ans.begin()+last+1,ans.begin()+i+1);
                        last = i + 1;
                }
        }
        cout << "YES" << ln;
        f(i,1,n+1){
                cout << ans[i] << ' ';
        }
        cout << ln;
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



