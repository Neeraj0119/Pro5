#pragma once
#include "media.h"

using namespace std;

class Audio : public Media {
private:
    string format;
    string quality;

public:
    Audio(const string& id = "", const string& name = "", int time = 0,
        const string& fmt = "", const string& qual = "")
        : Media(id, name, time), format(fmt), quality(qual) {}

    string getType() const override {
        return "Audio";
    }

    void readData(istream& in) override {
        Media::readData(in);
        getline(in, format);
        getline(in, quality);
    }

    void writeData(ostream& out) const override {
        Media::writeData(out);
        out << format << endl;
        out << quality << endl;
    }
};
