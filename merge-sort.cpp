#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
void Merge_sort(vector <ld> &a, int L, int R)
{
	if(L == R) return;
	int mid = (L+R) >> 1;
	Merge_sort(a,L,mid);
	Merge_sort(a,mid+1,R);
	vector <ld> t(R-L+1);
	merge(a.begin()+L,a.begin()+mid+1,a.begin()+mid+1,a.begin()+R+1,t.begin());
	for(int i = 0; i < t.size(); ++i) a[i+L] = t[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ofstream out("merge-sort.txt");
	for(int test = 1; test <= 10; ++test)
	{
		ifstream in("test/test"+to_string(test)+".txt");
		int n; in >> n;
		vector <ld> a(n);
		for(auto &i : a) in >> i;
	    auto start = std::chrono::system_clock::now();
	    Merge_sort(a,0,n-1);
	    auto end = std::chrono::system_clock::now();

	    std::chrono::duration<double> elapsed_seconds = end-start;
	    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		out << int(elapsed_seconds.count()*1000) << '\n';
	}
	cout << "Done";
}