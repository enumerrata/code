#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int x = 0;
    int y = 0;

	int a1 = (C - A) * (D - B);
	int a2 = (H - F) * (G - E);
    
    if (A >= E) {
        if (G > A && G <= C)
            x = G - A;
        else if (G > C)
            x = C - A;
    } else if (C > E){
        if (G <= C)
            x = G - E;
        else 
            x = C - E;
    }
    
    if (B >= F) {
        if (H > B && H <= D)
            y = H - B;
        else if (H > D)
            y = D - B;
    } else if (D > F) {
        if (H <= D)
            y = H - F;
        else 
            y = D - F;
    }
	//printf("%d %d %d %d", a1, a2, x, y);
    return a1 + a2 - x * y;
}

int main(int argc, char *argv[])
{
	printf("> %d \n", computeArea(-2,-2,2,2,3,3,4,4));

	return 0;
}

