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
        string s,t;
        cin >> s >> t;
        string a,b;
        a = s; b = t;
        sort(all(a));
        sort(all(b));
        if(a != b){
                cout << "NO" << ln;
                return;
        }
        vi info(n,0);
        int lost = 0;
        stack<ii> st;
        f(i,0,n)if(s[i] == 'a'){
                bool fin = 0;
                f(j,max(lost,(int)i),n)if(t[j] == 'a'){
                        st.push({i,j});
                        fin = 1;
                        lost = j + 1;
                        info[j] = 1;
                        break;
                }
                if(!fin){
                        cout << "NO" << ln;
                        return;
                }
        }
        lost = n-1;
        for(int i = n-1; i >= 0 ; i--)if(s[i] == 'c'){
                bool fin = 0;
                for(int j = min(i,lost) ; j >= 0 ;j--){ if(t[j] == 'c'){
                        fin = 1;
                        while(!st.empty()){
                                auto [ind,punt] = st.top();
                                if(ind > i){
                                        st.pop();
                                        continue;
                                }
                                if( punt > j){
                                        cout << "NO" << ln;
                                        return;
                                }
                                break;
                        }
                        lost = j - 1;
                        break;
                } }
                if(!fin){
                        cout << "NO" << ln;
                        return;
                }
        }
        cout << "YES"<<ln;
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
