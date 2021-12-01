#include <iostream>
#include <fstream>

using namespace std;

int main () {
  string line;
  ifstream myfile ("input.txt");
  int counter, cur;
  int prev = -1;

  if (!myfile.is_open()) {
    cout << "Unable to open file" << endl; 
    return 0;
  }

  while (getline(myfile,line)) {
    cur = stoi(line);
    if(prev > -1 && cur > prev) counter++;
    prev = cur;
  }
  cout << counter << endl;
  myfile.close();

  return 0;
}