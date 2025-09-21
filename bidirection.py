from collections import deque

def bidirectional_bfs(graph, start, goal):
    if start == goal:
        return [start]

    # দুইদিকের visited আর queue
    front, back = {start}, {goal}
    q1, q2 = deque([start]), deque([goal])

    while q1 and q2:
        # এক ধাপ সামনে থেকে
        for _ in range(len(q1)):
            node = q1.popleft()
            for nei in graph.get(node, []):
                if nei in back:
                    return f"Path found via {nei}"
                if nei not in front:
                    front.add(nei)
                    q1.append(nei)

        # এক ধাপ পেছন থেকে
        for _ in range(len(q2)):
            node = q2.popleft()
            for nei in graph.get(node, []):
                if nei in front:
                    return f"Path found via {nei}"
                if nei not in back:
                    back.add(nei)
                    q2.append(nei)

    return "No path found"

# --- Input ---
s = input("Graph: ")   # Example: A:B,C B:D,E C:F D: E: F:
graph = {}
for p in s.split():
    node, nei = p.split(":")
    graph[node] = nei.split(",") if nei else []

start = input("Start node: ")
goal = input("Goal node: ")

print(bidirectional_bfs(graph, start, goal))
