/**
 * @file tug-of-war.cpp
 * @author Wang Guibao (htps://github.com/wangguibao)
 * @brief Find a solution to the Tug of War problem
 *
 * Tug of War: http://www.geeksforgeeks.org/?p=115594
 * Given a set of n integers, divide the set in two subsets of n/2 sizes each
 * such that the difference of the sum of two subsets is as minimum as
 * possible. If n is even, then sizes of two subsets must be strictly n/2 and
 * if n is odd, then size of one subset must be (n-1)/2 and size of other
 * subset must be (n+1)/2.
 *
 * Elabration of my solution:
 * 1) Divide the original array into two equal subsets
 * 2) Calculate the diff of sum of each subsets target_diff
 *    target_diff = abs(sum_of_first_half - sum_of_second_half)
 * 3) Loop:
 *    (1)Find an element in first subset (array[i]), an element in second subset
 *    (array[j]) so that after swapping the two elements, the diff of sum of each
 *    newly formed subset is smaller than target_diff:
 *
 *    new_diff = abs((sum_of_first_half - array[i] + array[j])
 *                  - (sum_of_second_half + array[i] - array[j]))
 *    new_diff < target_diff
 *
 *    (2) swap array[i] and array[j]
 *    (3) If cannot find such a pair of elements, then we get to the final solution
 *
 *    The estimated time complexity: O(n^3)
 */
#include <iostream>
#include <cstdlib>
const int MAX_ELE = 16;

bool compact(int *ele, int n) {
    int half = n / 2;
    int sum_first_half = 0;
    int sum_second_half = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < half; ++i) {
        sum_first_half += ele[i];
    }

    for (i = half; i < n; ++i) {
        sum_second_half += ele[i];
    }

    int target_diff = abs(sum_first_half - sum_second_half);
    if (target_diff == 0) {
        return false;
    }

    bool found = false;
    int diff = 0;
    for (i = 0; i < half; ++i) {
        for (j = half; j < n; ++j) {
            diff = (sum_first_half - ele[i] + ele[j])
                        - (sum_second_half + ele[i] - ele[j]);
            diff = abs(diff);
            // need to decrease sum of first half while increasing sum of
            // second half
            if (diff < target_diff) {
                found = true;
            }

            if (found) {
                int temp = ele[i];
                ele[i] = ele[j];
                ele[j] = temp;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    return found;
}

void tug_of_war(int *ele, int n)
{
    if (n == 0 || n == 1) {
        return;
    }

    bool stop = false;
    int round = 0;
    while (!stop) {
        round++;
        stop = !(compact(ele, n));
        std::cout << round << ": ";
        for (int i = 0; i < n; ++i) {
            std::cout << ele[i] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main()
{
    int n = 0;
    int i = 0;
    int *ele = new int[MAX_ELE];

    std::cout << "Number of elements (max " << MAX_ELE << "): ";
    std::cin >> n;

    std::cout << n << " integers: ";
    for (i = 0; i < n; ++i) {
        std::cin >> ele[i];
    }

    for (i = 0; i < n; ++i) {
        std::cout << ele[i] << " ";
    }
    std::cout << std::endl;

    tug_of_war(ele, n);

    std::cout << "After adjusting:" << std::endl;
    int half = n / 2;
    for (i = 0; i < half; ++i) {
        std::cout << ele[i] << " ";
    }
    std::cout << "| ";

    for (i = half; i < n; ++i) {
        std::cout << ele[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
