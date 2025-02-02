#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000;
vector<int> tree[MAX + 1];
int parent[MAX + 1];

void bfs(int root)
{
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : tree[node])
        {
            if (parent[next] == 0) // 아직 부모가 할당되지 않은 경우 (방문하지 않은 노드)
            {
                parent[next] = node;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs(1);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }
}
