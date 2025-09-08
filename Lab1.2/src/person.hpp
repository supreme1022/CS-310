#pragma once
#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <yaml-cpp/yaml.h>
#include "exceptions.hpp"

using namespace std;

class Person {
protected:
    int id_;
    string name_;
    string email_;
public:
    Person(int id, string name, string email)
    : id_(id), name_(name), email_(email)
{
    if (id < 0) throw ValidationError("id cannot be negative");
    if (name.empty()) throw ValidationError("name cannot be empty");
    if (email.empty()) throw ValidationError("email cannot be empty");
    if (email.find('@') == string::npos) 
        throw ValidationError("email must contain '@'");
}


    // getters
    int id() const { return id_; }
    string name() const { return name_; }
    string email() const { return email_; }

    virtual string role() const = 0;
    virtual nlohmann::json to_json() const = 0;
    virtual YAML::Node to_yaml() const = 0;
    virtual string csv_header() const = 0;
    virtual string csv_row() const = 0;
    virtual ~Person() {}
};