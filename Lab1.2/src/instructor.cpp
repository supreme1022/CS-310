#include "instructor.hpp"

nlohmann::json Instructor::to_json() const {
    return {
        {"role", role()},
        {"id", id_},
        {"name", name_},
        {"email", email_},
        {"office", office_},
        {"teaches", teaches_csv_}
    };
}

Instructor Instructor::from_json(const nlohmann::json& j) {
    if (!j.contains("id") || !j.contains("name") || !j.contains("email") || !j.contains("office")) {
        throw ValidationError("Missing required field in Instructor::from_json");
    }
    return Instructor(
        j.at("id").get<int>(),
        j.at("name").get<string>(),
        j.at("email").get<string>(),
        j.at("office").get<string>(),
        j.value("teaches", "")
    );
}

YAML::Node Instructor::to_yaml() const {
    YAML::Node n;
    n["role"] = role();
    n["id"] = id_;
    n["name"] = name_;
    n["email"] = email_;
    n["office"] = office_;
    n["teaches"] = teaches_csv_;
    return n;
}

string Instructor::csv_header() const {
    return "role,id,name,email,office,teaches";
}

string Instructor::csv_row() const {
    return role() + "," + to_string(id_) + "," +
           csv_escape(name_) + "," + csv_escape(email_) + "," +
           csv_escape(office_) + "," + csv_escape(teaches_csv_);
}