#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ofstream out("std-sort.txt");
	for(int test = 1; test <= 10; ++test)
	{
		ifstream in("test/test"+to_string(test)+".txt");
		int n; in >> n;
		vector <ld> a(n);
		for(auto &i : a) in >> i;
	    auto start = std::chrono::system_clock::now();
	    sort(a.begin(),a.end());
	    auto end = std::chrono::system_clock::now();

	    std::chrono::duration<double> elapsed_seconds = end-start;
	    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		out << int(elapsed_seconds.count()*1000) << '\n';
	}
	cout << "Done";
}