/*
 * find_kth2.cpp
 */
#include <iostream>

#define MAX_ELE (8 + 1)

using namespace std;

int find_kth2(int *a, int begin, int end, int k)
{
    int x = a[end];
    int i = begin - 1;
    int tmp;

    for (int j = begin; j < end; j++) {
        if (a[j] < x) {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    tmp = a[i + 1];
    a[i + 1] = x;
    a[end] = tmp;

    if (i - begin + 1 == k - 1) {
        return a[i + 1];
    }
    else if (i - begin + 1 < k - 1) {
        return find_kth2(a, i + 1, end, k - (i - begin + 1));
    }
    else {
        return find_kth2(a, begin, i, k);
    }
}

int main(int argc, char *argv[])
{
    int a[MAX_ELE] = {0, 3, 4, 2, 7, 1, 5, 8, 6};

    for (int i = 1; i < MAX_ELE; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "find_kth(a, 1, 8, 5)" << find_kth2(a, 1, 8, 5) << endl;
    cout << "find_kth(a, 2, 2, 1)" << find_kth2(a, 2, 2, 1) << endl;
    cout << "find_kth(a, 3, 7, 3)" << find_kth2(a, 3, 7, 3) << endl;
	return 0;
}
