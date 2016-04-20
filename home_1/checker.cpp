#include <iostream>
#include <unistd.h>
int main() {
    int a, b, c, x, y;
    for (int i = -100; i <= 100; ++i) {
        for (int j = -100; j <= 100; ++j) {
            int pipefd[2];
            pipe(pipefd);
            dup2(
        }
    }
    return 0;
}
