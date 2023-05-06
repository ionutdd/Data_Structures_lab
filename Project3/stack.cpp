//Problem(ro): https://www.infoarena.ro/problema/paranteze

#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

int main() {
    int n, counter = 0, maxi = 0;
    string x;
    f >> n;
    f >> x;
    stack <int> stiva;
    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            stiva.push(i);
        else
            if (stiva.empty() == false)
                if ((x[stiva.top()] == '{' && x[i] == '}') || (x[stiva.top()] == '[' && x[i] == ']') || (x[stiva.top()] == '(' && x[i] == ')'))
                {
                    v[i] = 1;
                    v[stiva.top()] = 1;
                    stiva.pop();
                }
                else
                    stiva.push(i);
    }

    for (int i = 0; i < n; i++)
        if (v[i] == 1)
        {
            counter++;
            maxi = max(maxi, counter);
        }
        else
            counter = 0;

    g << maxi;

    return 0;
}
