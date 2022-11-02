/**
 * @file index_priority_queue.cpp
 * @author wangguibao(wang_guibao@163.com)
 * @date 2022/11/02 11:27:15
 * @brief
 *
 **/
#include <iostream>
template <typename Key> class IndexMaxPriorityQueue {
public:
    explicit IndexMaxPriorityQueue(int maxele) {
        max_ele = maxele;
        pq = new int[max_ele+1];
        qp = new int[max_ele+1];
        keys = new Key[max_ele+1];

        for (size_t i = 0; i <= max_ele; ++i) {
            qp[i] = -1;
        }
    }

    bool is_empty() {
        return (N == 0);
    }

    bool contains(int i) {
        return (qp[i] != -1);
    }

    int size() {
        return N;
    }

    void insert(int i, Key key) {
        if (i <= 0 || i > max_ele) {
            return;
        }

        N++;
        keys[i] = key;
        pq[N] = i;
        qp[i] = N;
        swim(qp[i]);

#if 0
        debug_print();
#endif
    }

    int max_index() {
        return pq[1];
    }

    Key max_key() {
        return keys[pq[1]];
    }

    void del_max() {
        exchange(1, N);
        N--;
        sink(1);
        keys[pq[N+1]] = 0;
        qp[pq[N+1]] = -1;
        pq[N+1] = 0;

#if 0
        debug_print();
#endif
    }

    Key key_of(int k) {
        return keys[k];
    }

    void change(int k, Key key) {
        keys[k] = key;
        swim(qp[k]);
        sink(qp[k]);
#if 0
        debug_print();
#endif
    }

    void del(int k) {
        exchange(qp[k], N);
        keys[k] = 0;
        pq[qp[k]] = 0;
        qp[k] = -1;

        N--;
        swim(qp[k]);
        sink(qp[k]);
#if 0
        debug_print();
#endif
    }

private:
    bool validate_index(int i) {
        return (i >= 1 && i <= max_ele);
    }

    bool less(int i, int j) {
        return keys[pq[i]] < keys[pq[j]];
    }

    void exchange(int i, int j) {
        int tmp = pq[i];
        pq[i] = pq[j];
        pq[j] = tmp;

        tmp = qp[pq[i]];
        qp[pq[i]] = qp[pq[j]];
        qp[pq[j]] = tmp;
    }

    void swim(int k) {
        if (!validate_index(k)) {
            return;
        }

        while (k > 1 && less(k/2, k)) {
            exchange(k, k/2);
            k /= 2;
        }
    }

    void sink(int k) {
        if (!validate_index(k)) {
            return;
        }

        while (k * 2 <= N) {
            int j = k * 2;
            if (j < N && less(j, j+1)) {
                j += 1;
            }

            if (!less(k, j)) {
                break;
            }

            exchange(k, j);
            k = j;
        }
    }

    void debug_print() {
        std::cout << "pq: ";
        for (size_t i = 0; i <= max_ele; ++i) {
            std::cout << pq[i] << ",";
        }
        std::cout <<std::endl;

        std::cout <<"qp: ";
        for (size_t i = 0; i <= max_ele; ++i) {
            std::cout << qp[i] << ",";
        }
        std::cout << std::endl;

        std::cout << "keys: ";
        for (size_t i = 0; i <= max_ele; ++i) {
            std::cout << keys[i] << ",";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }


private:
    int max_ele = 0;
    int N = 0;
    int* pq;
    int* qp;
    Key* keys;
};

int main() {
    IndexMaxPriorityQueue<char> pq(16);
    std::cout << "test 1===============" << std::endl;
    pq.insert(3, 'm');
    pq.insert(8, 'k');
    pq.insert(5, 'x');
    pq.insert(10, 'y');

    while (pq.size() > 0) {
        char c = pq.max_key();
        std::cout << c << std::endl;
        pq.del_max();
    }

    std::cout << "test 2==========" << std::endl;

    pq.insert(3, 'm');
    pq.insert(4, 'k');
    pq.change(4, 'n');
    pq.insert(8, 'x');
    pq.del(3);
    while(pq.size() > 0) {
        char c = pq.max_key();
        std::cout << c << std::endl;
        pq.del_max();
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
