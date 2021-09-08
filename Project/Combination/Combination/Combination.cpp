#include <iostream>
#include <cassert> // assert
#include <map> // map
#include <Windows.h> // GetTickCount64

using namespace std;

// recursive
int Combination(const int& n, const int& r)
{
	assert(n > 0 && r >= 0 && n >= r);

	// 탈출 조건
	if (n == r || r == 0)
		return 1;

	return Combination(n - 1, r - 1) + Combination(n - 1, r);
}

// DP(bottom up)
int CombinationDP(const int& n, const int& r)
{
	assert(n > 0 && r >= 0 && n >= r);

	map<pair<int, int>, int> tree_map;

	if (n == r || n == 1 || r == 0)
		return 1;

	// iCj
	for (int i = 1; i <= n - 1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			// 끝 부분은 1
			if (j == 0 || j == i)
			{
				tree_map[make_pair(i, j)] = 1;
			}
			else
			{
				assert(tree_map[make_pair(i - 1, j - 1)] != 0 && tree_map[make_pair(i - 1, j)] != 0);
				tree_map[make_pair(i, j)] = tree_map[make_pair(i - 1, j - 1)] + tree_map[make_pair(i - 1, j)];
			}
		}
	}
	return tree_map[make_pair(n - 1, r - 1)] + tree_map[make_pair(n - 1, r)];
}

int main()
{
	int n, r;
	cin >> n >> r;

	// nCr (recursive)
	int64_t start = GetTickCount64();
	cout << "Recursive 결과 : " << Combination(n, r) << endl;

	int64_t end = GetTickCount64();
	cout << "Elapsed Tick : " << end - start << endl << endl;

	// nCr (DP, bottom up)
	start = GetTickCount64();
	cout << "DP 결과 : " << CombinationDP(n, r) << endl;

	end = GetTickCount64();
	cout << "Elapsed Tick : " << end - start << endl;
	return 0;
}