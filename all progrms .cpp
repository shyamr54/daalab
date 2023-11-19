//Write a program non-recursive and recursive program to calculate fibonacci numbers and analyze their time and space complexity
// CSD - 66


#include<iostream>
using namespace std;

void fibo_without_recurr(int n)
{   int a=0,b=1,c,i;
    for(int i=2; i<=n; i++)
    {
        c = a + b;
        cout<<" "<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;
   
  
}

 void Fibo_with_recurr(int n){    
        static int n1=0, n2=1, n3;    
        if(n>0){    
             n3 = n1 + n2;    
             n1 = n2;    
             n2 = n3;    
     cout<<n3<<" ";    
             Fibo_with_recurr(n-1);    
        }    
        cout<<endl;
    }    
    
int main()
{   
    int n,ch;
    char Y;
    
   do
   {
    cout<<"1. Fibonacci series without recurssion"<<endl;
    cout<<"2. Fibonacci series with recurssion"<<endl;
    cout<<"Enter your choice"<<endl;
    
    cin>>ch;
    
     cout<<"Enter how many many  terms :-"<<endl;
    cin>>n;
    
    if(ch<=2)
    {
    
    switch(ch)
    {
        case 1 : 
        cout<<"Fibonacci Series without recurrsion: "<<endl;
        fibo_without_recurr(n);
                 break;
                 
        case 2 : 
        cout<<"/Fibonacci Series with recurrsion: "<<endl;    
        cout<<"0 "<<"1 ";  
        Fibo_with_recurr(n-2);  
        break;
    }
    }
    else{
    break;
    }
    
    }while(ch<3);
}


_----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------_

progeram 2 :: 
import heapq


class node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

    def __lt__(self, nxt):
        return self.freq < nxt.freq


def printNodes(node, val=''):
    newVal = val + str(node.huff)
    if node.left:
        printNodes(node.left, newVal)
    if node.right:
        printNodes(node.right, newVal)
    if not node.left and not node.right:
        print(f"{node.symbol} -> {newVal}")


chars = input("Enter characters (separated by spaces): ").split()
freq = list(map(int, input("Enter frequencies (separated by spaces): ").split()))
nodes = []

for x in range(len(chars)):
    heapq.heappush(nodes, node(freq[x], chars[x]))

while len(nodes) > 1:
    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)
    left.huff = 0
    right.huff = 1
    newNode = node(left.freq + right.freq, left.symbol + right.symbol, left, right)
    heapq.heappush(nodes, newNode)

printNodes(nodes[0])


_---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------_




// Write a program to solve a fractional Knapsack problem using a greedy method.
#include <iostream>
#include <algorithm>
#include <stdexcept> // Include this for exception handling
using namespace std;

// Structure to represent an item with its weight and value
struct Item {
    double weight; // Change to double for accepting float numbers
    double value;  // Change to double for accepting float numbers
};

// Function to compare items based on their value per weight ratio in descending order
bool compareItems(Item a, Item b) {
    double ratio_a = a.value / a.weight;
    double ratio_b = b.value / b.weight;
    return ratio_a > ratio_b;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(double capacity, Item items[], int n) {
    if (capacity <= 0) {
        throw invalid_argument("Capacity should be a positive number.");
    }

    // Sort items in non-increasing order of value per weight ratio
    sort(items, items + n, compareItems);
    double totalValue = 0.0;
    double currentWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= 0 || items[i].value <= 0) {
            throw invalid_argument("Weight and value of items should be positive numbers.");
        }

        if (currentWeight + items[i].weight <= capacity) {
            // If the entire item can be added, add it to the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, add a fraction of the item to fill the capacity
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            break; // The knapsack is now full, so we break out of the loop
        }
    }
    return totalValue;
}

int main() {
    double capacity; // Change to double for accepting float numbers
    int n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;
    if (capacity <= 0) {
        cout << "Capacity should be a positive number. Exiting the program." << endl;
        cout<<"Enter capacity ";
        cin>>capacity;
    }
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;
        if (items[i].weight <= 0) {
            cout << "Weight of item must be a positive number. Please enter again: ";
            cin >> items[i].weight;
        }

        cout << "Item " << i + 1 << " value: ";
        cin >> items[i].value;
        if (items[i].value <= 0) {
            cout << "Value of item must be a positive number. Please enter again: ";
            cin >> items[i].value;
        }
    }

   
        double maxValue = fractionalKnapsack(capacity, items, n);
        cout << "The maximum value that can be obtained is: " << maxValue << endl;

   
    

    return 0;
}



_----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------_



// Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and 
// bound strategy

#include <iostream>

using namespace std;

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsackDynamic(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " value: ";
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsackDynamic(weights, values, n, capacity);

    // Display the result
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}



_---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------_


//Write a program for analysis of quick sort by using deterministic and randomized variant their time and space complexity.
#include <iostream>
#include <cstdlib>

using namespace std;
//dqs- deterministic quick sort
//rqs-randomized quick sort

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void dqs(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        dqs(arr, low, pi - 1);
        dqs(arr, pi + 1, high);
    }
}

void rqs(int arr[], int low, int high) {
    if (low < high) {
        int random = (low + high)/2;
        swap(arr[random], arr[high]);

        int pi = partition(arr, low, high);
        rqs(arr, low, pi - 1);
        rqs(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int deterministic_sorted[n];
    for (int i = 0; i < n; i++) {
        deterministic_sorted[i] = arr[i];
    }
    dqs(deterministic_sorted, 0, n - 1);

    int randomized_sorted[n];
    for (int i = 0; i < n; i++) {
        randomized_sorted[i] = arr[i];
    }
    rqs(randomized_sorted, 0, n - 1);

    cout << "Deterministic Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << deterministic_sorted[i] << " ";
    }
    cout << endl;

    cout << "Randomized Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << randomized_sorted[i] << " ";
    }
    cout << endl;

    return 0;
}


_---------------------------------------------------------------------------------------------------------------------------------------------------------------------_

6th program 

#include <iostream>
#include <cstdlib>

using namespace std;

// Deterministic Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void dqs(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << "Partitioned array: ";
        for (int i = low; i <= high; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Pivot: " << arr[pi] << endl;

        dqs(arr, low, pi - 1);
        dqs(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void rqs(int arr[], int low, int high) {
    if (low < high) {
        int random = (low + high) / 2;
        swap(arr[random], arr[high]);

        int pi = partition(arr, low, high);

        cout << "Partitioned array: ";
        for (int i = low; i <= high; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Pivot: " << arr[pi] << endl;

        rqs(arr, low, pi - 1);
        rqs(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int deterministic_sorted[n];
    for (int i = 0; i < n; i++) {
        deterministic_sorted[i] = arr[i];
    }
    cout << "Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    dqs(deterministic_sorted, 0, n - 1);

    int randomized_sorted[n];
    for (int i = 0; i < n; i++) {
        randomized_sorted[i] = arr[i];
    }
    cout << "Initial array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rqs(randomized_sorted, 0, n - 1);

    cout << "Deterministic Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << deterministic_sorted[i] << " ";
    }
    cout << endl;

    cout << "Randomized Quick Sort Result:" << endl;
    for (int i = 0; i < n; i++) {
        cout << randomized_sorted[i] << " ";
    }
    cout << endl;

    return 0;
}


