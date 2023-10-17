#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int numCoins, int targetValue) {
    if (targetValue == 0) return 0;
    int result = INT_MAX;
    for (int i = 0; i < numCoins; i++) {
        if (coins[i] <= targetValue) {
            int subResult = minCoins(coins, numCoins, targetValue - coins[i]);
            if (subResult != INT_MAX && subResult + 1 < result)
                result = subResult + 1;
        }
    }
    return result;
}

int main() {
    int coinValues[] = {9, 6, 5, 1};
    int numCoins = sizeof(coinValues) / sizeof(coinValues[0]);
    int targetValue = 11;
    cout << "Minimum coins required: " << minCoins(coinValues, numCoins, targetValue);
    return 0;
}