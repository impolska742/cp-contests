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

void printMatrix(vvi &v) {
	f(i, 0, v.size()) {
		f(j, 0, v[0].size()) {
			cout << v[i][j] << " ";
		}
		nl;
	}
}

bool cool(vvi &mat) {
	ll n = mat.size();
	ll m = mat[0].size();

	f(i, 0, n) {
		f(j, 0, m) {
			if (i - 1 >= 0 && mat[i - 1][j] == mat[i][j])
				return false;
			if (i + 1 < n && mat[i + 1][j] == mat[i][j])
				return false;
			if (j - 1 >= 0 && mat[i][j - 1] == mat[i][j])
				return false;
			if (j + 1 < m && mat[i][j + 1] == mat[i][j])
				return false;
		}
	}

	return true;
}

bool fine(ll i, ll j, ll x1, ll y1, ll x2, ll y2) {
	if (i == x1 && j == y1)
		return false;
	else if (i == x2 && j == y2)
		return false;
	else
		return true;
}

void solve() {
	ll n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;

	x1--;
	x2--;
	y1--;
	y2--;

	vvi mat(n, vi(m));

	mat[x1][y1] = 1;
	mat[x2][y2] = 2;

	vpi temp = {{1, 2}, {2, 1}, {1, 3}, {3, 1}};

	for (int k = 0; k < 4; k++) {
		ll start = 1;

		for (int i = 0; i < n; i++) {
			if (i % 2 != 0) {
				start = temp[k].ff;
			} else {
				start = temp[k].ss;
			}

			ll prev = start;

			for (int j = 0; j < m; j++) {
				if (prev == temp[k].ff) {
					if (fine(i, j, x1, y1, x2, y2)) {
						mat[i][j] = temp[k].ss;
					}
					prev = temp[k].ss;
				} else {
					if (fine(i, j, x1, y1, x2, y2)) {
						mat[i][j] = temp[k].ff;
					}
					prev = temp[k].ff;
				}
			}
		}

		bool ok = cool(mat);
		if (ok) {
			printMatrix(mat);
			return;
		}
	}
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