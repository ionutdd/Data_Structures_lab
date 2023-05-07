//link to problem(ro): https://www.infoarena.ro/problema/vila2

#include <fstream>
#include <deque>
#include <math.h>

using namespace std;

ifstream f("vila2.in");
ofstream g("vila2.out");

int main()
{
    int n, k, v[100001], ans = -1;
    f >> n >> k;
    for (int i = 0; i < n; i++)
        f >> v[i];
    deque<int> maxi, mini;
    for (int i = 0; i < n; i++)
    {
        while (!maxi.empty() && v[i] > v[maxi.back()])
            maxi.pop_back();
        while (!mini.empty() && v[i] < v[mini.back()])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
        if (i - maxi.front() > k)
            maxi.pop_front();
        if (i - mini.front() > k)
            mini.pop_front();
        ans = max(ans, v[maxi.front()] - v[mini.front()]);
    }
    g << ans << endl;

    return 0;
}
