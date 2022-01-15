#include <stdio.h>
#include <string.h>
double num[5], flag = 0;
bool vis[5];
void dfs(int step, double sum)
{
    if (step == 3)
    {
        if (sum == 24)
        {
            flag = 1;
            return;
        }
    }
    else
    {
        step++;
        for (int i = 0; i < 4; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dfs(step, sum + num[i]); // 7*2+1+10等同于 1+10+7*2，由于该做法有所有情况，故能覆盖
                dfs(step, sum - num[i]);
                dfs(step, sum * num[i]);
                dfs(step, sum / num[i]);
                vis[i] = 0;
            }
        }
    }
}
int main()
{
    while (scanf("%lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3]) != EOF)
    {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        dfs(-1, 0);
        if (flag == 1)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }

    return 0;
}