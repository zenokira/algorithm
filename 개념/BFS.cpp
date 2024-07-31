#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<set<int>> graph;
vector<bool> bfs_visited;

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	bfs_visited[node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i : graph[cur])
		{
			if (!bfs_visited[i])
			{
				q.push(i);
				bfs_visited[i] = true;
			}
		}
	}
}

int main()
{
  cin >> point_cnt >> line_cnt >> START;

  dfs_visited.assign(point_cnt + 1, false); // 0번 노드 안쓰기 위해서 하나 더 크게 잡는다.

 for (int i = 0; i < L; i++)
	{
		int a, b;                // 간선 노드
		cin >> a >> b;
		graph[a].insert(b);      // 양방향 간선이기에 양쪽에 삽입
		graph[b].insert(a);
	}
  bfs(START);

  return 0;
}


