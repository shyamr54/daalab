import sys
import itertools

class TSP:
    def __init__(self, num_cities, distances):
        self.num_cities = num_cities
        self.distances = distances
        self.visited = [False] * num_cities
        self.min_cost = sys.maxsize
        self.min_path = []

    def branch_and_bound(self):
        self._branch_and_bound(0, 0, [0])

    def _branch_and_bound(self, current_city, current_cost, current_path):
        if len(current_path) == self.num_cities:
            current_cost += self.distances[current_path[-1]][current_path[0]]
            if current_cost < self.min_cost:
                self.min_cost = current_cost
                self.min_path = current_path.copy()
            return

        for next_city in range(self.num_cities):
            if not self.visited[next_city]:
                bound = self.calculate_bound(current_path, current_cost, next_city)
                if bound < self.min_cost:
                    self.visited[next_city] = True
                    current_path.append(next_city)
                    self._branch_and_bound(next_city, current_cost + self.distances[current_city][next_city], current_path)
                    current_path.pop()
                    self.visited[next_city] = False

    def calculate_bound(self, current_path, current_cost, next_city):
        bound = current_cost

        # Lower bound: adding the minimum edge cost from the current city
        bound += min([self.distances[current_city][next_city] for current_city in range(self.num_cities) if current_city not in current_path])

        # Upper bound: adding the minimum edge cost to complete the tour
        bound += min([self.distances[next_city][city] for city in range(self.num_cities) if city not in current_path])

        return bound

def main():
    print("Traveling Salesman Problem Solver (Branch and Bound)")
    num_cities = int(input("Enter the number of cities: "))

    distances = []
    print("Enter the distance matrix (enter -1 for infinity):")
    for i in range(num_cities):
        row = [int(x) for x in input().split()]
        distances.append(row)

    tsp_solver = TSP(num_cities, distances)
    tsp_solver.branch_and_bound()

    print("\nOptimal Path:", tsp_solver.min_path)
    print("Total Cost:", tsp_solver.min_cost)

if __name__ == "__main__":
    main()
