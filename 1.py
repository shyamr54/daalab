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
