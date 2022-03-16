#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
mt19937 Gene;
int Get(int L, int R)
{
	int temp = Gene();
	temp = abs(temp) % (R-L+1);
	return L + temp;
}
void Quick_sort(vector <ld> &a, int L, int R)
{
	if(L == R || L > R) return;
	int chosen = Get(L,R);
	swap(a[chosen],a[R]);
	int pos = L;
	for(int i = L; i < R; ++i)
	{
		if(a[i] <= a[R])
		{
			swap(a[pos],a[i]);
			++pos;
		}
	}
	swap(a[pos],a[R]);
	Quick_sort(a,L,pos-1);
	Quick_sort(a,pos,R);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ofstream out("quick-sort.txt");
	for(int test = 1; test <= 10; ++test)
	{
		ifstream in("test/test"+to_string(test)+".txt");
		int n; in >> n;
		vector <ld> a(n);
		for(auto &i : a) in >> i;
	    auto start = std::chrono::system_clock::now();
	    Quick_sort(a,0,n-1);
	    auto end = std::chrono::system_clock::now();

	    std::chrono::duration<double> elapsed_seconds = end-start;
	    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		out << int(elapsed_seconds.count()*1000) << '\n';
	}
	cout << "Done";
}