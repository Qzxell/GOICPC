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
    vi fr(35,0);
    vi ind(35,0);
    vi v(n);
    auto fu = [](int x){
        int c = 0;
        for(int i = 0 ; i < 32 ; i++) if((x>>i)&1){
            c = i;
        }
        return c;
    };
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        for(int j = 0 ; j < 31 ; j++)if( (v[i]>>j)&1){
            fr[j]++;
            ind[j]=i;
        }
    }

    int point = 0;
    for(int i = 34 ; i >=0 ; i--){
        if (fr[i] == 1) {
            point = ind[i];
            break;
        }
    }
    
    swap(v[0],v[point]);
    for(int i = 0 ; i < n ; i++)cout << v[i] << ' ';
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
