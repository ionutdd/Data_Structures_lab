//Pb: https://www.infoarena.ro/problema/proc2

#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("proc2.in");
ofstream g("proc2.out");
void procesoare(int n, int m, priority_queue<int, vector<int>, greater<int>>& p, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& timp) 
{
    int t1, t2, urmP;

    for (int i = 0; i < n; i++)
        p.push(i + 1);

    for (int i = 0; i < m; i++)
    {
        f >> t1 >> t2;

        while (!timp.empty() && t1 >= timp.top().first) {
            p.push(timp.top().second);
            timp.pop();
        }

        urmP = p.top();
        timp.push({ t1 + t2, urmP });
        p.pop();
        g << urmP << endl;
    }
}

int main() {

    int n, m;
    f >> n >> m;

    priority_queue<int, vector<int>, greater<int>> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> timp;

    procesoare(n, m, p, timp);

    return 0;
}
