#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

bool ask(int x , int y){
	cout << "? 1 " << x << ' ' << y << endl;
	string ret;
	cin >> ret;
	return ret == "Yes";
}
bool ask(int x1 , int y1, int x2, int y2){
	cout << "? 2 " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	string ret;
	cin >> ret;
	return ret == "Yes";
}
bool ask(int u, int v, int x1 , int y1, int x2, int y2){
	cout << "? 3 " << u << ' ' << v << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	string ret;
	cin >> ret;
	return ret == "Yes";
}

void so(int test){
	int n;
	cin >> n;
	int lo = 1, lf = n + n , mid;
	while(lf - lo > 1){
		mid = (lo + lf) >> 1;
		if(mid == 1){
			lo = mid;
			continue;
		}
		if(mid == 2){
			if(ask(1,1))lf = mid;
			else lo = mid;
			continue;
		}
		if(ask(1,1, 1,mid -1 , mid-1 ,1)) lf = mid;
		else lo = mid;
	}
	int s = lf ;
	lo = 0, lf = lf - 1;
	while(lf - lo > 1){
		mid = (lo + lf) >> 1;
		if(mid == 0){
			lo = mid;
			continue;
		}
		if(mid == 1){
			if(ask(1,s-1))lf = mid;
			else {
				lo = mid;
			}
			continue;
		}
		if(ask(1,s-1, mid, s- mid)) lf = mid;
		else lo = mid;
	}
	cout << "! "<< lf << ' ' << s - lf << '\n';
}

int main(){
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

