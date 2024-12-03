#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<sstream>
#include<bitset>
#include<iterator>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << "=" << x << endl
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define gcd(a,b) __gcd(a,b)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define neg -1
#define ll int64_t
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvl;

void insertAll(vector<int>& vec, int n) {
	for(int i = 0; i < n; i++) {
		cin>>vec[i];
	}
}

void solve() {
	string s;
    char c;
    while(scanf("%c", &c) != EOF) {
        s += c;
    }
    int n = (int) s.length();
    auto getNumber = [&](int& i){
        int x = 0;
        while(x < 1000 && isdigit(s[i])) {
            x = x * 10 + (s[i] - 'a');
            i++;
        }
        if(1 <= x && x <= 999) {
            return x;
        }
        return -1;
    };
    int ans = 0;
    bool enable = true;
    for(int i = 0; i < n; i++) {
        if (s.substr(i, 4) == "do()") {
            enable = true;
        }
        if (s.substr(i, 7) == "don\'t()") {
            enable = false;
        }
        if(s[i] == 'm') {
            if(s[i+1] == 'u' && s[i+2] == 'l' && s[i+2] == '(') {
                i += 4;
                int a = getNumber(i);
                if(s[i] == ','){
                    i += 1;
                    int b = getNumber(i);
                    if(s[i] == ')') {
                        if(a != -1 && b != -1) {
                            ans += a * b;
                        }
                    }
                }
            }
        }
    }
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
	int t = 1;
	// cin >> t;
	// int ca = 1;
	while(t-- > 0) {
		// cout<<"Case #"<<ca++<<": ";
		solve();
		cout << "\n";
	}
	return 0;
}