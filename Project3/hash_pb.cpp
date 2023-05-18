//Pb: https://www.infoarena.ro/problema/pariuri

#include <fstream>
#include <unordered_map>

using namespace std;

ifstream f("pariuri.in");
ofstream g("pariuri.out");

int main()
{
    int n, m, x, y, i, j;
    f >> n;
    unordered_map<int, long long int> hash;
    for (i = 0; i < n; i++)
    {
        f >> m;
        for (j = 0; j < m; j++)
        {
            f >> x >> y;
            hash[x] += y;
        }
    }
    g << hash.size() << endl;
    for (auto p = hash.begin(); p != hash.end(); p++)
    {
        g << p->first << " " << p->second << " ";
    }
}
