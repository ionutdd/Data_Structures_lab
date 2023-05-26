//Just a simple problem, link to the problem: https://www.infoarena.ro/problema/farfurii

#include <fstream>

using namespace std;

ifstream f("farfurii.in");
ofstream g("farfurii.out");

int optim(int &n, unsigned long long int &k)
{
    int i;
    for (i = n; i > 1 && k > n - i; i--)
        k = k - n + i;
    return i;
}

void afismici(int i)
{
    int j;
    for (j = 1; j < i; j++)
        g << j << " ";
}

void afisnrimportant(int i, unsigned long long int k)
{
    g << i + k << " ";
}

void afisrestu(int n, int i, unsigned long long int k)
{
    int j;
    for (j = n; j >= i; j--)
        if (j != k + i)
            g << j << " ";
}

int main()
{
    int n, i, j;
    unsigned long long int k;
    f >> n >> k;
    i = optim(n, k);
    afismici(i);
    afisnrimportant(i, k);
    afisrestu(n, i, k);
}
