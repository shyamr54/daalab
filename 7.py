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
