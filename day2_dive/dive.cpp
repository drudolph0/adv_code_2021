#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


enum Motion {
    FOWARD,
    DOWN,
    UP
};

typedef vector<pair<Motion, int>> Motions;

auto line2MotionPair(const string& input) {
    std::string delimiter = " ";
    auto pos = input.find(delimiter);
    std::string comand = input.substr(0, pos);
    Motion motion;
    if(comand == "forward") motion = Motion::FOWARD;
    else if(comand == "down") motion = Motion::DOWN;
    else if(comand == "up") motion = Motion::UP;
    auto digit = stoi(input.substr(pos, input.length()));

    return make_pair(motion, digit);
}

auto file2motions() {
    Motions motions;
    string line;
    ifstream myfile ("input.txt");
    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(0);
    }
    while (getline(myfile,line))
        motions.push_back(line2MotionPair(line));

    myfile.close();

    return motions;
}

auto moveSubmarine(const Motions& motions) {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    for(const auto& m : motions) {
        auto motion = m.first;
        switch(motion) {
            case Motion::FOWARD:
                horizontal += m.second;
                depth += aim*m.second;
                break;
            case Motion::DOWN:
                aim += m.second;
                break;
            case Motion::UP:
                aim -= m.second;
                break;
        }
    }

    return make_pair(horizontal, depth);
}
int main() {
    auto motions = file2motions();
    auto result = moveSubmarine(motions);

    cout << "horizontal: " << result.first << " depth:" << result.second << endl;
    cout << "Multiplied: " << result.first * result.second << endl;

  return 0;
}



