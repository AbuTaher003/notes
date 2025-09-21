from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])

    while queue:
        vertex = queue.popleft()
        if vertex not in visited:
            print(vertex, end = " ")
            visited.add(vertex)
            for neighbors in graph[vertex]:
                if neighbors not in visited:
                    queue.append(neighbors)


str = input("Graph: ")

graph = {}

for p in str.split():
    node , neighbors = p.split(":")
    if neighbors:
        graph[node] = neighbors.split(",")
    else: 
        graph[node] = []

start_node = input("Starting Node: ")
print("BFS traversal: ")
bfs(graph, start_node)

