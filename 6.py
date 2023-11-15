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
