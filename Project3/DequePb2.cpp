//Contents of problem(ro): https://www.infoarena.ro/problema/branza

#include <fstream>
#include <vector>
#include <deque>

using namespace std;

ifstream f("branza.in");
ofstream g("branza.out");

int main()
{
    unsigned long long int n, s, t;
    unsigned long long int ans = 0;
    f >> n >> s >> t;
    deque <unsigned long long int> deq;
    vector <unsigned long long int> cost;
    vector <unsigned long long int> pret;
    cost.resize(n + 10);
    pret.resize(n + 10);
    for (unsigned long long int i = 0; i < n; i++)
    {
        f >> pret[i] >> cost[i];
        while (deq.empty() == false && i - deq.front() > t)
        {
            deq.pop_front();
        }
        while (deq.empty() == false && ((pret[deq.back()] + s * (i - deq.back())) > pret[i]))
        {
            deq.pop_back();
        }
        deq.push_back(i);
        ans += cost[i] * pret[deq.front()] + s * (i - deq.front()) * cost[i];
    }
    g << ans;
    return 0;
}
