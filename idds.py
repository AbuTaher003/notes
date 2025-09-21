def dls(graph, node, goal, limit):   # Depth Limited Search
    if node == goal:
        return [node]
    if limit <= 0:
        return None
    for neighbor in graph.get(node, []):
        path = dls(graph, neighbor, goal, limit - 1)
        if path:
            return [node] + path
    return None


def ids(graph, start, goal, max_depth):  # Iterative Deepening Search
    for limit in range(max_depth + 1):
        path = dls(graph, start, goal, limit)
        if path:
            return path, limit
    return None, None


# --- Input ---
s = input("Enter graph (ex: A:B,C B:D C:D D:E E:): ")
graph = {}
for p in s.split():
    node, neighbors = p.split(":")
    graph[node] = neighbors.split(",") if neighbors else []

start, goal, max_depth = "A", "E", 5

path, depth = ids(graph, start, goal, max_depth)

if path:
    print("Path found:", path, "at depth", depth)
else:
    print("Goal not found (max depth reached)")
