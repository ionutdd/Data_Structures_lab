//Link to the problem: https://www.infoarena.ro/problema/kami

#include <fstream>

std::ifstream f("kami.in");
std::ofstream g("kami.out");

void intamplare(int y, int v[100001], int maxi)
{
    int s = v[y], j = y;
    j--;
    while (s > v[j] && s <= maxi)
    {
        s = s + v[j];
        j--;
    }
    if (s > maxi)
        g << "0" << '\n';
    else
        g << j << '\n';
}

int main()
{
    int n, m, i, y, z, maxi = 0, v[100001];
    bool x;
    f >> n;
    v[0] = 1000000001;
    for (i = 1; i <= n; i++)
    {
        f >> v[i];
        maxi = std::max(maxi, v[i]);
    }
    f >> m;
    for (i = 0; i < m; i++)
    {
        f >> x;
        if (x == 0)
        {
            f >> y >> z;
            v[y] = z;
            maxi = std::max(maxi, v[i]);
        }
        else
        {
            f >> y;
            intamplare(y, v, maxi);
        }
    }
}
