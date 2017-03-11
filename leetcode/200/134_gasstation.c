#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


//http://www.programcreek.com/2014/03/leetcode-gas-station-java/

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int i;
	int s = 0;
	int sumg = 0;
	int sumc = 0;
	int tank =0;

	for (i=0; i<gasSize; i++) {
		sumg += gas[i];
		sumc += cost[i];
		tank += gas[i] - cost[i];

		if (tank < 0) {
			s = i + 1;
			tank = 0;
		}
	}

	if (sumg >= sumc)
		return s;
	else
		return -1;
}

int main(int argc, char *argv[])
{
	printf("> \n");

	return 0;
}

