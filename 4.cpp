#include <iostream>
#include <vector>
using namespace std;
int customMax(int a, int b) {
    return (a > b) ? a : b;
}
void knapSack(int W, int weight[], int value[], int n, vector<bool>& selectedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = customMax(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems[i - 1] = true; // Item is selected
            w -= weight[i - 1];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive number of items." << endl;
        return 1; // Return an error code
    }
    int *value = new int[n];
    int *weight = new int[n];
    cout << "Enter the item's weight and its value:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];

        if (weight[i] <= 0 || value[i] <= 0) {
            cout << "Please enter positive values for weight and value." << endl;
            return 1; // Return an error code
        }
    }
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    if (W <= 0) {
        cout << "Please enter a positive capacity for the knapsack." << endl;
        return 1; // Return an error code
    }
    vector<bool> selectedItems(n, false); // Vector to store selection status of each item
    knapSack(W, weight, value, n, selectedItems);
    cout << "Items selected (1) or not selected (0) based on their weights: ";
    for (bool selected : selectedItems) {
        cout << selected << " ";
    }
    cout << endl;
    delete[] value;
    delete[] weight;
    return 0;
}