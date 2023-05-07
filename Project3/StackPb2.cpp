//Contents of the problem(ro): https://www.infoarena.ro/problema/alibaba

#include <fstream>
#include <stack>
#include <string>

using namespace std;

ifstream f("alibaba.in");
ofstream g("alibaba.out");

int main() {
    
    int n, k;
    f >> n >> k;
    string s;
    char result[10001];
    stack<char> stiva;
    f >> s;
    for (int i = 0; i < n; i++)
    {
        while (stiva.empty() == false && k!=0 && stiva.top() < s[i])
        {
            stiva.pop();
            k--;
        }
        stiva.push(s[i]);
    }
    int i = 0;
    while (k != 0)
    {
        stiva.pop();
        k--;
    }
    while (stiva.empty() == false)
    {
        result[i] = stiva.top();
        i++;
        stiva.pop();
    }
    for (int j = i - 1; j >= 0; j--)
    {
        g << result[j];
    }
    return 0;
}
