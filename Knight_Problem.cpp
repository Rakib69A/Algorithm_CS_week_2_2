#include <bits/stdc++.h>
using namespace std;

char a[20][20];
bool vis[20][20];
int dis[20][20];

vector<pair<int, int>> d = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool valid(int i, int j)
{
    return (i >= 1 && i <= 8 && j >= 1 && j <= 8);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str1, str2;
        cin >> str1 >> str2;
        int si, sj;
        int di, dj;
        si = str1[0] - 'a'+1;
        sj = str1[1] - '0';

        di = str2[0] - 'a'+1;
        dj = str2[1] - '0';
        // cout<<si<<" "<<sj<<endl;
        // cout<<di<<" "<<dj<<endl;
        // int si,sj;
        // cin>>si>>sj;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        // int di,dj;
        // cin>>di>>dj;
        cout << dis[di][dj] << endl;
    }
    return 0;
}