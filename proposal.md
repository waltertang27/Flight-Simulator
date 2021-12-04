# CS 225 Data Structures

# Project Proposal (vanshg3-vkowdle2-waltert3-ssg6)

## Leading Question
Covid-19 significantly diminished our ability to travel for a couple years, but as borders finally begin to open up and travelling has finally become safer, we wanted to help people find the best routes to their decisions or even help them plan their next trip based on what they want to do. We wanted to determine, what routes can we take to fly from one place to another? Our final deliverable will be a tool that holds airport flight information and can determine the shortest path  one can take to reach another destination. This will be useful to minimize the traveling distance between two destinations. The final deliverable will also be able to find the different potential round trips given a number of locations that someone wants to visit. Our tool can be used to plan vacations so the travelers can have the most efficient method of transportation. 


## Data 
Our dataset will primarily consist of the latest data from this organization which pieces together a curated list of flight destinations from start and end destinations. There are several steps required for us to make this data usable and accurate. 
First, we will iterate through every line in the data file, and extract the airplane code for the source airport and the destination airport. Once we get these values, we will convert the airport codes to the actual airport names using another map that maps an airport code to the airport name.
We will then store the graph in a hash map described below:


map<string, vector<pair<string, double>>  -> this one stores the source airport, and the destination airport with the distance between them as a pair


Every key will be the name of an airport the maps to a list of all of the connecting airports. The weighted edges between two nodes in the graph will represent the distance between the two airports. 

## Graph Algorithm
Traversal: We will be implementing DFS as our traversal. The inputs to the DFS will be the starting node and the ending node that we want to traverse to. Each node contains an airport and its information which indicates if there is a flight from the airport to another airport. The output of the traversal at every iteration is the current node which is an airport and its information and distance.


First Algorithm: The first algorithm we will implement is Dijkstra’s Algorithm which will help us find the shortest path between two countries in the flight graph. This will be useful to figure out, given two airports, how can we get from airport A to Airport B in the shortest amount of travel distance. This algorithm, given airports A and C, would return a list of the shortest path from A to C based on the weighted edges (distances between the airports). The inputs of the algorithm are two airports and the output is a list of airport nodes in the shortest path between the two airports. The time complexity is O(E + VlogV) if E is the number of edges and V is the number of countries. 


Second Algorithm: Our other algorithm would be Tarjan's strongly connected components algorithm. This algorithm is able to detect strongly connected components in our graph which indicates whether a cycle is present within our graph. Suppose we want to find all the possible paths a person can fly if they want to visit multiple cities on a round trip and go back to the original. This algorithm will give us the different cycles that could exist in this graph based specifically on the number of stops the user inputs. We could use a DFS, as it produces a tree, and we can check if there is a cycle by seeing if there is a back edge in the graph, which is a joint node to itself or an ancestor in the tree from DFS. This would have a O(|V| + |E|) runtime. We need to run a DFS from every unvisited node, so our input could be any point in the graph. We would output the different paths that the user will take as a list of lists of the edges.

## Timeline
**11/08:** Proposal Deadline\
**11/18:** Having a processing pipeline that is able to load the data in an efficient manner, read through every row, clean any bad parts of the data and be ready to add elements to the graph.\
**11/22:** Write and implement any necessary test cases to test edge behaviour and general behavior. Having simpler methods of graph data structure complete. Such methods would be constructor, add, remove, update, and find. \
**11/30:** Write and implement any necessary test cases to test edge behaviour and general behavior. Have a DFS iterator that can easily traverse both arrays depending on how the user wants it implemented. Develop topological sort and Djstrika's algorithms to be able to organize the graphs information. Have an MVP ready by mid point check-ins to keep pace with the project’s needs.\
**12/07:** Write and implement any necessary test cases to test edge behaviour and general behavior. Implement the search algorithm described above and be able to find any ways to improve efficiency if possible. Begin to get the project wrapped up by the final deadline.\
**12/13:** Build out all necessary documentation related to the project that will allow someone to run and test the application. Check for code quality (add comments, remove unnecessary functions, follow good naming conventions. Add additional test cases to test suite to test project in its entirety.


Varun Kowdle, vkowdle2\
Vansh Gupta, vanshg3\
Walter Tang, waltert3
