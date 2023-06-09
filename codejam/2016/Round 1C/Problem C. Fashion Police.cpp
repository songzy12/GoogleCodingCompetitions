#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int x, y, z, K;
// https://code.google.com/codejam/contest/4314486/dashboard#s=a&a=2
int main()
{
	int i, j, k;
	int T, TT;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>TT;
	for(T=1;T<=TT;T++)
	{
		printf("Case #%d: ", T);
		cin>>x>>y>>z>>K;
		K=min(K, z);
		vector<pii> v[20];
		for(i=1;i<=x;i++)
		{
			int now=i;
			for(j=0;j<y*K;j++)
			{
				v[i].emplace_back(j/K+1, now);
				now++;
				if(now == z+1) now=1;
			}
		}
		cout<<x*y*K<<endl;
		for(i=1;i<=x;i++)
		{
			for(auto e : v[i]) printf("%d %d %d\n", i, e.first, e.second);
		}
	}
	return 0;
}
/*
 J = 2, P = 3, S = 4, K = 2:

**.. .**.
.**. ..**
..** *..*

By construction, the first layer does not have more than K *s in any row or column. This is also true of each additional layer, since they are all rotations of the first layer. Moreover, no line of cells parallel to the jacket axis (that is, across layers) can possibly have more than K *s; considering how the layers are constructed, that would directly imply more than K *s in one row of the first layer. (since S >= J)
*/