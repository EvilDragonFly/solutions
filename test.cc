#include <iostream>
#include <map>
#include <vector>
#include<algorithm>

using std::cout; using std::cin;
using std::endl; using std::map;
using std::string; using std::vector;

int main(){
    map<string, string> veggy_map = {{"1", "Yam",},
                                     {"2", "Pumpkin",},
                                     {"3", "Ginger",},
                                     {"4", "Melon",},
                                     {"5", "Beetroot",},
                                     {"6", "Spinach",}};


    cout << "Unsorted - " << endl;
    for (const auto & [key, value] : veggy_map) {
        cout << key << " : " << value << endl;
    }

    vector<std::pair<string, string> > arr;
    for (const auto &item : veggy_map) {
        arr.emplace_back(item);
    }

    std::sort(arr.begin(), arr.end(),
              [] (const auto &x, const auto &y) {return x.second < y.second;});

    cout << "Sorted - " << endl;
    for (const auto & [key, value] : arr) {
        cout << key << " : " << value << endl;
    }

    return EXIT_SUCCESS;
}