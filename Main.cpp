#include <iostream>
#include <fstream>
#include <vector>
#include "media.h"
#include "audio.h"
#include "video.h"

using namespace std;

int main() {
    ifstream inputFile("pro5data.txt");
    if (!inputFile) {
        cerr << "Cannot open input file" << endl;
        return 1;
    }

    vector<Media*> mediaList;
    char mediaType;

    while (inputFile >> mediaType) {
        inputFile.ignore(); // Ignore newline after mediaType character
        Media* media = nullptr;

        if (mediaType == 'A') {
            media = new Audio();
        }
        else if (mediaType == 'V') {
            media = new Video();
        }

        if (media) {
            media->readData(inputFile);
            mediaList.push_back(media);
        }
    }

    inputFile.close();

    ofstream audioOutput("AudioOutputData.txt");
    ofstream videoOutput("VideoOutputData.txt");

    for (const auto& media : mediaList) {
        if (media->getType() == "Audio") {
            media->writeData(audioOutput);
            audioOutput << "****************************************" << endl;
        }
        else if (media->getType() == "Video") {
            media->writeData(videoOutput);
            videoOutput << "****************************************" << endl;
        }
    }

    audioOutput.close();
    videoOutput.close();

    for (auto& media : mediaList) {
        delete media;
    }

    return 0;
}
