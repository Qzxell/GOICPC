#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int n;
    cin >> n;
    double w,l,x,y;
    cin >> w >> l >> x >> y;
    vector<double> aa,bb;
    for(int i = 0 ; i < n ; i++){
        double a,b;
        cin >> a >> b;
        double ga = sqrt((y-b)*(double)(y-b) + (x-a)*(double)(x-a));
        aa.pb(ga);
    }
    for(int i = 0 ; i < n ; i++){
        double a,b;
        cin >> a >> b;
        double ga = sqrt((y-b)*(double)(y-b) + (x-a)*(double)(x-a));
        bb.pb(ga);
    }
    sort(all(aa));
    sort(all(bb));
    if(aa[0] < bb[0]){
        cout << "A ";
        int u= upper_bound(all(aa),bb[0])-aa.begin();
        cout << u;
    } else {
        cout << "R ";
        int u= upper_bound(all(bb),aa[0])-bb.begin();
        cout << u;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
