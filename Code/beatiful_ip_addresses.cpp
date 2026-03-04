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
        int n;
        cin >> n;
        vi v(10,0);
        f(i,0,n){
                int x;
                cin >>x; 
                v[x] = 1;
        }
        if(n >= 7){
                cout << 0 << ln;
                return;
        }
                
        auto is_pali = [&](string s) -> bool{
                int le = sz(s);
                f(i,0,le/2)if(s[i] != s[le-i-1])return false;
                vi fr(10,0);
                f(i,0,le)fr[s[i]-'0']=1;
                int c = 0;
                f(i,0,10)if(fr[i])c++;
                if(c < n)return false;
                return true;
        };
        string s1,s2,s3,s4,owo;
        vi ga;
        f(i,0,256){
                string ss;
                ss = to_string(i);
                bool yes = 1;
                f(j,0,sz(ss))if(v[ss[j]-'0'] == 0)yes = 0;
                if(!yes)continue;
                ga.pb(i);
        }
        int le = sz(ga);
        vector<tuple<string,string,string ,string>> ans;
        f(i,0,le) f(j,0,le) f(k,0,le){
                s1 = to_string(ga[i]);
                s2 = to_string(ga[j]);
                s3 = to_string(ga[k]);
                owo = s1+s2+s3;

                s4 = "";s4 += owo[0];
                if(is_pali(owo+s4) )
                        ans.emplace_back(s1,s2,s3,s4);

                s4 = "";s4 += owo[1];s4 += owo[0];
                if(is_pali(owo+s4) and to_string(stoi(s4)) == s4)
                        ans.emplace_back(s1,s2,s3,s4);

                s4 = "";s4 += owo[2]; s4+= owo[1] ;s4 += owo[0];
                if(is_pali(owo+s4) and stoi(s4) < 256 and to_string(stoi(s4)) == s4)
                        ans.emplace_back(s1,s2,s3,s4);
        }
        cout << sz(ans) << ln;
        for(auto [a,b,c,d] : ans){
                cout << a << '.' << b << '.' << c << '.' << d << ln;
        }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
