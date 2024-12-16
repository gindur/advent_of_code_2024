    #include <algorithm>    // std::sort
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include <vector>

    using namespace std;

    int part1(vector<vector<int>> data) {
        int problem = 0;
        for (int i = 0; i < data.size(); i++){
            int current = data[i][0];
            int diff = 0;
            int direction = data[i][0] - data[i][1];
            if (direction == 0) {
                continue;
            }
            if (direction > 0 ){
                direction = -1; // -1 means decreasing
            } else {
                direction = 1; // 1 means increasing
            }
            int j = 0;
            while (j < data[i].size()-1) {
                diff = data[i][j] - data[i][j+1];
                if (diff * direction > 0 || abs(diff) > 3 || abs(diff) == 0) {
                    // fail
                    cout << "Line: " << i << " failed" << endl;
                    problem += 1;
                    break;
                }
                j++;
            }
        }
        return problem;
    }

    int main() {

        ifstream f("input");

        // Check if the file is successfully opened
        if (!f.is_open()) {
            cerr << "Error opening the file!" << endl;
            return 1;
        }

        vector<vector<int>> data = {};
        string line;

        // Read the file line by line and construc the data vector
        while (getline(f, line)) {
            istringstream iss(line);
            vector<int> numbers;
            int num;
            while (iss >> num){
                numbers.push_back(num);
            }
            data.push_back(numbers);
        }

        int problem = part1(data);
        cout << data.size()- problem  << endl;

        return 0;
    }