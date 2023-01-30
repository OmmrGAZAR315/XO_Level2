#include <cstdio>

int main() {
    int l = 4;
    int w = 7;
    int cc = 1;
    for (int x = 0; x< 4; x++) {
        for (int k = 4-x; k > 0; k--) {
            printf(" ");
        }
        for (int j = 0; j < cc; j++) {
            printf("x");
        }
        cc+=2;
        printf("\n");
    }
}