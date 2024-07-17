#pragma once
#include "media.h"

using namespace std;

class Video : public Media {
private:
    string resolution;
    string format;
    string quality;

public:
    Video(const string& id = "", const string& name = "", int time = 0,
        const string& res = "", const string& fmt = "", const string& qual = "")
        : Media(id, name, time), resolution(res), format(fmt), quality(qual) {}

    string getType() const override {
        return "Video";
    }

    void readData(istream& in) override {
        Media::readData(in);
        getline(in, resolution);
        getline(in, format);
        getline(in, quality);
    }

    void writeData(ostream& out) const override {
        Media::writeData(out);
        out << resolution << endl;
        out << format << endl;
        out << quality << endl;
    }
};
