#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll ILL=2167167167167167167;
const int INF=2100000000;
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define all(p) p.begin(),p.end()
template<class T> using pq_ = priority_queue<T, vector<T>, greater<T>>;
template<class T> int LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> int UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
bool yneos(bool a,bool upp=false){if(a){cout<<(upp?"YES\n":"Yes\n");}else{cout<<(upp?"NO\n":"No\n");}return a;}
template<class T> void vec_out(vector<T> &p,int ty=0){
    if(ty==2){cout<<'{';for(int i=0;i<(int)p.size();i++){if(i){cout<<",";}cout<<'"'<<p[i]<<'"';}cout<<"}\n";}
    else{if(ty==1){cout<<p.size()<<"\n";}for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}}
template<class T> T vec_min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T vec_max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}
template<class T> T vec_sum(vector<T> &a){T ans=T(0);for(auto &x:a) ans+=x;return ans;}
int pop_count(long long a){int res=0;while(a){res+=(int)(a&1),a>>=1;}return res;}
template<class T> T square(T a){return a * a;}



void solve();
// DEAR MYSTERIES / TOMOO
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    rep(i, 0, t) solve();
}

void solve(){
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N + 1);
    rep(i, 0, N){
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
    }
    ll ans = 0;
    // y >= i 以上の大きい方から i 個の和
    vector<ll> p(N + 1);
    pq_<ll> pq;
    ll sum = 0;
    for (int i = N; i >= 0; i--){
        for (auto x : G[i]){
            pq.push(x);
            sum += x;
        }
        while ((int)pq.size() > i + 1){
            sum -= pq.top();
            pq.pop();
        }
        chmax(ans, sum);
        if ((int)pq.size() > i){
            sum -= pq.top();
            pq.pop();
        }
        p[i] = sum;
    }
    rep(i, 0, N) chmax(p[i + 1], p[i]);
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        cout << max(ans, p[b] + a) << (i + 1 == M ? "\n" : " ");
    }
}

