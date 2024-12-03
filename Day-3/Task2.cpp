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

bool isOk(vector<int>& a) {
	int k = (int) a.size();
	bool ok = true;
	bool only_inc = true;
	bool only_dec = true;
	for(int j = 0; j < k-1; j++){
		int diff = a[j+1] - a[j];
		if(diff < 0) {
            only_inc = false;
        }
		if(diff > 0) {
            only_dec = false;
        }
		if(!(1 <= abs(diff) && abs(diff) <= 3)) {
			ok = false;
			break;
		}
	}
	return (ok && (only_dec || only_inc));
}

void solve() {
	int T = 1000;
	int ans = 0;
	while(T--) {
		vector<int> a;
		while(true) {
			int x;
			scanf("%d", &x);
			a.push_back(x);
			char c;
			scanf("%c", &c);
			if(c == '\n') {
                break;
            }
		}
		bool anyOk = false;
		auto consider = [&](int i) {
			vector<int> b = a;
			b.erase(b.begin() + i);
			if(isOk(b)) anyOk = true;
		};
		int k = (int) a.size();
		consider(0);
		for(int i = 0; i < k-1; i++) {
			int diff = a[i+1] - a[i];
			if(abs(diff) < 1 || abs(diff) > 3) {
				consider(i);
				consider(i+1);
				break;
			}
			if(i+2 < k) {
				int diff2 = a[i+2] - a[i+1];
				if((diff > 0) != (diff2 > 0)) {
					consider(i);
					consider(i+1);
					consider(i+2);
					break;
				}
			}
		}
		if(anyOk) ans++;
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