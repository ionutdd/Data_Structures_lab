//Pb: https://www.infoarena.ro/problema/heapuri

#include <fstream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");

int main()
{
    int n, i, x, y, k = 0;
    vector <int> v;
    unordered_set <int> set;
    priority_queue <int, vector<int>, greater<int>> que;
    f >> n;
    v.resize(n + 5);
    for (i=0; i<n; i++)
    {
        f >> x;
        if (x == 1)
        {
            f >> y;
            v[++k] = y;
            set.insert(y);
            que.push(y);
        }
        if (x == 2)
            f >> y,
            set.erase(v[y]);
        if (x == 3)
        {
            while (set.find(que.top()) == set.end())
                que.pop();
            g << que.top() << '\n';
        }
    }

    return 0;
}
