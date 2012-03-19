/*
 * find_kth_small.cpp
 */
#include <cstdlib>
#include <iostream>

using namespace std;

int find_kth_small(int *a , int l , int r , int k)
{
    int i = l , j = r , x = a[(l+r)>>1] , temp ;

    if(l == r)
    {
        return a[l] ;
    }

    do
    {
        while(a[i] < x) ++ i ;
        while(a[j] > x) -- j ;
        if(i <= j)
        {
            temp = a[i] ;
            a[i] = a[j] ,  a[j] = temp ;
            i++ ;
            j-- ;
        }
    }
    while (i <= j) ;

    if(k <= j)
    {
        return find_kth_small(a , l , j , k);
    }
    if(k >= i)
    {
        return find_kth_small(a , i , r , k);
    }
    return x ;
}

int main(int argc, char *argv[])
{
    int a[8] = {1, 7, 3, 2, 8, 4, 5, 6};

    cout << find_kth_small(a, 1, 2, 2) << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
