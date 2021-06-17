#include "swapcup.h"
#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    startGame();
    for ( int i = 0; i < N; i++ ) {
        int A, B;
        scanf("%d%d", &A, &B);
        swap(A, B);
    }
    printf("%d\n", getAnswer());
    return 0;
}


int n;
int current;
void startGame() {
    current = 2;
}

void swap(int A, int B) {
    if (A == current){
        current = B;
    }
    else if (B == current){
        current = A;
    }
}

int getAnswer() {
    return current;
}
