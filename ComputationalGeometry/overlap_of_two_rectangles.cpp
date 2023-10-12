/*
 * overlap_of_two_rectangles.cpp
 *
 * @author Wang Guibao (wang_guibao@163.com)
 * @date 2023/10/12 19:23
 * @brief check if two rectangles overlap
 * from https://www.geeksforgeeks.org/find-two-rectangles-overlap/
 */
#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

bool isOverlap(Point downleft1, Point upright1, Point downleft2, Point upright2) {
    if (downleft1.x == upright1.x
            || downleft1.y == upright1.y
            || downleft2.x == upright2.x
            || downleft2.y == upright2.y) {
        return false;
    }

    if (downleft1.x > upright2.x || downleft2.x > upright1.x) {
        return false;
    }

    if (downleft1.y > upright2.y || downleft2.y > upright1.y) {
        return false;
    }

    return true;
}

int main() {
    while (1) {
        int x;
        int y;
        Point downleft1;
        Point upright1;
        Point downleft2;
        Point upright2;

        std::cout << "x and y axis for downleft point of rectangle 1: ";
        if (!(std::cin >> x >> y)) {
            return 0;
        }
        downleft1.x = x;
        downleft1.y = y;

        std::cout << "x and y axis for upright point of rectangle 1: ";
        if (!(std::cin >> x >> y)) {
            return 0;
        }
        upright1.x = x;
        upright1.y = y;

        std::cout << "x and y axis for downleft point of rectangle 2: ";
        if (!(std::cin >> x >> y)) {
            return 0;
        }
        downleft2.x = x;
        downleft2.y = y;

        std::cout << "x and y axis for upright point of rectangle 2: ";
        if (!(std::cin >> x >> y)) {
            return 0;
        }
        upright2.x = x;
        upright2.y = y;


        std::cout << (isOverlap(downleft1, upright1, downleft2, upright2)? "true" : "false") << std::endl;

    }

    return 0;
}
