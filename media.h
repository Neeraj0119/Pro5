#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Media {
protected:
    string identifier;
    string accountName;
    int runningTime;

public:
    Media(const string& id = "", const string& name = "", int time = 0)
        : identifier(id), accountName(name), runningTime(time) {}

    virtual ~Media() = default;

    string getIdentifier() const { return identifier; }
    string getAccountName() const { return accountName; }
    int getRunningTime() const { return runningTime; }

    void setIdentifier(const string& id) { identifier = id; }
    void setAccountName(const string& name) { accountName = name; }
    void setRunningTime(int time) { runningTime = time; }

    virtual string getType() const = 0;

    virtual void readData(istream& in) {
        getline(in, identifier);
        getline(in, accountName);
        string timeStr;
        getline(in, timeStr);
        stringstream ss(timeStr);
        ss >> runningTime;
    }

    virtual void writeData(ostream& out) const {
        out << identifier << endl;
        out << accountName << endl;
        out << runningTime << endl;
    }
};
