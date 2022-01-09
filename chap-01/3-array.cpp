#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    using namespace std;
    /*
    int array[]    = { 0, 1, 2, 3 };

    for (int val : array) {
        cout << val << endl;
    }
    */
    /*
    int array[50] = {};

    for (int i = 0; i < 50; i++) {
        array[i] = i + 1;
        cout << array[i] << endl;
    }
    */
    vector<int> array;

    if (argc < 2) {
        cerr << "Missing argument" << endl;
        return -1;
    }
    cout << "Argument : " << argv[1] << endl;

    int length = stoi(argv[1]);
    if (length <= 0) {
        cerr << "Length must be > 0" << endl;
        return -1;
    }
    cout << "Conversion : " << length << endl;

    for (int i = 0; i < length; i++) {
        array.emplace_back(i);
    }

    for (int value : array) {
        cout << value << endl;
    }

    return 0;
}
