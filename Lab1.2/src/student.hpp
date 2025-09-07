#pragma once
#include "person.hpp"
#include "csv.hpp"

class Student : public Person {
protected:
    int grad_year_;
    string courses_csv_; // courses stored as CSV string
public:
    Student(int id, string name, string email, int grad_year, string courses_csv = "")
        : Person(id, name, email), grad_year_(grad_year), courses_csv_(courses_csv)
    {
        if (grad_year_ < 2000) throw ValidationError("grad_year too small");
    }

    string role() const override { return "Student"; }

    // getters
    int grad_year() const { return grad_year_; }
    string courses_csv() const { return courses_csv_; }

    nlohmann::json to_json() const override;
    static Student from_json(const nlohmann::json& j);

    YAML::Node to_yaml() const override;
    string csv_header() const override;
    string csv_row() const override;
};