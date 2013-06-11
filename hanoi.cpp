#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int disks;          // Number of disks
stack<int> peg[3];  // We wish to move disks from peg 1 to peg 3

void hanoi(int src, int aux, int dst, int n)
{
    if (n == 0) {
        return;
    }
    hanoi(src, dst, aux, n - 1);
    int x = peg[src].top();
    peg[dst].push(x);
    peg[src].pop();
    cout << x << " from peg " << src << " to peg " << dst << endl;
    hanoi(aux, src, dst, n - 1);
}

int main()
{
    cout << "Number of disks: ";
    cin >> disks;
    for (int i = disks; i >= 1; i--) {
        peg[0].push(i);
    }

    hanoi(0, 1, 2, disks);

    return 0;
}
