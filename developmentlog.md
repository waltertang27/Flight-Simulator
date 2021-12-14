# CS 225 Data Structures

# Development Log (vanshg3-vkowdle2-waltert3-ssg6)

1. **Week of Nov 8th** 
Began drafting out project proposal. This consisted of gathering the amount owed from country to country and making a graph based off of that. The dataset that we found is a bit interesting regarding the various ways it is organized, so it might be a challenge to extract the necessary information.
2. **Week of Nov 15th** 
Finished up our project proposal which finalized how we would store graph nodes and search amongst them. Moreover, we decided how we would detect circles of debt amongst every country to make sure we don’t run into any issues. As a group, we decided that we will use DFS as our search algorithm and Tarjan’s cycle detection/Dijkstras shortest path algorithm for our two external algorithms. 
3. **Week of Nov 22nd**
Nothing was accomplished due to thanksgiving break

4. **Week of Nov 29th**
As we began to work on our project, we realized that our data was to obscure to create weighted graph with edges resembling the debt from one country to another country. Developing the graph with this dataset was not feasible, so we decided that we will change our proposal in order to use a dataset that we can apply our constructors and algorithms to. Instead of using a dataset representing debt, we decided that we will use a data set that contained flights from one location to another. With this dataset, we are able to apply our build a graph with a weighted edge and apply DFS, Dijkstra's, and Tarjan's algorithms to. With this new data set, we were able to get a few things done by the mid point chek in. Walter and Varun worked on functions that involved parcing the input data files and storing them into the appropriate data structures. Vansh and Praneeth were able to get a graph constuctor and DFS method working. During the chek-in our constructor was able to create a weighted graph from country to country, and DFS through a test case. Furthermore, one problem that was resolved during our midpoint check in was our graph constructor being able to created a weighted graph with distances.

5. **Week of Dec 6th**
This week consisted of implementing the core functionality of the program which includes our two algorithms - Dijkstras and Tarjans. From the previous week, we were able to fix our bugs that prevented us from generating a weighted graph. With this in place, Varun and Vansh were able to develop the shortest path algorithm from country A to country B. Moreover, Praneeth and Walter were able to finish Tarjan's cycle detection algorithm. Provided number X and starting country, this program returns a list of iteniraries containing X amount of stops within the country. In addition to implemting these algorithms, both groups developed test cases. These test cases will help identify any bugs or defects in the program. We hope to continue testing this week and clear up any last minute changes. 

6. **Week of Dec 13th**
Today, we finished up the project which includes updating any necessary code bases, data parcing, or test cases. Moreover we finished recording our visual presentation for the project. Finally, we wrapped up any documentation and readme files. 
