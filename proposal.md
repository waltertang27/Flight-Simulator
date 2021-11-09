# CS 225 Data Structures

# Project Proposal (vanshg3-vkowdle2-waltert3-ssg6)

## Leading Question
Our final deliverable will consist of a worldwide debt to GDP ratio along with a population search tool. This data can be manipulated by adding, deleting, or searching for various governed bodies. This tool can display information in varying orders depending on how the user wants their data displayed. A successful project will be able to store, update, search, and extract data efficiently and effectively.


## Data 
Our dataset will primarily consist of the latest data from this organization which pieces together a curated list of every nation’s debt and the various creditors that they owe money to. There are several steps required for us to make this data useable and accurate. In order for someone to clone and run our repository, they will need to download this data and add it to their local project as it is quite large to keep in a git repository. We will then build a data processing pipeline that will aggregate all information regarding a country and place them together for easier readability. We will also remove any broken/missing data by simply ignoring it. Currently the data is structured as a CSV with each row representing a country, the creditor they owe money to and how much they owe every year. We will need to iterate through every year and find the cumulative sum based on how much they have paid off and how much they owe for each country. We will load this data into a graph with each country and the edges representing the debt to a given country.

## Graph Algorithms
We want to store data in an AVL tree. We will be doing insertions, rotations, and deletions. For each insertions and deletions, we will take a data piece that we want to insert/delete. The output for these will be void. Rotations don’t need any inputs or outputs. The traversals we plan on using include BFS and DFS to traverse the tree. Traversals don’t require any inputs or outputs and should take O(log n) time. Since we are using an AVL tree, we want rotations to take O(1) time, insertions to take O(log n) time, and deletions to have O(log n) time. In doing so, we are efficiently extracting the data necessary to do any calculations and deliver outputs.


## Timeline
**11/08:** Proposal Deadline\
**11/15:** Having a processing pipeline that is able to load the data in an efficient manner, read through every row, clean any bad parts of the data and be ready to add elements to the graph.\
**11/23:** Write and implement any necessary test cases to test edge behaviour and general behavior. Having simpler methods of graph data structure complete. Such methods would be constructor, add, remove, update, and find. \
**11/30:** Write and implement any necessary test cases to test edge behaviour and general behavior. Have a DFS and BFS iterator that can easily traverse both arrays depending on how the user wants it implemented. Have an MVP ready by mid point check-ins to keep pace with the project’s needs.\
**12/07:** Write and implement any necessary test cases to test edge behaviour and general behavior. Implement the search algorithm described above and be able to find any ways to improve efficiency if possible. Begin to get the project wrapped up by the final deadline.\
**12/13:** Build out all necessary documentation related to the project that will allow someone to run and test the application. Check for code quality (add comments, remove unnecessary functions, follow good naming conventions. Add additional test cases to test suite to test project in its entirety.


Varun Kowdle, vkowdle2\
Vansh Gupta, vanshg3