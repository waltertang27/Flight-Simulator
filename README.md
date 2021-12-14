# vanshg3-vkowdle2-waltert3-ssg6 (Phantom Troupe)
Final Project for vanshg3-vkowdle2-waltert3-ssg6

LINK TO DEMO: https://drive.google.com/file/d/1IIR77zn1LmBgwcYqQT09z3_5D2exTzDM/view?usp=sharing

## Authors
- Varun Kowdle (vkowdle2)
- Praneeth Guduguntla (ssg6)
- Walter Tang (waltert3)
- Vansh Gupta (vanshg3)

## Overview
This program allows individuals to find the best routes to their destinations and plan theur next trip on what activities they want to do. In this program, we have provided three scripts that allows users to determine a depth-firtst path between two airports, the shortest path between two airports, and given a number and a location, they will be given the different potential round trips they can take. Our implementation of this program begins with our graph class. Given a text file containing a flights destinations and locations, we are able to parse the data and store it in a hash map consisting of name and a vector continaing the destination airports and its distance. Using this data, we apply our traversal and cycle detection algorithms to provide the user with the necessary outputs. 

## Running the program
To run this program uncomment the function that you desire. From there, in the input section inside of main.cpp include the desired inputs depending on each function. For DFS and Dijkstra's, include the start and end airports. For Tarjan's inlcude the start airport and the length of the cycle. Lastly, run "make routes" to run the program. To test the test suite, run "make test".



## Linkage, Location, and Results
In our project, our main code base resides within graph.cpp. Here, our traversals and various alorithms reside, allowing the user to run the input data. Our input data is stored in data.txt. Every time the data is parsed, it is stored in a hashmap containing map<string, vector<pair<string, double>>. This stores the destination airport with the distances between them as a pair. The results of our major code base and data is stored in Results.md. 

## Citations
# vanshg3-vkowdle2-waltert3-ssg6 (Phantom Troupe)
Final Project for vanshg3-vkowdle2-waltert3-ssg6


## Results
After taking time and devloping our algorithms to analyze the various routes flights can take from a source airports, we wera able to develop a functioning program that allows users to find a path from airport a to b, find the shortest path from airport a to b, and given a number and a location, they will be given the different potential round trips they can take. Throughout this process we feel that we met the goal outlined in our project proposal. This includes our DFS traversal and two algorithms (Dijkstras and Tarjans). Moreover, our program takes in a data.txt file and converts it into the necessary data structure to hold a airport and a vector containing a destination airport with the correct distance. When testing our program against our test suite and cache data, our programs run accordingly to the test suite. If you also trace our searches and algorithms by hand, you will see that the same outpute arises. To test our program using the make file, type - make test.d
