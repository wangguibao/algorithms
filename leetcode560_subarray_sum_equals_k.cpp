class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        std::unordered_map<int, std::vector<int>> posInfo;

        int sum = 0;
        std::vector<int> sums(len + 1);
        sums[0] = 0;

        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            sums[i + 1] = sum;
            posInfo[sum].push_back(i + 1);
        }

        int n = 0;
        for (int i = 0; i <= len; ++i) {
            int curSum = sums[i];
            int target = k + curSum;

            // std::cout << "i = " << i << ", curSum = " << curSum << std::endl;
            auto it = posInfo.find(target);
            if (it == posInfo.end()) {
                continue;
            }

            auto& vec = it->second;
            // for (auto x: vec) {
            //     std::cout << "  " << x << std::endl;
            // }
            // std::cout << std::endl;

            for (auto iter = vec.rbegin(); iter != vec.rend(); ++iter) {
                // std::cout << "  " << target << ": " << *iter << std::endl;
                if (*iter <= i) {
                    break;
                }
                ++n;
            }
        }

        return n;
    }
};
