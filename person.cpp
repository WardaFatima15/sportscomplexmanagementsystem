#pragma once
#include <iostream>
#include <string>
using namespace std;
class person {
protected:
    int id;
    string name;
    int age;
    string phoneNumber;

public:
    // Constructors
    person() {
        id = 0;
        age = 0;
    }

    person(int iid, string namee, int agee, string phnnum) {
        id = iid;
        name = namee;
        age = agee;
        phoneNumber = phnnum;
    }

    // Setters
    void setId(int iid)a {
        id = iid;
    }

    void setName(string namee) {
        name = namee;
    }

    void setAge(int agee) {
        age = agee;
    }

    void setPhoneNumber(string phnnum) {
        phoneNumber = phnnum;
    }

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }
};