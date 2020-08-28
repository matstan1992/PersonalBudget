#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:

    XmlFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName();
    bool isFileEmpty();
};

#endif
