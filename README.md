# Stromgly_Connected_Component_Cpp
In the following code I use Trees and DFS to represent and traverse the graph, Kosaraju's algorithm to find Strongly Connected Components, Stack for postorder processing, and List2d to store the components.
This code implements finding strongly connected components (SCCs) in a directed graph using Kosaraju's algorithm.

The key components are:
Graph class - Represents the overall graph and coordinates the SCC finding process
Tree class - Represents a directed graph as a binary search tree. Contains the insert, clear, print methods.
List2d class - Represents the list of SCCs. Each component is a linked list, and the components are linked in a 2D list structure.
Stack class - Auxiliary stack used in the algorithm.

The overall flow is:
Read graph from file into two Trees - straight (original) and reversed (with edge directions flipped)
Run DFS on straight Tree, pushing nodes to Stack in postorder
Pop nodes from Stack, run DFS on reversed Tree using popped nodes as roots. Each tree visited forms an SCC.
Add each SCC found in previous step to the List2d of components.
Find largest component in List2d, print details and output to file.

The data set links used here are:
https://snap.stanford.edu/data/web-Google.html
https://snap.stanford.edu/data/ego-Twitter.html
