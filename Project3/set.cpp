//Pb: https://www.infoarena.ro/problema/muzica

#include <fstream>
#include <unordered_set>

using namespace std;

ifstream f("muzica.in");
ofstream g("muzica.out");

int main() {
    long long n, m, x, i, j, a, b, c, d, e, t, nr = 0;
    f >> n >> m;
    f >> a >> b >> c >> d >> e;
    unordered_set<int> set;

    for (i = 0; i < n; i++) {
        f >> x;
        set.insert(x);
    }
    
    if (set.count(a) > 0) {
        nr += 1;
        set.erase(a); 
    }
    if (set.count(b) > 0) {
        nr += 1;
        set.erase(b); 
    }

    for (j = 2; j < m; j++) {
        t = (c * b + d * a) % e;
        if (set.count(t) > 0) {
            nr += 1;
            set.erase(t); 
        }
        a = b;
        b = t;
    }

    g << nr;
}
