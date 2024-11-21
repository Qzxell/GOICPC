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
    int n,x,pos;
    cin >> n >> x >> pos;
    int lo = 0;
    int lf = n;
    int mid;
    int on = 0;// ones
    int zer = 0;// zer
    vi ga(n,-1);//
    ga[pos] = 1;
    while(lo < lf){
        mid = (lo + lf )/ 2;
        if(pos < mid){
            lf = mid;
            ga[mid] = 0;
        }else{
            lo = mid+1;
            ga[mid] = 1;
        }
    }
    int ram = 0;

    f(i,0,n)ram += (ga[i]==-1), on += (ga[i]==1),zer += (ga[i] == 0);

    if(on > x or zer > n - x + 1) {
        cout << 0 << ln;
        return;
    }
    on --;
    int mod = 1e9 + 7;
    auto fu = [&](int lf , int lo){
        ll ret = 1;
        f(i,0,lo){
            ret = (ret*lf)%mod;
            lf--;
        }
        return ret;
    };
    //if(n==123){
        //cout << 824071958 << ln;
        //return;
    //}
    //if(test == 1){
        //cout << 6 << ln;
    //}
    //return;
    cout << ((fu(x-1,on)*1ll*fu(n-x,zer))%mod*1ll*fu(ram,ram))%mod;
    cout << ln;
    //cout << fu(x-1,on) << ' ' << fu(n-x,zer) << ' ' << fu(ram,ram);

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
