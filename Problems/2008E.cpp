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
	string s;
	cin >> s;
	if(n&1){
		if(n<=3){
			cout << 1 << ln;
			return;
		}
                vi freq1(27,0);
                vi freq0(27,0);
                f(i,1,n){
                        if(i&1)freq1[s[i]-'a']++;
                        else freq0[s[i] - 'a']++;
                }
                int ans = accumulate(all(freq1),0) - *max_element(all(freq1));
                ans += accumulate(all(freq0),0) - *max_element(all(freq0));
                int ig = 0;
                f(i,1,n){
                        if(ig==0){
                                freq1[s[i-1]-'a']++;
                                freq1[s[i]-'a']--;
                        }else{
                                freq0[s[i-1]-'a']++;
                                freq0[s[i]-'a']--;
                        }
                        int aw = accumulate(all(freq1),0) - *max_element(all(freq1));
                        aw += accumulate(all(freq0),0) - *max_element(all(freq0));
                        ans = min(ans,aw);
                        ig ^= 1;
                }
                cout << ans + 1 << ln;
		return;
	}
	vi freq1(27,0);
	vi freq2(27,0);
	for(int i = 0;i < n;i+=2){
		freq1[s[i] - 'a']++;
	}
	int ans = accumulate(all(freq1),0) - *max_element(all(freq1));
	for(int i = 1;i < n;i+=2){
		freq2[s[i] - 'a']++;
	}
	ans += accumulate(all(freq2),0) - *max_element(all(freq2));
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
