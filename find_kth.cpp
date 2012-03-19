/*
 * find_kth.cpp
 */
#include <iostream>

#define MAX_ELE 8

using namespace std;

int find_kth(int *a, int len, int k)
{
    int i;
    int min;
    int mid;
    int max;
    int gt;
    int lt;
    
    for (i = 0, max = a[0], min = a[0]; i < len; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if (min > a[i]) {
            min = a[i];
        }
    }
    
    mid = min + (max - min) / 2;
    
    for (i = 0, gt = 0, lt = 0; i < n; i++) {
        if (a[i] <= mid) {
            lt++;
        }
        else {
            gt++;
        }
    }
    
    if (gt == k - 1) {
        
    }
}

int main(int argc, char *argv[])
{
    int a[MAX_ELE] = {3, 4, 2, 7, 1, 5, 8, 6};
    
    cout << find_kth(a, MAX_ELE, 5) << endl;
	return 0;
}
