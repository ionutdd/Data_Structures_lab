//Link to the problem: https://www.infoarena.ro/problema/stramosi

#include <fstream>

using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

void construireMatrice(int n, int a[250001][22])
{
    for (int j = 1; j <= 21; j++)
        for (int i = 1; i <= n; i++)
            a[i][j] = a[a[i][j - 1]][j - 1];
}

void intrebare(int z, int &k, int a[250001][22])
{
    for (int j = 21; j >= 0; j--)
        if ((z >> j) & 1)
            k = a[k][j];
}

int main()
{
    int n, m, z, k, i;
    f >> n >> m;
    int a[250001][22];

    for (i = 1; i <= n; i++)
        f >> a[i][0];

    construireMatrice(n, a);

    for (i = 1; i <= m; i++)
    {
        f >> k >> z;
        intrebare(z, k, a);
        g << k << '\n';
    }

    return 0;
}
