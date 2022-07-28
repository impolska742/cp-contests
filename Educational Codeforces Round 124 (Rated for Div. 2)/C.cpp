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
#define maxi(a) ( max_element((a).begin(), (a).end()) - (a).begin())
#define imax INT_MAX
#define len(a) ((ll) (a).size())
#define imin INT_MIN
#define LIMIT 10000000

const ll mod = 1000000007;

void solve() {
	ll n;
	cin >> n;

	vi a(n), b(n);
	in(a, n);
	in(b, n);

	ll A = imax, B = imax, C = imax, D = imax;

	for (int i = 0; i < n; i++) {
		A = min(A, abs(a[0] - b[i]));
		B = min(B, abs(a[n - 1] - b[i]));
		C = min(C, abs(b[0] - a[i]));
		D = min(D, abs(b[n - 1] - a[i]));
	}

	ll ans = imax;
	ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
	ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
	ans = min(ans, abs(a[0] - b[0]) + B + D);
	ans = min(ans, abs(a[n - 1] - b[n - 1]) + A + C);
	ans = min(ans, abs(a[0] - b[n - 1]) + C + B);
	ans = min(ans, abs(a[n - 1] - b[0]) + A + D);
	ans = min(ans, A + B + C + D);
	o1(ans);
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