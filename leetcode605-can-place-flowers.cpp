class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxPlace = 0;
        int len = flowerbed.size();
        int begin = 0;
        int end = 0;

        while(true) {
            while (begin < len && flowerbed[begin] != 0) {
                ++begin;
            }

            if (begin >= len) {
                break;
            }

            if (begin > 0 && flowerbed[begin - 1] != 0) {
                --begin;
            }

            int slots = 0;
            end = begin + 1;
            while (end < len && flowerbed[end] == 0) {
                ++slots;
                ++end;
            }

            if (flowerbed[begin] == 0) {
                ++slots;
            }

            int leftFlower = (flowerbed[begin] > 0) ? 1: 0;
            int rightFlower = (end < len) && (flowerbed[end] > 0) ? 1: 0;

            // std::cout << "left " << begin << " right " << end << std::endl;
            // std::cout << "leftFlower " << leftFlower << " rightFlower " << rightFlower << std::endl;
            maxPlace += numberOfFlowersCanPlace(
                    slots,
                    leftFlower,
                    rightFlower);

            begin = end + 1;
        }

        return (maxPlace >= n);
    }

private:
    int numberOfFlowersCanPlace(int slots, int leftFlower, int rightFlower) {
        // std::cout << "slots " << slots << " left " << leftFlower << " right" << rightFlower << std::endl;
        int sideFlowers = leftFlower + rightFlower;
        slots -= sideFlowers;

        int n = (slots > 0) ? (slots + 1) / 2: 0;

        // std::cout << n << std::endl;
        return n;
    }
};
