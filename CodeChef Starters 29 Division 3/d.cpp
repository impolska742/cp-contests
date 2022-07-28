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

ll modAdd(ll a, ll b) {
	return (a + b) % mod;
}

ll modSub(ll a, ll b) {
	return (a - b + mod) % mod;
}

ll modProd(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

struct Equation {
	ll C, x;
	vpi breakdown;
};

void solve() {
	ll n, m;
	cin >> n >> m;

	vi Q(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> Q[i];

	// dbv(Q);

	vector<Equation> equations(m);

	for (int i = 0; i < m; i++) {
		cin >> equations[i].C >> equations[i].x;

		for (int j = 0; j < equations[i].x; j++) {
			ll w, c;
			cin >> w >> c;

			equations[i].breakdown.push_back({w, c});
		}
	}

	for (int i = 0; i < m; i++) {
		ll q = Q[equations[i].C];
		Q[equations[i].C] = 0;

		for (int j = 0; j < equations[i].x; j++) {
			ll w = equations[i].breakdown[j].ff;
			ll c = equations[i].breakdown[j].ss;
			ll temp = modProd(w, q);
			Q[c] = (Q[c] + temp) % mod;
		}

	}
	// dbv(Q);

	for (int i = 1; i <= n; i++)
		o1(Q[i]);
}

int main(int argc, char **argv)
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll tests = 1;
	// cin >> tests;
	while (tests--)
		solve();
	return 0;
}