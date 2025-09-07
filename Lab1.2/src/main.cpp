#include "student.hpp"
#include "instructor.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    try {
        // Create people using CSV strings instead of vectors
        unique_ptr<Person> s = make_unique<Student>(
            1, "Ada", "ada@uni.edu", 2026, "CS101,MATH200");

        unique_ptr<Person> i = make_unique<Instructor>(
            2, "Grace", "grace@uni.edu", "Room 314", "CS101");

        // JSON serialization
        nlohmann::json j = nlohmann::json::array();
        j.push_back(s->to_json());
        j.push_back(i->to_json());
        cout << "JSON:\n" << j.dump(2) << "\n\n";

        // YAML serialization
        YAML::Node y;
        y.push_back(s->to_yaml());
        y.push_back(i->to_yaml());
        cout << "YAML:\n" << YAML::Dump(y) << "\n";

        // CSV serialization
        cout << "\nCSV (Student):\n";
        Student tmpS(99,"Tmp","tmp@uni.edu",2030,"CS105,CS106");
        cout << tmpS.csv_header() << "\n";
        cout << static_cast<Student&>(*s).csv_row() << "\n";

        cout << "\nCSV (Instructor):\n";
        Instructor tmpI(98,"TmpI","tmpI@uni.edu","Room 1","CS201");
        cout << tmpI.csv_header() << "\n";
        cout << static_cast<Instructor&>(*i).csv_row() << "\n";
    } 
    catch (const ValidationError& e) {
        cerr << "ValidationError: " << e.what() << "\n";
        return 2;
    } 
    catch (const SerializationError& e) {
        cerr << "SerializationError: " << e.what() << "\n";
        return 3;
    } 
    catch (const exception& e) {
        cerr << "Unhandled std::exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}