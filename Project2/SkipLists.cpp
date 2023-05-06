/*
Pentru a implementa operațiile 1 și 2, vom căuta nodul corespunzător valorii X, iar dacă îl găsim vom efectua inserarea/ștergerea nodului respectiv și vom actualiza nivelurile în care se găsește nodul.
Pentru a implementa operația 3, vom căuta nodul corespunzător valorii X și vom verifica dacă acesta există. Dacă da, vom returna 1, altfel vom returna 0.
Pentru a implementa operația 4, vom căuta nodul corespunzător valorii X, iar dacă acesta nu există vom lua nodul precedent (cel mai mare nod mai mic decât X) de pe nivelul maxim. De asemenea, vom verifica dacă nodul precedent există și dacă este mai mic decât X. Dacă da, vom returna valoarea stocată în nodul precedent, altfel vom returna -1 (pentru a indica că nu există un astfel de nod).
Pentru a implementa operația 5, vom căuta nodul corespunzător valorii X, iar dacă acesta există vom returna valoarea stocată în nodul respectiv. Altfel, vom căuta primul nod mai mare decât X pe nivelul maxim și vom returna valoarea stocată în nodul precedent (cel mai mic nod mai mare sau egal decât X). Dacă nodul precedent există și este mai mare sau egal decât X, vom returna valoarea stocată în acesta, altfel vom returna -1 (pentru a indica că nu există un astfel de nod).
Pentru a implementa operația 6, vom căuta nodul corespunzător valorii X și vom începe să parcurgem lista de la acest nod către dreapta, adăugând valorile întâlnite într-un vector. Vom întrerupe parcurgerea când vom ajunge la un nod cu valoarea mai mare decât Y sau la sfârșitul listei. Apoi vom sorta vectorul și îl vom returna.
*/

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <random>

using namespace std;


ifstream f("abce.in");
ofstream g("abce.out");
// definim nivelul maxim al skip listei
const int MAX_LEVEL = 100000001;

// structura nodului din skip listă
struct Node {
    int value;
    int level;
    Node** next;

    Node(int v, int l) : value(v), level(l) {
        next = new Node * [l + 1];
        for (int i = 0; i <= l; i++) {
            next[i] = nullptr;
        }
    }

    ~Node() {
        delete[] next;
    }
};


int randomLevel() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, 1);
    int level = 0;
    while (dis(gen) && level < MAX_LEVEL - 1) {
        level++;
    }
    return level;
}

// clasa skip listă
class SkipList {
private:
    Node* head;
    int level;
    int count;

public:
    SkipList() {
        // inițializăm capul skip listei cu un nod invalid
        head = new Node(INT_MIN, MAX_LEVEL);
        level = 0;
        count = 0;
    }

    ~SkipList() {
        // eliberăm toți nodurile din skip listă
        Node* curr = head->next[0];
        while (curr != nullptr) {
            Node* tmp = curr;
            curr = curr->next[0];
            delete tmp;
        }

        // eliberăm și capul
        delete head;
    }

    // adăugăm un nod cu valoarea value în skip listă
    void insert(int value) {
        // căutăm poziția unde ar trebui să inserăm nodul
        Node* curr = head;
        Node* update[MAX_LEVEL + 1];
        for (int i = level; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->value < value) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }
        curr = curr->next[0];

        // verificăm dacă nodul există deja în skip listă
        if (curr != nullptr && curr->value == value) {
            return;
        }

        // creăm un nou nod cu un nivel aleatoriu
        int newLevel = randomLevel();
        Node* newNode = new Node(value, newLevel);

        // actualizăm nivelul skip listei dacă este cazul
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++) {
                update[i] = head;
            }
            level = newLevel;
        }

        // inserăm noul nod în skip listă
        for (int i = 0; i <= newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }

        count++;
    }

    // ștergem nodul cu valoarea value din skip listă (dacă există)
    void remove(int value) {
        // căutăm poziția nodului de șters
        Node* curr = head;
        Node* update[MAX_LEVEL + 1];
        for (int i = level; i >= 0; i--) {
            while (curr->next[i] != nullptr && curr->next[i]->value < value) {
                curr = curr->next[i];
            }
            update[i] = curr;
        }
        curr = curr->next[0];

        // insert the new node
        Node* newNode = new Node(level, value);
        for (int i = 0; i <= level; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }

        // increase size of the skip list
        count++;
    }

    int search(int target) {
        Node* current = head;
        for (int i = MAX_LEVEL - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->value < target) {
                current = current->next[i];
            }
        }
        current = current->next[0];
        if (current != nullptr && current->value == target) {
            return 1;
        }
        return 0;
    }

    bool contains(int value) const;
    int floor(int value) const;
    int ceiling(int value) const;
    void range(int x, int y) const;
    void print() {
        // iterate through all levels of the skip list
        for (int i = MAX_LEVEL - 1; i >= 0; i--) {
            g << "Level " << i << ": ";

            // start at the first node of the current level
            Node* node = head->next[i];

            // iterate through all nodes on the current level
            while (node != nullptr) {
                // print the node's value
                g << node->value << " ";

                // move to the next node on the current level
                node = node->next[i];
            }

            g << endl;
        }
    }
};

bool SkipList::contains(int value) const {
    Node* x = head;
    for (int i = level; i >= 0; i--) {
        while (x->next[i] != NULL && x->next[i]->value < value) {
            x = x->next[i];
        }
    }
    x = x->next[0];
    return (x != NULL && x->value == value);
}

int SkipList::floor(int value) const {
    Node* x = head;
    for (int i = level; i >= 0; i--) {
        while (x->next[i] != NULL && x->next[i]->value < value) {
            x = x->next[i];
        }
    }
    x = x->next[0];
    if (x != NULL && x->value <= value) {
        return x->value;
    }
    else {
        return INT_MIN;
    }
}

int SkipList::ceiling(int value) const {
    Node* x = head;
    for (int i = level; i >= 0; i--) {
        while (x->next[i] != NULL && x->next[i]->value < value) {
            x = x->next[i];
        }
    }
    x = x->next[0];
    if (x != NULL && x->value >= value) {
        return x->value;
    }
    else {
        return INT_MAX;
    }
}

void SkipList::range(int x, int y) const {
    if (x > y) {
        return;
    }
    Node* curr = head->next[0];
    while (curr != NULL && curr->value <= y)
    {
        if (curr->value >= x) {
            g << curr->value << " ";
        }
        curr = curr->next[0];
    }
    g << endl;
}


int main()
{
    int q;
    f >> q;

    SkipList sl;

    for (int i = 0; i < q; i++) {
        int op, x, y;
        f >> op >> x;

        switch (op) {
        case 1:
            sl.insert(x);
        case 2:
            sl.remove(x);
        case 3:
            g << sl.search(x) << endl;
        case 4:
            g << sl.floor(x) << endl;
        case 5:
            g << sl.ceiling(x) << endl;
        case 6:
            f >> y;
            sl.range(x, y);
        default:
            break;
        }
    }

    f.close();
    g.close();

    return 0;
}
