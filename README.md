Our clothing store program that is named as NoCashier Clothing Store is in C++, and is a command-line based program that simulates the functionality of a retail clothing store. This program allows customers to browse through a virtual catalog of clothing items and make purchases. The program also allows customers to search through women, men and kids section of clothing and choosing if they want to buy from new merch or the merch on sale. It manage the delivery of orders, including adding new orders, viewing user’s complete orders, and even gift it to someone living in another city.
This program is written in C++, which is a powerful and efficient programming language. C++ is known for its speed and performance, making it a great choice for building a program that needs to handle a large amount of data, such as a clothing store program.
The program does not have a graphical user interface (GUI) and is operated via command-line inputs, making it a more efficient program for managing the store inventory. The program can also generate orders which are stored in a link list that is a type of data structure. It generates the bill including 7.5% GST so everyone pays taxes and our country’s economy prosper
The following program allows customers to place an order by giving item code. Program will check if the input item code is valid or not and will generate an invoice for the items purchased.
Overall, our clothing store program in C++ is a useful tool for managing retail clothing stores. It streamlines the process of managing a clothing store and allows store owners to make their store efficient as it will reduce human work and lessen the need of manual work. 

Implemented Data Structures:

•	Single Linked List:
The program uses linked lists to manage customer information and orders. Linked lists are a data structure that allows for efficient insertion and deletion of elements.
The following data is saved in the linked List:
[1]	Product code no
[2]	Product name
[3]	Product price
[4]	Distance of delivery
[5]	Time Taken for delivery
[6]	Delivery Charges
•	Graphs:
Graphs has been used in the project to show the areas where the parcel can be delivered. Graphs are represented through adjacency matrix.
•	Prim’s algorithm:
Prim's algorithm is a greedy algorithm for finding the minimum spanning tree of a weighted undirected graph. The algorithm starts by selecting an arbitrary vertex from the graph and adding it to a growing tree. Then, at each step, the algorithm looks at all of the edges that connect the tree to vertices not yet in the tree and selects the edge with the smallest weight. The vertex at the other end of this edge is then added to the tree, and the process is repeated until all vertices are in the tree.
The key idea behind Prim's algorithm is that at each step, we are adding a vertex to the tree that is connected to the tree by the minimum-weight edge. This ensures that the tree will have the minimum total weight of any spanning tree that can be formed from the graph.
•	Dijkstra’s algorithm:
Dijkstra's algorithm is used to implement efficient searching and navigation within the system. Dijkstra's algorithm is a shortest path algorithm that can be used to find the shortest path between two nodes in a graph. It is a graph search algorithm that solves the single-source shortest path problem for a graph with non-negative edge weights, producing a shortest path tree. This algorithm is often used in routing and as a subroutine in other graph algorithms. The nodes are represented as cities and this algorithm helps to provide the distance between cities.                 
             
Implemented Methods:
•	Recursion:
Recursion is a technique where a function calls itself in order to solve a problem or perform a task. The key idea behind recursion is that a problem can be broken down into smaller and smaller sub problems, until it becomes simple enough to be solved directly. A function that uses recursion is called a recursive function, and the process of calling a function in this way is known as recursion. A recursive function has two main components: a base case and a recursive case. The base case is the simplest possible version of the problem that can be solved directly, without the need for further recursion. The recursive case is the case where the function calls itself with a slightly simpler version of the problem.

•	Composition:
Composition is a technique that allows you to combine objects or classes to create new, more complex objects or classes. The key idea behind composition is that you can use the properties and behaviors of existing objects or classes to build new ones, without having to create everything from scratch

•	Iteration:
Iteration is the process of repeatedly executing a block of code until a certain condition is met. The most common way to perform iteration in most programming languages is to use a loop, such as a for loop or a while loop. A for loop is used to iterate over a sequence. If elements, such as a list, an array, or a string. A while Loop, on the other hand, is used to iterate as long as a certain condition is true.

•	Encapsulation:
Encapsulation is a technique that allows you to bundle the data and behavior of an object into a single unit, and hide the implementation details from the outside world. This is done by using access modifiers such as public, private, and protected, which control who can access the members (variables and methods) of a class.
 
•	Conditional-Statements:
Conditional statements are used to control the flow of execution based on whether a certain condition is true or false. The most common types of conditional statements are the if-else and switch-case statements. The if-else statement is used to check a single condition and execute a block of code if the condition is true, and another block of code if the condition is false. The switch-case statement is a way of selecting one of many blocks of code to execute

SUMMARY:
The TopSol Clothing Store program is a unique and efficient solution for managing a retail clothing store. This command-line based program simulates the functionality of a physical store, making it an ideal tool for both customers and store owners. One of the key highlights of the TopSol Clothing Store program is its capability to calculate GST on the final bill, making it a comprehensive solution for store management. It streamlines the process of managing a clothing store and makes it more efficient by reducing manual work, making it a great tool for both customers and store managers having features of data structures which is the basic requirement of this project.
