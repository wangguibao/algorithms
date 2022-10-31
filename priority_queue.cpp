/**
 * @file priority_queue.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/10/31 15:17:01
 * @brief
 *
 **/
#include <cstdint>
#include <iostream>

template <typename Key> class MaxPriorityQueue {
public:
    explicit MaxPriorityQueue(int maxele) {
        max_ele = maxele;
        pq = new Key[max_ele + 1];
        N = 0;
    }

    bool empty() {
        return (N == 0);
    }

    int size() {
        return N;
    }

    void insert(Key key) {
        if (size() >= max_ele) {
            return;
        }

        pq[++N] = key;
        swim(N);
    }

    Key max() {
        return pq[1];
    }

    void del_max() {
        if (size() <= 0) {
            return;
        }

#if 0
        debug_print();
#endif

        exchange(1, N);
        N--;
        sink(1);
#if 0
        debug_print();
#endif
    }

private:
   bool less(int i, int j) {
        if (i <= 0 || i > size()) {
            return false;
        }

        if (j <= 0 || j > size()) {
            return false;
        }

        return (pq[i] < pq[j]);
   }

   void exchange(int i, int j) {
        if (i <= 0 || i > size()) {
            return;
        }

        if (j <= 0 || j > size()) {
            return;
        }

        Key key = pq[i];
        pq[i] = pq[j];
        pq[j] = key;
   }

   void swim(int k) {
        if (k <= 0 || k > size()) {
            return;
        }

        while (k > 1 && less(k/2, k)) {
            exchange(k, k/2);
            k /= 2;
        }
    }

    void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j+1 <= N && less(j, j+1)) {
                j = j+1;
            }

            if (!less(k, j)) {
                break;
            }

            exchange(k, j);
            k = j;
        }
    }

    void debug_print() {
        for (size_t i = 1; i <= size(); ++i) {
            std::cout << pq[i] << ",";
        }
        std::cout << std::endl;
    }

private:
    int max_ele = 0;
    int N = 0;
    Key* pq;
};

int main() {
    MaxPriorityQueue<int32_t> pq(16);
    pq.insert(2);
    pq.insert(3);
    pq.insert(8);
    pq.insert(7);
    pq.insert(-8);
    pq.insert(10);
    pq.insert(11);
    pq.insert(9);
    pq.insert(9);


    while (!pq.empty()) {
        std::cout << pq.max() << std::endl;
        pq.del_max();
    }

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
