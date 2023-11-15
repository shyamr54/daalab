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