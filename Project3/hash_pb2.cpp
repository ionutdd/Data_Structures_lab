//Pb: https://www.infoarena.ro/problema/loto

#include <fstream>
#include <unordered_map>

using namespace std;

ifstream f("loto.in");
ofstream g("loto.out");

int main()
{
    int n, s, v[101], i, j, k;
    bool ok = 0;
    bool brek = 0;
    unordered_map<int, int[4]> hash;
    f >> n >> s;
    for (i = 0; i < n; i++)
    {
        f >> v[i];
    }
    for (i = 0; i < n && brek != 1; i++)
    {
        for (j = 0; j < n && brek != 1; j++)
        {
            for (k = 0; k < n && brek !=1 ; k++)
            {
                hash[v[i] + v[j] + v[k]][0] = v[i];
                hash[v[i] + v[j] + v[k]][1] = v[j];
                hash[v[i] + v[j] + v[k]][2] = v[k];
                if (hash.find(s - v[i] - v[j] - v[k]) != hash.end())
                {
                    ok = 1;
                    g << v[i] << " " << v[j] << " " << v[k] << " " << hash[s - v[i] - v[j] - v[k]][0] << " " << hash[s - v[i] - v[j] - v[k]][1] << " " << hash[s - v[i] - v[j] - v[k]][2] << " ";
                    brek = 1;
                }
            }
        }
    }
    if (ok == 0)
    {
        g << "-1";
    }
}
