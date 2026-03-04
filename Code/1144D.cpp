#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    vi v(n);
    int o = 2e5 + 2;
    vi mp(o,0);
    int eq = 0;
    int ma = 0;
    for(int &i : v){
        cin >> i;
        mp[i]++;
        if (mp[i] > eq) {
            ma = i; 
            eq = mp[i];
        }
    } 

    vector<vector<int>> ans;
    int owo = 0;
    for(int i = 0 ; i< n ;i++){
        if (v[i] == ma) {
            owo = i;
            int pos = i - 1;
            if (pos == -1) {
                continue; 
            }
            while(pos >=0 and v[pos] != ma){
                if (v[pos] > ma) {
                    ans.push_back({2,pos +1,pos+2}) ;
                }else{
                    ans.push_back({1,pos+1,pos+2}) ;
                }
                pos--;
            }
        }
    }
    if (owo != n-1) {
        for(int i = owo+1;  i < n ; i++){
            if (v[i] > ma) {
                ans.push_back({2,i +1,i}) ;
            }else{
                ans.push_back({1,i +1,i}) ;
            }
        }
        
    }
    cout << ans.size() << ln;
    for (auto m : ans)cout << m[0] << ' ' << m[1] << ' ' << m[2] << ln;

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
