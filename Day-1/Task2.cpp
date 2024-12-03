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

const static int N = 1000;

void solve() {
    vector<int> a, b;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    map<int, int> freq;
    for (int& x: b) {
        freq[x]++;
    }
    long long int ans = 0;
    for (int& x: a) {
        ans += (long long) x * freq[x];
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
	while (t-- > 0) {
		// cout<<"Case #"<<ca++<<": ";
		solve();
		cout << "\n";
	}
	return 0;
}