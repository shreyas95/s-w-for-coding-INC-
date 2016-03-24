#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 50000+5;

struct coord
{
    int x;
    long long y;
};

bool operator<(const coord &l, const coord &r)
{
    return (l.y > r.y);
}

vector< coord > graph[N];
priority_queue< coord > q;

int d[N];
int n, m, s, f;
long long er;

int main()
{
    //freopen("input.txt", "r", stdin);
    coord c, e;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++ i)
    {
        scanf("%d%d%lld", &s, &f, &er);
        c.x = f;
        c.y = er;
        graph[s].push_back(c);
        c.x = s;
        graph[f].push_back(c);
    }
    for(int i = 1; i <= n; ++ i)
    d[i] = -1;
    c.x = 1;
    c.y = 0;
    q.push(c);
    while(!q.empty())
    {
        c = q.top();
        q.pop();
        if(d[ c.x ]!=-1)
        continue;
        d[c.x] = c.y;
        if(c.x==n)
        {
            printf("%lld\n", c.y);
            return 0;
        }
        for(int j = 0; j < (int)graph[c.x].size(); ++ j)
        {
            int to = graph[c.x][j].x;
            if(d[ to ]==-1)
            {
                e.x = to;
                e.y = graph[c.x][j].y-c.y;
                if(e.y < 0)
                e.y = 0;
                e.y+=c.y;
                q.push(e);
            }
        }
    }
    printf("NO PATH EXISTS\n");
    return 0;
}
