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
        vi m(10);
        vi ans(sz(s));
        vi m_(10);
        m[0] = 6;
        m[1] = 2;
        m[2] = 5;
        m[3] = 5;
        m[4] = 4;
        m[5] = 5;
        m[6] = 6;
        m[7] = 3;
        m[8] = 7;
        m[9] = 6;
        m_[4] = 9;
        m_[3] = 5;
        m_[2] = 4;
        m_[1] = 7;
        m_[0] = 1;
        int to = 0;
        int usar = 0;
        f(i,0,sz(s)){
                to += m[s[i] - '0'];
                usar += m[s[i] - '0']-2;
        }
        f(i,0,sz(s)){
                if(usar > 4){
                        ans[i] = 9;
                        usar -= 4;
                }else{
                        ans[i] = m_[usar];
                        usar = 0;
                }
        }
        int in = sz(s) -1;
        while(usar > 0){
                ans[in] = 8;
                in--;
                usar--;
        }
        f(i,0,sz(s))cout << ans[i] ;


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
