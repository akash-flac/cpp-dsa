A **topological sort** is an ordering of the nodes of a directed graph such that if there is a path from node a to node b, then node a appears before node b in the ordering. 
For example, for the following graph
![](attachments/Pasted%20image%2020240530125310.png)

Topological sorting is only possible in **DAGs(Directed Acyclic Graphs)**. The graphs must be directed, as an undirected graph cannot have a node that always comes before the other, and acyclic, as within a cyclic graph no node of the cycle can appear before the other nodes of the cycle in the ordering. 

