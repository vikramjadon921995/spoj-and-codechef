#include<bits/stdc++.h>
using namespace std;

vector< vector<long long int> > prices, discount, min_cost;

#define INF 1000000000

int main()
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		long long int n,m;
		cin>>n>>m;
		
		prices.clear();
		discount.clear();
		min_cost.clear();
		
		prices.resize(n);
		discount.resize(n);
		min_cost.resize(n);
		
		for(long long int i = 0; i < n; i++)
		{
			prices[i].resize(m);
			discount[i].resize(m);
			min_cost[i].resize(m);
		}
		
		for(long long int i = 0; i < n; i++)
		{
			for(long long int j = 0; j < m; j++)
			{
				cin>>prices[i][j];
			}
		}
		
		for(long long int i = 0; i < n; i++)
		{
			for(long long int j = 0; j < m; j++)
			{
				cin>>discount[i][j];
			}
		}
		
		long long int prev = (long long int)INF*INF;
		for(long long int i = 0; i < m; i++)
		{
			min_cost[0][i] = prices[0][i];
			prev = min(prev,min_cost[0][i]);
		}
		
		for(long long int i = 1; i < n; i++)
		{
			long long int prev1 = (long long int)INF*INF;
			for(long long int j = 0; j < m; j++)
			{
				long long int d = max((long long int)0,prices[i][j] - discount[i - 1][j]);
				min_cost[i][j] = min(min_cost[i - 1][j] + d, prev + prices[i][j]);
				prev1 = min(prev1, min_cost[i][j]);
			}
			prev = prev1;
		}
		
		long long int ans = (long long int)INF*INF;
		for(int i = 0; i < m; i++)
		{
			ans = min(ans,min_cost[n-1][i]);
		}
		cout<<ans<<endl;
	}
}
