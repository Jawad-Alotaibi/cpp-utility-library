#pragma once

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

namespace FileLibrary
{
    void printFileContent(string fileName)
    {
        fstream myFile;
        myFile.open(fileName, ios::in); // read mode

        if (myFile.is_open())
        {
            string line;

            while (getline(myFile, line)) // means read the first line in myFile file then put it in the line variable
            {
                cout << line << endl;
            }

            myFile.close();
        }
    }

    void loadDataFromFileToVector(string fileName, vector<string> &vFileContent)
    {
        // open the file in the read mode
        // read the data and put it into the vector

        fstream myFile;
        string line;
        myFile.open(fileName, ios::in); // read mode

        while (getline(myFile, line))
        {
            vFileContent.push_back(line);
        }

        myFile.close();
    }

    void saveDataFromVectorToFile(string fileName, vector<string> vFileContent)
    {
        fstream myFile;
        myFile.open(fileName, ios::out); // write mode

        if (myFile.is_open())
        {
            for (string &line : vFileContent)
            {
                if (line != "")
                {
                    myFile << line << endl;
                }
            }
        }
        myFile.close();
    }

    void updateVectorRecord(string fileName, string record, string updatedRecord)
    {
        vector<string> vFileContent;
        loadDataFromFileToVector("MyFile.txt", vFileContent);
        for (string &line : vFileContent)
        {
            if (line == record)
            {
                line = updatedRecord;
            }
        }
        saveDataFromVectorToFile(fileName, vFileContent);
    }

    void deleteVectorRecord(string fileName, string DeletedElement)
    {
        vector<string> vFileContent;
        loadDataFromFileToVector("MyFile.txt", vFileContent);
        for (string &line : vFileContent)
        {
            if (line == DeletedElement)
            {
                line = "";
            }
        }
        saveDataFromVectorToFile(fileName, vFileContent);
    }

    
}