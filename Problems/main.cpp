#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")


#include <bits/stdc++.h>
using namespace std;
/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⠛⣿⠀⠀⠀⠀⣤⣿⢻⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⡛⠀⣤⣿⣿⣤⣤⣿⣿⣤⢸⡇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀
⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⠀
⢠⣼⣿⣿⣿⣿⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷
⢸⣿⣿⡟⠛⠛⢿⣿⣿⣿⣿⣿⣿⣿⣤⣤⣤⣿⣿⣿⣿⣤⣤⣼⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋       
*/
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(a) (int)(a.size())
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
void print(){cout<<'\n';}
template<class h,class...t>
void print(const h&v,const t&...u){cout<<v<<' ',print(u...);}

#define debug(...)

//const int mod = 1e9+7;
//const int mod = 998244353;
const int MAXN=2e5+5; 
const ll inf=1e9,INF=1e18; 

inline unsigned fast_rand() {
    static unsigned x = 123456789;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

struct custom_hash {
    static uint32_t splitmix64(uint32_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint32_t x) const {
        static const uint32_t FIXED_RANDOM = fast_rand();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,q,A[MAXN];
array<int,3> queries[MAXN];

void solve(int tc = 0){
    cin>>n>>q; vi st[q]; 
    
    unordered_map<int, vi, custom_hash> m;
    
    rep(i,1,n+1) cin>>A[i],m[A[i]].pb(i);
    
    int block = max(1, int(n / sqrt(q)));
    
    function<int(int,int,int)> freq = [&](int x,int l,int r) -> int {
        auto tl = lower_bound(all(m[x]),l);
        auto tr = upper_bound(all(m[x]),r);
        return tr - tl;
    };

    while(q--) {
        int l,r; cin>>l>>r;

        vi ans;
        rep(_,0,40) {
            int idx = fast_rand() % (r - l + 1) + l;
            if(freq(A[idx],l,r) > (r - l + 1) / 3) ans.emplace_back(A[idx]);
        }
        sort(all(ans)); ans.erase(unique(all(ans)),ans.end());
        if(ans.empty()) print(-1);
        else {
            for(int j:ans) cout<<j<<' ';
            cout<<'\n';
        }
    }

}

signed main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    int tc=1;
    cin>>tc;
    for(int t = 0; t < tc; t++) solve(t);
}
