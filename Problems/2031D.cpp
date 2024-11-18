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
    stack<pair<ii,ii>> qu;// max min and segmet
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        qu.push({{x,x},{i,i}});
        while(!qu.empty() and qu.size() > 1){
            pair<ii,ii> ff = qu.top();
            qu.pop();
            pair<ii,ii> ow = qu.top();
            if (ow.fi.fi > ff.fi.se) {
                ow = {{max(ow.fi.fi,ff.fi.fi),ff.fi.se},{ow.se.fi,ff.se.se}};
                qu.pop();
                qu.push(ow);
            }else{
                qu.push(ff);
                break;
            } 
        }
    }
    vi ans(n);
    while(!qu.empty()){
        pair<ii,ii> fr = qu.top();
        int i,fi;
        i = fr.se.fi;
        fi = fr.se.se;
        for(int j = i ; j <= fi;j++) ans[j] = fr.fi.fi;
        qu.pop();
    }
    for(int i = 0 ; i < n ;i++)cout << ans[i] << ' ';
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
