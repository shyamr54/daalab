# daalab
 Daa lab 
Assi1:
def fibonacci_non_recursive(n):
    fib_list = [0, 1]
    for i in range(2, n + 1):
        fib_list.append(fib_list[i - 1] + fib_list[i - 2])
    return fib_list[n]

def fibonacci_recursive(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def main():
    while True:
        print("\n1. Non-recursive Fibonacci")
        print("2. Recursive Fibonacci")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter the value of n: "))
            print("Fibonacci:", fibonacci_non_recursive(n))
        elif choice == 2:
            n = int(input("Enter the value of n: "))
            print("Fibonacci:", fibonacci_recursive(n))
        elif choice == 3:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == '__main__':
    main()

Assi2:
import heapq
class node:
	def __init__(self, freq, symbol, left=None, right=None):
		self.freq = freq
		self.symbol = symbol
		self.left = left
		self.right = right
		self.huff = ' '
	def __lt__(self, nxt):
		return self.freq < nxt.freq
def printNodes(node, val=''):
	newVal = val + str(node.huff)
	if(node.left):
		printNodes(node.left, newVal)
	if(node.right):
		printNodes(node.right, newVal)
	if(not node.left and not node.right):
		print(node.symbol+ " -> "+newVal)
		
def check(c=[]):
	for i in range(0,len(c)):
		for j in range (i+1,len (c)):
			if c[i]==c[j]:
				print("you entered two similar elements")
				exit(0)
			else:
				continue
chars =[]
freq = []
nodes = []
a=int(input("ENTER NO. OF ELEMENTS TO CREATE HUFFMAN CODE\t"))
print("enter elements")
for j in range (a):
	chars.append(input())
	check(chars)	

print("enter frequencies")
for k in range(a):
	freq.append(int(input()))
for x in range(len(chars)):
	heapq.heappush(nodes, node(freq[x], chars[x]))
while len(nodes) > 1:
	left = heapq.heappop(nodes)
	right = heapq.heappop(nodes)

	left.huff = 0
	right.huff = 1

	newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
	heapq.heappush(nodes, newNode)
printNodes(nodes[0])

Assi3:
class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value
        self.ratio = value / weight

def fractional_knapsack(capacity, items):
    items.sort(key=lambda x: x.ratio, reverse=True)

    total_value = 0.0
    current_weight = 0
    for item in items:
        if current_weight + item.weight <= capacity:
            current_weight += item.weight
            total_value += item.value
        else:
            remaining_weight = capacity - current_weight
            total_value += item.ratio * remaining_weight
            break

    return total_value

if __name__ == "__main__":
    capacity = int(input("Enter the capacity of the knapsack: "))
    num_items = int(input("Enter the number of items: "))

    items = []
    for i in range(num_items):
        weight = int(input(f"Enter the weight of item {i + 1}: "))
        value = int(input(f"Enter the value of item {i + 1}: "))
        items.append(Item(weight, value))

    for item in items:
        item.ratio = item.value / item.weight

    max_value = fractional_knapsack(capacity, items)

    print(f"Maximum value in Knapsack = {max_value}")

Assi4:
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

Assi5:
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void displayMatrix(const vector<vector<int>>& graph) {
    int V = graph.size();
    cout << "Distance Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int travllingSalesmanProblem(vector<vector<int>>& graph, int s) {
    int V = graph.size();
    vector<int> vertex;
    
    for (int i = 0; i < V; i++) {
        if (i != s) {
            vertex.push_back(i);
        }
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main() {
    int V;
    cout << "Enter the number of cities: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter distances from one city to another (enter -1 for unreachable cities):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Distance from City " << i << " to City " << j << ": ";
                cin >> graph[i][j];
            } else {
                graph[i][j] = 0;  // Distance from a city to itself is 0.
            }
        }
    }
    displayMatrix(graph); // Display the distance matrix
    int s;
    cout << "Enter the starting city (0 to " << V - 1 << "): ";
    cin >> s;
    if (s < 0 || s >= V) {
        cout << "Invalid starting city.\n";
        return 1;
    }
    int minPath = travllingSalesmanProblem(graph, s);
    cout << "Minimum path cost: " << minPath << endl;
    return 0;
}

assi6:
def is_safe(board, row, col, N):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check if there is a queen in the left diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check if there is a queen in the right diagonal
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(board, row, N):
    if row == N:
        return True

    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = 1

            if solve_n_queens(board, row + 1, N):
                return True

            # Backtrack if placing a queen in the current position doesn't lead to a solution
            board[row][col] = 0

    return False

def print_board(board):
    for row in board:
        print(" ".join(["Q" if cell == 1 else "." for cell in row]))

def main():
    print("N-Queens Backtracking Solver")
    N = int(input("Enter the size of the chessboard (N): "))
    first_queen_row = int(input("Enter the row index for the first queen (0 to N-1): "))

    # Initialize the board with the first queen already placed
    board = [[0] * N for _ in range(N)]
    board[first_queen_row][0] = 1

    if solve_n_queens(board, 1, N):
        print("\nSolution found:")
        print_board(board)
    else:
        print("\nNo solution found.")

if __name__ == "__main__":
    main()

Assi7:
import random
def quicksort(arr, method, comparisons=0):
    if len(arr) <= 1:
        return arr, comparisons

    pivot_index = choose_pivot(arr, method)
    pivot = arr[pivot_index]
    left = [x for i, x in enumerate(arr) if x <= pivot and i != pivot_index]
    right = [x for i, x in enumerate(arr) if x > pivot and i != pivot_index]

    sorted_left, left_comparisons = quicksort(left, method, comparisons)
    sorted_right, right_comparisons = quicksort(right, method, comparisons)

    return sorted_left + [pivot] + sorted_right, comparisons + left_comparisons + right_comparisons

def choose_pivot(arr, method):
    if method == "deterministic":
        return 0  # Always choose the first element as the pivot in the deterministic variant
    elif method == "randomized":
        return random.randint(0, len(arr) - 1)  # Choose a random element as the pivot in the randomized variant

def main():
    print("QuickSort Analysis Program")
    n = int(input("Enter the number of elements in the array: "))
    arr = [int(input(f"Enter element {i + 1}: ")) for i in range(n)]

    print("\nChoose a QuickSort variant:")
    print("1. Deterministic QuickSort")
    print("2. Randomized QuickSort")

    choice = input("Enter your choice (1/2): ")
    if choice == "1":
        method = "deterministic"
    elif choice == "2":
        method = "randomized"
    else:
        print("Invalid choice. Please enter 1 or 2.")
        return

    sorted_arr, comparisons = quicksort(arr, method)

    print("\nSorted Array:", sorted_arr)
    print(f"Number of Comparisons: {comparisons}")

if __name__ == "__main__":
    main()
