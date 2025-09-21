def dls(graph, start, goal, limit):
    if start == goal:
        return [start]
    if limit <= 0:
        return None
    for neighbor in graph.get(start, []):
        path = dls(graph, neighbor, goal, limit - 1)
        if path:
            return [start] + path
    return None

graph = {}

str = input("Enter Graph: ")

for p in str.split():
    node, neighbor = p.split(":")
    if neighbor : 
        graph[node] = [n.strip() for n in neighbor.split(",") if n.strip()]

    else: 
        graph[node] = []

start_node = 'A'
goal_node = 'E'
depth_limit = 3

result = dls(graph, start_node, goal_node, depth_limit)

if result: 
    print("Path found: ", result)
else :
    print("No path found within depth limit")