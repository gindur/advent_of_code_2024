#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>    // std::sort
using namespace std;

int main() {
    ifstream f("input1.txt");

    // Check if the file is successfully opened
    if (!f.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    vector<int> array1, array2, result;
    string line;

    // Read the file line by line
    while (getline(f, line)) {
        istringstream iss(line);
        int num1, num2;

        // Read two numbers from each line
        if (iss >> num1 >> num2) {
            array1.push_back(num1);
            array2.push_back(num2);
        }
    }



    f.close(); // Close the file after reading
    cout << array1[0] << " " << array2[0] << endl;
    std::sort (array1.begin(), array1.end());
    std::sort (array2.begin(), array2.end());

    int tot = 0;
    for (int i = 0; i < array1.size(); i++) {
        tot += abs(array1[i] - array2[i]);
    }

    unordered_map<int, int> m;
    for (int i = 0; i < array2.size(); i++) {
        m[array2[i]]++;
    }

    int res = 0;
    for (int i = 0; i < array1.size(); i++) {
        int count = m[array1[i]];
        if (count > 0) {
            res+= count * array1[i];
        }
    } 

    cout << "Total: " << res << endl;

    return 0;
}
