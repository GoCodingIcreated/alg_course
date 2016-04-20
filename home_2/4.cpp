#include <iostream>
#include <cmath>
int main() {
    int n;
    std::cin >> n;
    double min_left = 0, max_left = 0, min_right = 0, max_right = 0;
    double max_left_y = 0, max_right_y = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        if (x == 0) {
            continue;
        }
        y = fabs(y);
        if (y > 0) {
            if (x > 0) {
                max_right_y = max_right_y > y ? max_right_y : y;
            }
            else {
                max_left_y = max_left_y > y ? max_left_y : y;
            }
        }
        else {
            if (x > 0) {
                max_right = max_right > x ? max_right : x;
                if (min_right == 0 || x < min_right) {
                    min_right = x;
                }
            }
            else {
                x = -x;
                max_left = max_left > x ? max_left : x;
                if (min_left == 0 || x < min_left) {
                    min_left = x;
                }
            }
        }
    }
    double square1 = 0, square2 = 0;
    if (min_left != 0 && max_left != 0 && max_left_y != 0) {
        square1 = 0.5 * (max_left - min_left) * max_left_y;
    }
    if (min_right != 0 && max_right != 0 && max_right_y != 0) {
        square2 = 0.5 * (max_right - min_right) * max_right_y;
    }
    double square = square1 > square2 ? square1 : square2;
    std::cout << square << std::endl;
}
