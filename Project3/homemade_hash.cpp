//Pb: https://www.infoarena.ro/problema/hashuri

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("hashuri.in");
ofstream g("hashuri.out");

const int MAX = 666013;
int layer = 19;
vector<int>fr[MAX + 1];

int main() {
    
    int n, i, x, y, k = 1, treat = 0, clona, u;
    f >> n;
    for (i = 0; i < n; i++) {
        f >> x >> y;
        clona = y;
        treat = 0;
        k = 1;
        while (clona) {
            u = clona % 10;
            treat = (treat + (u * k)) % MAX;
            k = (k * layer) % MAX;
            clona /= 10;
        }

        auto el = find(fr[treat].begin(), fr[treat].end(), y);

        if (x == 1 && el == fr[treat].end())
        {
            fr[treat].push_back(y);
        }

        if (x == 2 && el != fr[treat].end())
        {
            fr[treat].erase(el);
        }

        if (x == 3) {
            if (el != fr[treat].end())
                g << "1" << '\n';
            else
                g << "0" << '\n';
        }
    }
    return 0;
}
