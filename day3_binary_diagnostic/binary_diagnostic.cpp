#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> Bits;

auto file2bits() {
    Bits motions;
    string line;
    ifstream myfile("input.txt");
    if(!myfile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(0);
    }
    while(getline(myfile,line))
        motions.push_back(line);

    myfile.close();

    return motions;
}

void countEpsGam(const Bits& bits, int i, int& e, int& g) {
    for(auto& b : bits) {
        if(*(b.begin()+i) == '1') e++; 
        else g++;
    }
}

auto calcEpsilonAndGamma(const Bits& bits) {
    // Part 1
    std::string epsilon, gamma;
    for(int i = 0; i < bits.front().length(); ++i) {
        int e(0), g(0);
        countEpsGam(bits, i, e, g);
        if(e > g) { epsilon += "1"; gamma += "0"; }
        else { epsilon += "0"; gamma += "1"; }
    }

    return make_pair(epsilon, gamma);
}

auto calcValue(Bits bits, bool oxygen) {
    // Part 2
    int c = 0;
    while(true) {
        int e(0), g(0);
        char digit('0');
        countEpsGam(bits, c, e, g);
        if(oxygen) {
            if(e >= g) digit = '1';
            else digit = '0';
        } else {
            if(g <= e) digit = '0';
            else digit = '1';
        }
        for(auto it = bits.begin(); it != bits.end(); ) {
            if(*((*it).begin()+c) != digit) bits.erase(it);
            else ++it;
            if(bits.size() == 1) return bits.front();
        }
        c++;
        cout << "size: " << bits.size() << endl;
    }
}

int main() {
    auto bits = file2bits();
    auto pair = calcEpsilonAndGamma(bits);
    auto oxygen = calcValue(bits, true);
    auto co2 = calcValue(bits, false);

    auto eps = stoi(pair.first, nullptr, 2);
    auto gam = stoi(pair.second, nullptr, 2);
    auto oxy = stoi(oxygen, nullptr, 2);
    auto c = stoi(co2, nullptr, 2);
    cout << "epsilon: " << pair.first << " int: " << eps << endl;
    cout << "gamma: " << pair.second << " int: " << gam << endl;
    cout << "multi: " << eps*gam << endl;
    cout << "oxygen: " << oxygen << " int: " << oxy << endl;
    cout << "co2: " << co2 << " int: " << c << endl;
    cout << "multi: " << oxy*c << endl;


  return 0;
}



