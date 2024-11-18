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

priority_queue<int> pq;
void so(int test){
    int n,m,l;
    cin >> n >> m >> l;
    vii hur(n);
    vector<int> v[n+1];
    f(i,0,n){
        int h,r;
        cin >> h >> r ;
        hur[i] = {h,r-h+1};
    }
    int cur = 0;
    f(i,0,m){
        int x,y;
        cin >> x >> y;
        if (cur == n) {
            continue; 
        }
        int bre = hur[cur].fi;
        if (x < bre) {
            v[cur].pb(y); 
        }else{
            while(x > hur[cur].fi){
                cur++;
                if (cur == n) {
                    break; 
                }
            }
            if(cur != n)v[cur].pb(y);
        }
    }
    int ans = 0;
    ll score = 1;
    f(i,0,n){
        int barr = hur[i].se;
        //cout << "score : " << score << " , " << barr << ":"<<ln; 
        //cout << "ans : " << ans << ln;
        for(int x : v[i]){
            //cout << x << ' ';
            pq.push(x);
        }
        while(score <= barr){
            if(pq.empty())break;
            int fr = pq.top();
            score += fr;
            ans++;
            pq.pop();
        }
        if (score <= barr) {
            cout << -1 << ln;
            return;
        }
    }
    cout << ans << ln; 
    while (!pq.empty()) {
        pq.pop();
    }
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
