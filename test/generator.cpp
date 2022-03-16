#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
mt19937_64 Gene;
using ld = long double;
i64 Get(i64 val)
{
	i64 temp = Gene();
	return abs(temp) % val;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	auto Get_double = [&]()
	{
		i64 x = Get(1e9);
		i64 y = Get(1e9);
		string s = to_string(x) + "." + to_string(y);
		stringstream temp;
		temp << s;
		ld val;
		temp >> val;
		return val;
	};
	for(int test = 1; test <= 10; ++test)
	{
		int n = 1e6;
		vector <ld> a(n);
		for(auto &i : a) i = Get_double();
		if(test <= 2) sort(a.begin(),a.end());
		if(test == 2) reverse(a.begin(),a.end());
		ofstream out("test"+to_string(test)+".txt");
		out << fixed << setprecision(9) << n << '\n';
		for(auto &i : a) out << i << ' ';
		cerr << "Test " << test << " has prepared." << '\n';
	}
}