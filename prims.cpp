#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
using namespace std;

int main()
{
	
	int wei[21][21];
	int dist[21];
	bool vis[21];
	for(int i = 0;i < 21; i++){
		for(int j = 0; j < 21; j++){
			wei[i][j] = 100000000;
			dist[i] = 100000000;
			vis[i]=false;
		}
	}
	priority_queue<int> p;
	int n,m;
	cin>>n>>m;
	vector< vector<int> > g(n + 1);
	
	for(int i=0;i<m;i++)
	{
		int src,dest;
		cin>>src>>dest;
		
		g[src].push_back(dest);
		g[dest].push_back(src);
		wei[src][dest] = abs(dest-src);
		wei[dest][src] = abs(dest-src);
	}

	
	dist[1]=0;
	p.push(1);
	int wei_final=0;
	while(p.empty()==false)
	{
		int ret=p.top();
		p.pop();
		wei_final+=dist[ret];
		for(int i=0;i<g[ret].size();i++)
		{
			if(!vis[ g[ret][i]   ])
			{
				if(wei[ret][g[ret][i]] < dist[g[ret][i]])
				{
					dist[g[ret][i]]=wei[ret][g[ret][i]];
					p.push(g[ret][i]);
				}
			}
		}
		vis[ret]=true;
	}
	
	cout<<wei_final<<endl;
}
