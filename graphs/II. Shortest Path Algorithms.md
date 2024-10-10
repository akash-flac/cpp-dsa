In an **==unweighted graph==**, the length of a path equals the number of its edges, and we can simply use breadth-first search(BFS) to find a shortest path.

In a ==**weighted graph**==, the following algorithms can be used:
- **Dijkstra's Algorithm** : Starting node to all nodes of a graph
- **Bellman-Ford Algorithm** : Same as Dijkstra's, but also includes negative edges
- **Floyd-Warshall Algorithm** : All shortest paths between nodes
- **Topological Sort** to find shortest path in a DAG

### Dijkstra's Algorithm
