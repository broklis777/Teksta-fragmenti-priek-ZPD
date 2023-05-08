#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;
using namespace std::chrono;
vector<string> getWords(const string& text){
    vector<string> all_words;
    std::string word;
    for (char i: text){
        if (i != ' '){
            word.push_back(i);
        }
        else {
            all_words.push_back(word);
            word.clear();
        }
    }
    return all_words;
}

int main(){
    std::ifstream file("path\to\text\file.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }
    string file_contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    auto start = high_resolution_clock::now();
    vector<string> all = getWords(file_contents);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    auto micro_secs = duration.count();
    cout << "MicroSeconds: " << micro_secs;
    return 0;
}

// The code was made by myself, with some improvements and help from ChatGPT
