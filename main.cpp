#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
//Add any includes here

int main() {

  vector<string> countries;
  vector<vector<int> > debt;


  ifstream infile("data.txt");
  if(!infile) {
    cout << "data file can not be opened" << endl;
    return 0;
  }


  string s = "";
  int temp = 0;
  while(getline(infile, s)) {
      cout << s << endl;
      while(infile >> temp) {
        cout << temp << endl;
      }
  }
  infile.close();
  
  return 0;
}
