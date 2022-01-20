
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool parse_params(int argc, char* argv[], string& dict_path, string& word, string& translation,
                  vector<string>& sentence);
vector<pair<string, string>> open_dictionary(const string& path);
void                         save_dictionary(const string& path, const vector<pair<string, string>>& dict);
void translate(const vector<string>& sentence, const vector<pair<string, string>>& dict);

int main(int argc, char* argv[]) {
    string         dict_path, word, translation;
    vector<string> sentence;

    if (!parse_params(argc, argv, dict_path, word, translation, sentence)) {
        return -1;
    }

    vector<pair<string, string>> dict;

    if (!dict_path.empty()) {
        dict = open_dictionary(dict_path);
    }

    if (!word.empty() && !translation.empty()) {
        dict.emplace_back(word, translation);

        if (!dict_path.empty()) {
            save_dictionary(dict_path, dict);
        }
    }

    if (!sentence.empty()) {
        translate(sentence, dict);
    }

    return 0;
}

bool parse_params(int argc, char* argv[], string& dict_path, string& word, string& translation,
                  vector<string>& sentence) {
    for (auto i = 1; i < argc; ++i) {
        std::string option = argv[i];

        if (option == "-d" && (i + 1) < argc) {
            dict_path = argv[++i];
        }
        else if (option == "-a" && (i + 2) < argc) {
            word        = argv[++i];
            translation = argv[++i];
        }
        else {
            sentence.emplace_back(argv[i]);
        }
    }

    if (dict_path.empty()) {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }

    return true;
}

vector<pair<string, string>> open_dictionary(const string& path) {
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    if (!file.is_open()) {
        return dict;
    }

    while (!file.eof()) {
        string word;
        file >> word;

        string translation;
        file >> translation;

        if (word.empty() || translation.empty()) {
            break;
        }

        pair<string, string> tmp { word, translation };
        dict.emplace_back(tmp);
    }
    file.close();

    return dict;
}

void save_dictionary(const string& path, const vector<pair<string, string>>& dict) {
    fstream file { path, ios_base::out | ios_base::trunc };

    for (auto word_translation : dict) {
        file << word_translation.first << " " << word_translation.second << std::endl;
    }
    file.close();
}

void translate(const vector<string>& sentence, const vector<pair<string, string>>& dict) {
    for (auto word : sentence) {
        bool find = false;
        for (auto word_translation : dict) {
            if (word == word_translation.first) {
                cout << word_translation.second << " ";
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "???"
                 << " ";
        }
    }
    cout << endl;
}