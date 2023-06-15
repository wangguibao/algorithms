#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class RandomizedSet {
public:
    RandomizedSet() {
        curIndex = 0;
    }

    bool insert(int val) {
        auto kv = m.insert({val, curIndex});
        if (kv.second) {
            values.push_back(val);
            ++curIndex;
            return true;
        } else {
            return false;
        }
    }

    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            return false;
        }

        int pos = it->second;
        m.erase(it);
        if (pos < curIndex - 1) {
            values[pos] = values[curIndex-1];
            it = m.find(values[pos]);
            it->second = pos;
        }

        --curIndex;
        values.pop_back();
        return true;
    }

    int getRandom() {
        if (curIndex <= 0) {
            return 0;
        }

        int pos = std::rand() % (curIndex);
        return values[pos];
    }

private:
    std::unordered_map<int, int> m;
    std::vector<int> values;
    int curIndex;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet* randomizedSet = new RandomizedSet();
#if 0
    std::cout << randomizedSet->insert(0) << std::endl;
    std::cout << randomizedSet->remove(0) << std::endl; // Returns false as 2 does not exist in the set.

    std::cout << randomizedSet->insert(0) << std::endl;
    std::cout << randomizedSet->insert(1) << std::endl;
    std::cout << randomizedSet->remove(0) << std::endl; // Returns false as 2 does not exist in the set.
    std::cout << randomizedSet->insert(2) << std::endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    std::cout << randomizedSet->remove(1) << std::endl; // Removes 1 from the set, returns true. Set now contains [2].
    std::cout << randomizedSet->getRandom() << std::endl; // Since 2 is the only number in the set, getRandom() will always return 2.
#else
    std::cout << randomizedSet->insert(3) << std::endl;
    std::cout << randomizedSet->insert(3) << std::endl;
    std::cout << randomizedSet->getRandom() << std::endl;
    std::cout << randomizedSet->getRandom() << std::endl;
    std::cout << randomizedSet->insert(1) << std::endl;
    std::cout << randomizedSet->remove(3) << std::endl;
    std::cout << randomizedSet->getRandom() << std::endl;
    std::cout << randomizedSet->getRandom() << std::endl;
    std::cout << randomizedSet->insert(0) << std::endl;
    std::cout << randomizedSet->remove(0) << std::endl;
#endif
    return 0;
}
