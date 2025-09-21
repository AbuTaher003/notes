def depth_limited_search(graph, start, goal, limit):
    if start == goal:  # যদি শুরু আর goal একই হয়
        return [start]
    if limit <= 0:     # depth শেষ হয়ে গেলে
        return None
    
    for neighbor in graph.get(start, []):
        path = depth_limited_search(graph, neighbor, goal, limit - 1)
        if path:  # path পাওয়া গেলে
            return [start] + path
    return None


# ----- Input নেওয়া ----- 
graph = {}
s = input("Enter graph (format A:B,C B:D ...): ")  
for p in s.split():
    node, neighbor = p.split(":")
    if neighbor:
        graph[node] = [n.strip() for n in neighbor.split(",") if n.strip()]
    else:
        graph[node] = []


start_node = "A"
goal_node = "E"
depth_limit = 3   # limit ঠিক মতো বড় রাখ

result = depth_limited_search(graph, start_node, goal_node, depth_limit)

if result:
    print("Path found:", result)
else:
    print("No path found within depth limit.")
