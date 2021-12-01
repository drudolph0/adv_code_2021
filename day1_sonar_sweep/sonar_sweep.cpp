#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

auto file2vec() {
    vector<int> vec;
    string line;
    ifstream myfile ("input.txt");
    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(0);
    }
    while (getline(myfile,line))
        vec.push_back(stoi(line));
    myfile.close();

    return vec;
}

int calcDepthMeasureIncr(const vector<int>& vec) {
    int prev = -1;
    int counter = 0;
    for(const auto& cur : vec) {
        if(prev > -1 && cur > prev) counter++;
        prev = cur;
    }
    return counter;
}

auto slidingWindow(const vector<int>& vec) {
    vector<int> out;
    for(auto it = vec.cbegin(); it != vec.cend() - 2; ++it) {
        int sum = *it + *(it+1) + *(it+2);
        out.push_back(sum);
    }
    return out;
}

int main () {
    auto vec = file2vec();
    vec = slidingWindow(vec);
    auto depth = calcDepthMeasureIncr(vec);
    cout << "max depth: " << depth << endl;

  return 0;
}



