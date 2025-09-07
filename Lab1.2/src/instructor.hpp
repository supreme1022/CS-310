#pragma once
#include "person.hpp"
#include "csv.hpp"

class Instructor : public Person {
protected:
    string office_;
    string teaches_csv_;
public:
    Instructor(int id, string name, string email, string office, string teaches_csv = "")
        : Person(id, name, email), office_(office), teaches_csv_(teaches_csv) {}

    string role() const override { return "Instructor"; }

    // getters
    string office() const { return office_; }
    string teaches_csv() const { return teaches_csv_; }

    nlohmann::json to_json() const override;
    static Instructor from_json(const nlohmann::json& j);

    YAML::Node to_yaml() const override;
    string csv_header() const override;
    string csv_row() const override;
};