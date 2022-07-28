#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define vb vector<bool>
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define vpi vector<pi>
#define mpi map<ll,ll>
#define yn(x) cout << (((x)) ? "YES" : "NO") << '\n';
#define in(v,n) for(int i = 0 ; i < n ; i++) cin >> v[i];
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define frev(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mp make_pair
#define dbv(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define FIO std::ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ff first
#define ss second
#define o1(x) cout<<x<<'\n'
#define o2(x,y) cout<<x<<" "<<y<<"\n";
#define o3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define o4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<'\n'
#define nl cout <<"\n"
#define all(x) x.begin(), x.end()
#define s(x) sort(all(x));
#define sd(x) sort(all(x), greater<ll>())
#define r(s) reverse(s.begin(), s.end());
#define sum(a) ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) ( max_element((a).begin(), (a).end()) - (a).begin())
#define imax INT_MAX
#define len(a) ((ll) (a).size())
#define imin INT_MIN
#define LIMIT 10000000

const ll mod = 1000000007;

/*

*/

void solve() {
	ll n;
	cin >> n;

	vi a(n), b(n);
	in(a, n);
	in(b, n);

	ll s = 0;

	for (int i = 0; i < n - 1; i++) {
		ll x = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
		ll y = abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]);
		ll z = abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]);
		ll m = min({x, y, z});

		if (m == x) continue;
		else if (m == y) swap(a[i + 1], b[i + 1]);
		else swap(a[i], b[i]);
	}

	// dbv(a);
	// dbv(b);

	f(i, 0, n - 1) {
		s += abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
	}

	o1(s);
}

int main(int argc, char **argv)
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll tests = 1;
	cin >> tests;
	while (tests--)
		solve();
	return 0;
}