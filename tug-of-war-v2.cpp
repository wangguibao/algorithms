/**
 * @file tug-of-war-v2.cpp
 * @author Wang Guibao (htps://github.com/wangguibao)
 * @brief Find a solution to the Tug of War problem
 *
 * Tug of War: https://www.geeksforgeeks.org/?p=115594
 * Given a set of n integers, divide the set in two subsets of n/2 sizes each
 * such that the difference of the sum of two subsets is as minimum as
 * possible. If n is even, then sizes of two subsets must be strictly n/2 and
 * if n is odd, then size of one subset must be (n-1)/2 and size of other
 * subset must be (n+1)/2.
 *
 * This is an implementation of Dynamic Programming proposed by the original
 * author on https://geeksforgeeks.org/?p=115594
 */
#include <iostream>
#include <cstdlib>

const int MAX_ELE = 16;
bool solution[MAX_ELE];
bool in_first_half[MAX_ELE];
int best_diff = INT_MAX;

int print_result(int *ele, size_t n)
{
    unsigned int i = 0;
    for (i = 0; i < n; ++i) {
        if (solution[i]) {
            std::cout << ele[i] << " ";
        }
    }
    std::cout << "| ";

    for (i = 0; i < n; ++i) {
        if (!solution[i]) {
            std::cout << ele[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

void tug_of_war(int *ele,
                size_t n,
                size_t now_pos,
                size_t first_half_size,
                int total_sum,
                int first_half_sum,
                bool *in_first_half,
                bool *solution)
{
    int diff = 0;
    if (first_half_size == n / 2) {
        diff = abs(total_sum - first_half_sum - first_half_sum);
        if (diff < best_diff) {
            best_diff = diff;
            for (unsigned int i = 0; i < n; ++i) {
                solution[i] = in_first_half[i];
            }
            solution[now_pos - 1] = true;
            print_result(ele, n);
        }
        return;
    }

    if (now_pos == n) {
        return;
    }

    in_first_half[now_pos] = true;
    tug_of_war(ele,
               n,
               now_pos + 1,
               first_half_size + 1,
               total_sum,
               first_half_sum + ele[now_pos],
               in_first_half,
               solution);

    in_first_half[now_pos] = false;
    tug_of_war(ele,
               n,
               now_pos + 1,
               first_half_size,
               total_sum,
               first_half_sum,
               in_first_half,
               solution);
    return;
}

int main()
{
    int n = 0;
    int i = 0;
    int *ele = new int[MAX_ELE];

    std::cout << "Number of elements (max " << MAX_ELE << "): ";
    std::cin >> n;
    if (n > MAX_ELE) {
        std::cout << "Out of range: " << n << std::endl;

        return -1;
    }

    std::cout << n << " integers: ";
    for (i = 0; i < n; ++i) {
        std::cin >> ele[i];
    }

    int total_sum = 0;
    int now_sum = 0;
    for (i = 0; i < n; ++i) {
        std::cout << ele[i] << " ";
        total_sum += ele[i];
        solution[i] = false;
        in_first_half[i] = false;
    }
    std::cout << std::endl;

    tug_of_war(ele, n, 0, 0, total_sum, now_sum, in_first_half, solution);

    std::cout << "After adjusting:" << std::endl;

    print_result(ele, n);
    return 0;
}
