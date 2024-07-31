#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> graph;
vector<bool> dfs_visited;

void dfs(int node)
{
  dfs_visited[node] = true;

  for (int i : graph[node])
	{
		if (!dfs_visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
  int point_cnt, line_cnt, START;
  
  cin >> point_cnt >> line_cnt >> START;

  dfs_visited.assign(point_cnt + 1, false); // 0번 노드 안쓰기 위해서 하나 더 크게 잡는다.

 for (int i = 0; i < L; i++)
	{
		int a, b;                // 간선 노드
		cin >> a >> b;
		graph[a].insert(b);      // 양방향 간선이기에 양쪽에 삽입
		graph[b].insert(a);
	}

  dfs(START);
  return 0;
}
