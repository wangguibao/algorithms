/**
 * @file leetcode372_super_pow.cpp
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2023/08/24 16:11
 * @brief https://leetcode.com/problems/super-pow/
 *
 **/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int bSize = b.size();
        int aMod1337 = a % 1337;
        int aPow2Mod1337 = (aMod1337 * aMod1337) % 1337;
        int aPow4Mod1337 = (aPow2Mod1337 * aPow2Mod1337) % 1337;
        int aPow8Mod1337 = (aPow4Mod1337 * aPow4Mod1337) % 1337;
        int aPow10Mod1337 = (aPow2Mod1337 * aPow8Mod1337) % 1337;

        std::vector<int> positionalRes(bSize);

        long long mod = 0;
        for (int i = bSize - 1; i >= 0; --i) {
            if (i == bSize - 1) {
                mod = aMod1337;
            } else if (i == bSize - 2) {
                mod = aPow10Mod1337;
            } else {
                long long newMod = mod;
                for (int i = 1; i < 10; ++i) {
                    newMod = (newMod * mod) % 1337;
                }
                mod = newMod;
            }

            int d = b[i];
            int res = 1;
            for (int j = 1; j <= d; ++j) {
                res = (res * mod) % 1337;
            }

            positionalRes[i] = res;
        }

        int finalRes = 1;
        for (int i = 0; i < positionalRes.size(); ++i) {
            finalRes = (finalRes * positionalRes[i]) % 1337;
        }

        return finalRes;
    }
};

int main() {
    while (1) {
        int a = 0;
        std::cout << "Input a: (control-C to exit): ";
        if (!(std::cin >> a)) {
            return 0;
        }

        std::cout << "Number of elements for b (control-C to exit): ";
        int n = 0;

        if (!(cin >> n)) {
             return -1;
        }

        std::vector<int> bvec;
        int x;
        for (size_t i = 0; i < n; ++i) {
            cin >> x;
            bvec.emplace_back(x);
        }

        Solution solution;
        auto ret = solution.superPow(a, bvec);
        std::cout << ret << std::endl;
    }

    return 0;
}
