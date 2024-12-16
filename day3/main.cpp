    #include <algorithm>    // std::sort
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include <vector>
#include <regex>

    using namespace std;

    int part1(string line) {

        regex mul_regex(R"(mul\((\d+),(\d+)\))");
        smatch match;
        int total = 0;

        auto begin = sregex_iterator(line.begin(), line.end(), mul_regex);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; it++) {
            smatch match = *it;
            int x = stoi(match.str(1));
            int y = stoi(match.str(2));
            total += x * y;
        }
        return total;
    }

    int main() {

        ifstream f("input");

        // Check if the file is successfully opened
        if (!f.is_open()) {
            cerr << "Error opening the file!" << endl;
            return 1;
        }
        string line;

        // Read the file line by line and construc the data vector
        while (getline(f, line)) {
        }

        int total = part1(line);

        cout << "Total: " << total << endl;
        f.close();
        return 0;
    }