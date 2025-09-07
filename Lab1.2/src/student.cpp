#include "student.hpp"

nlohmann::json Student::to_json() const {
    return {
        {"role", role()},
        {"id", id_},
        {"name", name_},
        {"email", email_},
        {"grad_year", grad_year_},
        {"courses", courses_csv_}
    };
}

Student Student::from_json(const nlohmann::json& j) {
    if (!j.contains("id") || !j.contains("name") || !j.contains("email") || !j.contains("grad_year")) {
        throw ValidationError("Missing required field in Student::from_json");
    }
    return Student(
        j.at("id").get<int>(),
        j.at("name").get<string>(),
        j.at("email").get<string>(),
        j.at("grad_year").get<int>(),
        j.value("courses", "")
    );
}

YAML::Node Student::to_yaml() const {
    YAML::Node n;
    n["role"] = role();
    n["id"] = id_;
    n["name"] = name_;
    n["email"] = email_;
    n["grad_year"] = grad_year_;
    n["courses"] = courses_csv_;
    return n;
}

string Student::csv_header() const {
    return "role,id,name,email,grad_year,courses";
}

string Student::csv_row() const {
    return role() + "," + to_string(id_) + "," +
           csv_escape(name_) + "," + csv_escape(email_) + "," +
           to_string(grad_year_) + "," + csv_escape(courses_csv_);
}