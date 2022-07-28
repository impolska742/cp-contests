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
#define google(x) cout << "Case #" << x << ": ";
#define LIMIT 10000000

const ll mod = 1000000007;

/*

*/

void solve(ll test) {
	string a, b;
	cin >> a >> b;

	if (a == b) {
		google(test);
		o1(0);
		return;
	}

	if (a.size() > b.size()) {
		google(test);
		o1("IMPOSSIBLE");
		return;
	}

	ll i = 0, j = 0, cnt = 0;
	while (i < a.size() and j < b.size()) {
		if (a[i] == b[j]) {
			i++, j++;
		} else {
			cnt++;
			j++;
		}
	}

	if (j == b.size()) {
		if (i == a.size()) {
			google(test);
			o1(cnt);
		} else {
			google(test);
			o1("IMPOSSIBLE");
		}
	} else {
		if (i == a.size()) {
			cnt += b.size() - j;
			google(test);
			o1(cnt);
		} else {
			google(test);
			o1("IMPOSSIBLE");
		}
	}
}

int main(int argc, char **argv) {
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll tests = 1;
	cin >> tests;
	for (ll i = 1; i <= tests; i++)
		solve(i);
	return 0;
}