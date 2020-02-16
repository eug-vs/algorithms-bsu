class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        if value < self.value:
            if not self.left:
                self.left = Node(value)
            else:
                self.left.insert(value)
        elif value > self.value:
            if not self.right:
                self.right = Node(value)
            else:
                self.right.insert(value)

    def traversal(self, results):
        results.append(str(self.value))
        if self.left:
            self.left.traversal(results)
        if self.right:
            self.right.traversal(results)


with open("input.txt", "r") as input, open("output.txt", "w+") as output:
    root = Node(int(input.readline()))
    results = []
    for line in input.readlines():
        root.insert(int(line))
    root.traversal(results)
    output.write('\n'.join(results))

