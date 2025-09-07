#include <catch2/catch_test_macros.hpp>
#include "student.hpp"
#include "instructor.hpp"

TEST_CASE("Student JSON serialization") {
    Student s(10,"Alice","alice@uni.edu",2027,"CS101,HIST110");
    auto j = s.to_json();
    CHECK(j.at("role") == "Student");
    CHECK(j.at("name") == "Alice");
    CHECK(j.at("grad_year") == 2027);
}

TEST_CASE("Instructor YAML serialization") {
    Instructor i(11,"Bob","bob@uni.edu","C-210","CS101");
    auto y = i.to_yaml();
    CHECK(y["role"].as<std::string>() == "Instructor");
    CHECK(y["office"].as<std::string>() == "C-210");
}

TEST_CASE("CSV escaping handles commas and quotes") {
    Student s(12,"Eve, \"The Great\"","eve@uni.edu",2028,"CS,101;AI\"Lab");
    auto row = s.csv_row();
    REQUIRE(row.find("\"Eve, \"\"The Great\"\"\"") != std::string::npos);
}

TEST_CASE("Validation throws on bad email") {
    REQUIRE_THROWS_AS(Student(13,"Zed","not-an-email",2026,"MATH100"), ValidationError);
}

TEST_CASE("Student round-trip JSON") {
    Student s(20,"Alice","alice@uni.edu",2027,"CS101,HIST110");
    auto j = s.to_json();
    Student s2 = Student::from_json(j);
    CHECK(s2.to_json() == j);
}

TEST_CASE("Instructor round-trip JSON") {
    Instructor i(21,"Bob","bob@uni.edu","C-210","CS101");
    auto j = i.to_json();
    Instructor i2 = Instructor::from_json(j);
    CHECK(i2.to_json() == j);
}

TEST_CASE("from_json throws on invalid Student") {
    nlohmann::json bad = { {"id", "not-an-int"} };
    CHECK_THROWS_AS(Student::from_json(bad), ValidationError);
}

TEST_CASE("Student JSON round-trip") {
    Student s(10,"Alice","alice@uni.edu",2027,"CS101,HIST110");
    auto j = s.to_json();
    Student s2 = Student::from_json(j);
    CHECK(s2.csv_row() == s.csv_row());
}