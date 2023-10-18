#include <bits/stdc++.h>
using namespace std;

int numOrders; // Number of orders

// Recursive function to calculate the maximum total tip for X and Y
int calculateMaxTip(int currentIndex, int XRemaining, int YRemaining,
                    int tipA[], int tipB[], int numOrders) {

    // When all orders have been considered
    if (currentIndex == numOrders)
        return 0;

    // When X cannot take more orders
    if (XRemaining <= 0)
        return tipB[currentIndex] + calculateMaxTip(currentIndex + 1, XRemaining, YRemaining - 1, tipA, tipB, numOrders);

    // When Y cannot take more orders
    if (YRemaining <= 0)
        return tipA[currentIndex] + calculateMaxTip(currentIndex + 1, XRemaining - 1, YRemaining, tipA, tipB, numOrders);

    // When both X and Y can take orders
    // Calculate the maximum between two options
    else
        return max(tipA[currentIndex] + calculateMaxTip(currentIndex + 1, XRemaining - 1, YRemaining, tipA, tipB, numOrders),
                   tipB[currentIndex] + calculateMaxTip(currentIndex + 1, XRemaining, YRemaining - 1, tipA, tipB, numOrders));
}

int main() {
    int tipA[] = { 1, 2, 3, 4, 5 };
    int tipB[] = { 5, 4, 3, 2, 1 };
    numOrders = sizeof(tipA) / sizeof(tipA[0]);
    int X = 3, Y = 3;

    cout << "Maximum total tip: " << calculateMaxTip(0, X, Y, tipA, tipB, numOrders);

    return 0;
}
