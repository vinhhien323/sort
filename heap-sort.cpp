#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ofstream out("heap-sort.txt");
	for(int test = 1; test <= 10; ++test)
	{
		ifstream in("test/test"+to_string(test)+".txt");
		int n; in >> n;
		vector <ld> a(n);
		for(auto &i : a) in >> i;
	    auto start = std::chrono::system_clock::now();
	    priority_queue <ld> A;
	    for(auto &i : a) A.push(i);
	    for(int i = n-1; i >= 0; i--)
	    {
	    	a[i] = A.top();
	    	A.pop();
	    }
	    auto end = std::chrono::system_clock::now();

	    std::chrono::duration<double> elapsed_seconds = end-start;
	    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		out << int(elapsed_seconds.count()*1000) << '\n';
	}
	cout << "Done";
}