#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string normalize_phone_number(string phone_number) {
    if (phone_number.substr(0, 3) == "98+") {
        phone_number.replace(0, 3, "0");
    }
    if (phone_number.substr(0, 2) == "09" && phone_number.length() == 11) {
        return phone_number;
    }
    return "null";
}

int main() {
    ifstream names_file("names.txt");
    ifstream phones_file("phones.txt");
    ofstream result_file("result.json");

    if (!names_file.is_open() || !phones_file.is_open() || !result_file.is_open()) {
        cerr << "sth went wrong" << endl;
        return 1;
    }

    vector<pair<string, string>> name_phone_pairs;
    string name, phone_number;
    while (getline(names_file, name) && getline(phones_file, phone_number)) {
        name_phone_pairs.emplace_back(name, phone_number);
    }

    sort(name_phone_pairs.begin(), name_phone_pairs.end());

    result_file << "{\n";
    for (const auto& [name, phone_number] : name_phone_pairs) {
        result_file << "    \"" << name << "\": \"" << normalize_phone_number(phone_number) << "\",\n";
    }
    result_file << "}\n";

    names_file.close();
    phones_file.close();
    result_file.close();

    return 0;
}
