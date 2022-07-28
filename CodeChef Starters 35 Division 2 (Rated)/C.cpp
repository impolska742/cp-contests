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

void printMatrix(vvi &v) {
	f(i, 0, v.size()) {
		f(j, 0, v[0].size()) {
			cout << v[i][j] << " ";
		}
		nl;
	}
}

void solve() {
	ll n;
	cin >> n;

	vi arr(n);
	in(arr, n);

	vi previous_same(n, 0), previous_diff(n, 0);

	previous_diff[0] = -1;
	previous_same[0] = -1;

	ll last_odd = -1, last_even = -1;

	if (arr[0] & 1) last_odd = 0;
	else last_even = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] & 1) {
			previous_same[i] = last_odd;
			previous_diff[i] = last_even;
			last_odd = i;
		} else {
			previous_same[i] = last_even;
			previous_diff[i] = last_odd;
			last_even = i;
		}
	}

	dbv(previous_same);
	dbv(previous_diff);

	
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