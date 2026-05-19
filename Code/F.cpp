#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using ll = long long;

int S(int x) {
    int sa = 0;
    for (char c : to_string(x)) {
        sa += c - '0';
    }
    return sa;
}

string simulate(int x) {
    string t;
    while(x > 9) {
        t += to_string(x);
        x = S(x);
    }
    t += to_string(x);
    return t;
}

vector<int> get_freq(string s) {
    vector<int> f(10);
    for (char c : s) {
        f[c - '0'] += 1; 
    }
    return f;
}

string solve() {
    string s; cin >> s; 
    vector<int> F = get_freq(s);
    int lmt = 9 * sz(s);
    for (int s = 1; s <= lmt; s++) {
        string t = simulate(s);
        vector<int> freq = get_freq(t);

        if (freq == F) return t;

        vector<int> other(F);
        
        bool ok = 1;
        for (int x = 0; x <= 9; x++) {
            if (F[x] >= freq[x]) {
                F[x] -= freq[x];
            } else {
                ok = 0;
            }
        }
        if (ok) {
            ok = 0;
            int sa = 0;
            for (int x = 9; x >= 0; x--) {
                sa += F[x] * x;
                if (F[x] and x != 0) ok = 1; // has initial character?
            }
            ok = ok and (sa == s);
            
            if (ok) {
                string res;
                for (int x = 9; x >= 0; x--) {
                    if (F[x] == 0) continue;
                    while(F[x]--) {
                        res.push_back('0' + x);
                    }
                }
                return res + t;
            }
            
        }

        F = other;
    }
    assert(false);
    return "waaa";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
    return 0;
}


