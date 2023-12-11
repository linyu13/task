#include <stdio.h>
int minimumRefill(int *plants, int plantsSize, int capacityA, int capacityB) {
    int numOfA = capacityA;
    int numOfB = capacityB;
    int cntA = 0;
    int cntB = 0;
    int i = 0;
    int j = plantsSize - 1;
    while (i <= j) {
        if (numOfA - plants[i] - plants[i + 1] > 0) {
            numOfA -= plants[i];
        } else {
            if (numOfA < capacityA) {
                numOfA = capacityA;
                cntA++;
            }
            numOfA -= plants[i];
        }
        i++;
        if (i == j) {
            if (numOfA >= numOfB) {
                numOfA -= plants[i];
                break;
            }
            if (numOfA < numOfB) {
                numOfB -= plants[i];
                break;
            }
        }
        if (numOfB - plants[j] - plants[j - 1] > 0) {
            numOfB -= plants[j];
        } else {
            if (numOfB < capacityB) {
                numOfB = capacityB;
                cntB++;
            }
            numOfB -= plants[j];
        }
        j--;
        if (i == j) {
            if (numOfA >= numOfB) {
                numOfA -= plants[i];
                break;
            }
            if (numOfA < numOfB) {
                numOfB -= plants[i];
                break;
            }
        }
    }
    return cntA + cntB;
}
int main() {
    int nums[] = {2, 2, 3, 3};
    minimumRefill(nums, 4, 5, 5);
}