/**
 * median-of-two-sorted-arrays.cpp
 * @author Wang Guibao (https://github.com/wangguibao/)
 * @breif Find median of two sorted arrays whose lenghs not necessarily equal
 *
 * Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * This is a specialize case of finding the k-th element in the union of two
 * sorted arrays: assuming length of each arrays is m, n respectively, the
 * problem is to find (m + n) / 2 - th element.
 *
 * The key idea is like this:
 *
 * Assume we want to find kth element of two sorted arrays A and B
 * 1) Compare A[k/2] and B [k/2]
 * 2) if A[k/2] >= B[k/2] then forward B by k/2, skiping k/2 elements
 *   B[0...k/2 - 1]; this is safe because both of the two arrays are sorted, so
 *   even if we skip both A[0...k/2] and B[0...k/2], we will at most drop k
 *   elements, still leaving the kth element untouched.
 * 3) Repeat step 2
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return median(nums1, nums2);
    }

private:
    double median(vector<int>& vec_a, vector<int>& vec_b)
	{
        int step_a = 0;
        int step_b = 0;
        int low_a = 0;
        int low_b = 0;
        int len_a = vec_a.size();
        int len_b = vec_b.size();

        // kth element
        int k = (len_a + len_b - 1) / 2;

        int origin_k = k;

        while (k >= 1 && low_a < len_a && low_b < len_b) {
            step_a = step_b = k / 2 - 1;

            if (step_a <= 0) {
                if (vec_a[low_a] <= vec_b[low_b]) {
                    low_a += 1;
                }
                else {
                    low_b += 1;
                }
                k -= 1;
                continue;
            }

            if (step_a + low_a >= len_a - 1) {
                step_a = len_a - 1 - low_a;
            }

            if (step_b + low_b >= len_b - 1) {
                step_b = len_b - 1 - low_b;
            }

            if (vec_a[step_a + low_a] < vec_b[step_b + low_b]) {
                k -= step_a + 1;
                low_a += step_a + 1;
            }
            else if (vec_a[step_a + low_a] > vec_b[step_b + low_b]) {
                k -= step_b + 1;
                low_b += step_b + 1;
            }
            else if (vec_a[step_a + low_a] == vec_b[step_b + low_b]) {
                k -= step_a + 1 + step_b + 1;
                low_a += step_a + 1;
                low_b += step_b + 1;
            }
        }

        if (low_a >= len_a) {
            k = origin_k - len_a;
            if ((len_a + len_b) % 2 == 0) {
                return (static_cast<double>(vec_b[k]) + vec_b[k + 1]) / 2;
            }
            else {
                return static_cast<double>(vec_b[k]);
            }
        }
        else if (low_b >= len_b) {
            k = origin_k - len_b;
            if ((len_a + len_b) % 2 == 0) {
                return (static_cast<double>(vec_a[k]) + vec_a[k + 1]) / 2;
            }
            else {
                return static_cast<double>(vec_a[k]);
            }
        }
        else {
            if ((len_a + len_b) % 2 == 0) {
                int first = vec_a[low_a];
                int second = vec_b[low_b];
                
                if (low_a + 1 < len_a) {
                    if (vec_a[low_a + 1] <= second) {
                        second = vec_a[low_a + 1];
                    }
                }

                if (low_b + 1 < len_b) {
                    if (vec_b[low_b + 1] <= first) {
                        first = vec_b[low_b + 1];
                    }
                    else if (vec_b[low_b + 1] <= second) {
                        second = vec_b[low_b + 1];
                    }
                }
                return((static_cast<double>(first) + second) / 2);
            }
            else {
                return (vec_a[low_a] <= vec_b[low_b]) ? vec_a[low_a] : vec_b[low_b];
            }
        }

        cout << "Shouldn't have been here" << endl;
        return 0.0;
	}   // end median
};

int main()
{
    std::vector<int> nums1;
    std::vector<int> nums2;

    int len_1;
    int len_2;
    cin >> len_1;
    cin >> len_2;

    int x;
    for (int i = 0; i < len_1; ++i) {
        cin >> x;
        nums1.push_back(x);
    }

    for (int i = 0; i < len_2; ++i) {
        cin >> x;
        nums2.push_back(x);
    }

    Solution solution;
    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
