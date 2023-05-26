//Link to the problem: https://www.infoarena.ro/problema/datorii

#include<fstream>

using namespace std;

ifstream f("datorii.in");
ofstream g("datorii.out");

void initZero(int n, int v[150001])
{
    for (int i = 1; i <= n; i++)
        v[i] = 0;
}

void init(int x, int y, int v[15001], int n)
{
    for (int i = x; i <= n; i += i & (-i))
        v[i] += y;
}



int rez(int x, int v[15001])
{
    int s = 0;
    for (int i = x; i >= 1; i -= i & (-i))
        s += v[i];
    return s;
}

int main()
{   
    int n, m, v[15001], x, a, b, i;
    bool k;
    f >> n >> m;
 
    initZero(n, v);
        
    for (i = 1; i <= n; i++)
    {
        f >> x;
        init(i, x, v, n);
    }
    for (i = 0; i < m; i++)
    {
        f >> k >> a >> b;
        if (k == 0) 
            init(a, -b, v, n);
        else 
            g << rez(b, v) - rez(a - 1, v) << '\n';
    }
    return 0;
}
