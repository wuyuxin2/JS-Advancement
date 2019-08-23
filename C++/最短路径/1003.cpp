#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;  // <=500个城市
int teams[510];    // 每个城市拥有的消防队数量
int allTeams[510]; // 每段路径总共拥有的消防队数量
int e[510][510];   // 两个城市之间路径大小
int dis[510];      // 最短路径
int num[510];      // 最短路径数量
bool visit[510];   // 是否访问过
const int inf = 999999999;
int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &teams[i])
    }
    // 初始化城市之间的距离，无穷大
    fill(e[0], e[0] + 510 * 510, inf);
    // 初始化最短路径,无穷大
    fill(dis, dis + 510, inf);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    // c1为源点,初始化
    dis[c1] = 0;
    allTeams[c1] = teams[c1];
    num[c1] = 1;

    for (int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for (int j; j < n; j++)
        {
            if (visit[j] == false && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && e[u][v] != inf)
            {
                if (dis[u] + dis[u][v] < dis[v])
                {
                    dis[v] = dis[u] + dis[u][v];
                    num[v] = num[u];
                    allTeams[v] = allTeams[u] + teams[v];
                }
                else if (dis[u] + dis[u][v] == dis[v])
                {
                    num[v] = num[v] + num[u];
                    if (allTeams[u] + teams[v] > allTeams[v])
                        allTeams[v] = allTeams[u] + teams[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], allTeams[c2]);
}