#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	vector<int>* v = (vector<int>*)malloc(sizeof(vector<int>)*(N + 1));
	stack<int> s_dfs;
	queue<int> q_bfs;
	bool* check = (bool*)malloc(sizeof(bool)*(N + 1));
	fill(check, check + N + 1, false);
	for (int i = 0;i < M;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1;i <=N;i++){
		sort(v[i].begin(), v[i].end());
	}
	s_dfs.push(V);
	check[V] = true;
	printf("%d ", V);
	while (!s_dfs.empty()){
		int cur_node = s_dfs.top();
		s_dfs.pop();
		for (int i = 0;i < v[cur_node].size();i++){
		    int next = v[cur_node][i];
			if (check[next] == false){
				printf("%d ", next);
				check[next] = true;
				s_dfs.push(cur_node);
				s_dfs.push(next);
				break;
			}
		}
	}
	printf("\n");
	fill(check, check + N + 1, false);
	q_bfs.push(V);
	check[V] = true;
	while (!q_bfs.empty())	{
		int cur = q_bfs.front();
		q_bfs.pop();
		printf("%d ", cur);
		for (int i = 0;i < v[cur].size();i++){
			if (check[v[cur][i]] == false)	{
				q_bfs.push(v[cur][i]);
				check[v[cur][i]] = true;
			}
		}
	}
	return 0;
}