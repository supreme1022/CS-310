#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

using namespace std;

//Escape a string for CSV
inline string csv_escape(const string& s) {
    if (s.find_first_of(",\"\n") != string::npos) {
        string escaped = "\"";
        for (char c : s) {
            if (c == '"') escaped += "\"\""; // escape quotes
            else escaped += c;
        }
        escaped += "\"";
        return escaped;
    }
    return s;
}

//CSV of people
inline void write_people_csv(const Person** people, int count, const string& filename = "people.csv") {
    ofstream file(filename);
    if (!file.is_open()) throw runtime_error("Unable to open file: " + filename);

    if (count == 0) return;

    
    file << people[0]->csv_header() << "\n";

    
    for (int i = 0; i < count; i++) {
        file << people[i]->csv_row() << "\n";
    }

    file.close();
}