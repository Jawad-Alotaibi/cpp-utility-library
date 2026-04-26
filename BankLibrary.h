#pragma once

#include <iostream>
#include "MyInputLibrary.h"
#include "StringLibrary.h"
#include "FileLibrary.h"
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
using namespace StringLibrary;
using namespace FileLibrary;

const string FILENAME = "clients.txt";

namespace BankLibrary
{

    struct stClient
    {
        string accountNumber;
        string pinCode;
        string name;
        string phone;
        double accountBalance;
        bool markForDelete = false;
    };

    stClient readNewClient()
    {
        stClient client;

        cout << "Enter Account Number? ";
        getline(cin >> ws, client.accountNumber); // cleans leftover '\n', then reads, then consumes '\n'  → buffer clean

        cout << "Enter PinCode? ";
        getline(cin, client.pinCode); // reads, then consumes '\n' → buffer clean

        cout << "Enter Name? ";
        getline(cin, client.name); // reads, then consumes '\n' → buffer clean

        cout << "Enter Phone? ";
        getline(cin, client.phone); // reads, then consumes '\n' → buffer clean

        cout << "Enter Account Balance? ";
        cin >> client.accountBalance; // reads value, leaves '\n' ⚠️

        return client;
    }
     stClient changeClientRecord(string accountNumber)
    {
        stClient client;
        client.accountNumber = accountNumber;

        cout << "Enter PinCode? ";
        getline(cin >> ws, client.pinCode); // reads, then consumes '\n' → buffer clean

        cout << "Enter Name? ";
        getline(cin, client.name); // reads, then consumes '\n' → buffer clean

        cout << "Enter Phone? ";
        getline(cin, client.phone); // reads, then consumes '\n' → buffer clean

        cout << "Enter Account Balance? ";
        cin >> client.accountBalance; // reads value, leaves '\n' ⚠️

        return client;
    }

    string convertRecordToLine(stClient clientData, string delm = "#//#")
    {
        // string s1 = "";
        // s1 += clientData.accountNumber + delm;
        // s1 += clientData.pinCode + delm;
        // s1 += clientData.name + delm;
        // s1 += clientData.phone;
        // s1 += to_string(clientData.accountBalance);

        return (string)clientData.accountNumber + delm + clientData.pinCode + delm +
               clientData.name + delm + clientData.phone + delm + to_string(clientData.accountBalance);
        ;
    }

    stClient convertLineToRecord(string line, string delm = "#//#")
    {
        stClient client; // declare a structure

        vector<string> vClientData = splitString(line, delm);

        // Validate that we have all required fields
        if (vClientData.size() < 5)
        {
            // Return empty client if line is malformed
            client.accountNumber = "";
            client.pinCode = "";
            client.name = "";
            client.phone = "";
            client.accountBalance = 0;
            return client;
        }

        client.accountNumber = vClientData[0];
        client.pinCode = vClientData[1];
        client.name = vClientData[2];
        client.phone = vClientData[3];

        try
        {
            client.accountBalance = stod(vClientData[4]); // string to double conversion function in c++ called stod
        }
        catch (const invalid_argument &e)
        {
            client.accountBalance = 0;
        }

        return client;
    }

    vector<stClient> loadClientDataFromFile(string FileName)
    {
        fstream file;

        string line = "";
        vector<stClient> vClients;

        file.open(FileName, ios::in);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                vClients.push_back(convertLineToRecord(line));
            }

            file.close();
        }

        return vClients;
    }

    void printClientCard(stClient client)
    {
        int width = 18; // Adjust this number based on your longest label

        cout << endl
             << "The following are client details" << endl
             << endl;
        cout << left << setw(width) << "Account Number:" << client.accountNumber << endl;
        cout << left << setw(width) << "Pin Code:" << client.pinCode << endl;
        cout << left << setw(width) << "Name:" << client.name << endl;
        cout << left << setw(width) << "Phone:" << client.phone << endl;
        cout << left << setw(width) << "Account Balance:" << client.accountBalance << endl;
    }

    void addClientToFile(string fileName, string line)
    {
        fstream file;
        file.open(FILENAME, ios::out | ios::app);

        if (file.is_open())
        {
            file << line << endl;
        }
        file.close();
    }

    void addNewClient()
    {
        stClient client;
        client = readNewClient();
        addClientToFile("clients.txt", convertRecordToLine(client));
    }
    void addClients()
    {
        char wannaAddUser = 'y';

        do
        {
            addNewClient();
            cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
            cin >> wannaAddUser;
        } while (toupper(wannaAddUser) == 'Y');
    }

    void printAllClientsHeader(int clientsNumber)
    {
        cout << "________________________________________________________________________" << endl;
        cout << "\t\tClients list (" << clientsNumber << ") Client(s)." << endl;
        cout << "________________________________________________________________________" << endl;
    }

    void printClientRecord(stClient client)
    {
        cout << "| " << left << setw(10) << client.accountNumber;
        cout << "| " << left << setw(10) << client.pinCode;
        cout << "| " << left << setw(20) << client.name;
        cout << "| " << left << setw(10) << client.phone;
        cout << "| " << left << setw(10) << client.accountBalance << right << setw(1) << "|";
    }

    void printClientsDetails(vector<stClient> clients)
    {

        cout << "| Account Number";
        cout << " | Pin Code";
        cout << " | Client Name";
        cout << " | Phone";
        cout << " | Balance";
        cout << endl
             << "________________________________________________________________________" << endl;

        for (stClient &client : clients)
        {
            printClientRecord(client);
            cout << endl;
        }
    }

    void printAllClients(vector<stClient> clients)
    {
        printAllClientsHeader(clients.size());
        printClientsDetails(clients);
    }

    bool findClientByAccountNumber(string accountNumber, stClient &client)
    {
        vector<stClient> vClients = loadClientDataFromFile(FILENAME);

        for (stClient &c : vClients)
        {
            if (c.accountNumber == accountNumber)
            {
                client = c;
                return true;
            }
        }
        return false;
    }

    bool findClientByAccountNumberWithoutLoadingFromFile(string accountNumber, vector<stClient> vClients, stClient &client)
    {
        for (stClient &c : vClients)
        {
            if (c.accountNumber == accountNumber)
            {
                client = c;
                return true;
            }
        }
        return false;
    }

    void saveClientsToFile(string FileName, vector<stClient> vClients)
    {
        fstream file;
        file.open(FileName, ios::out); // Open in output mode to overwrite the file

        if (file.is_open())
        {
            for (stClient &client : vClients)
            {
                file << convertRecordToLine(client) << endl;
            }
            file.close();
        }
    }

     void saveClientsMarkedToDeleteToFile(string fileName, vector<stClient> vClients)
    {
        fstream file;
        file.open(FILENAME, ios::out); // Open in output mode to overwrite the file

        if (file.is_open())
        {
            for (stClient &client : vClients)
            {
                if(client.markForDelete == false)
                {
                    file << convertRecordToLine(client) << endl;
                }
            }
            file.close();
        }
    }


    bool markClientForDeleteByAccountNumber(string accountNumber, vector <stClient> &vClients)
    {
        for (stClient &c : vClients)
        {
            if (c.accountNumber == accountNumber)
            {
                c.markForDelete = true;
                return true;
            }
        }
        return false;
    }

    bool deleteClientByAccountNumber(string accountNumber, vector<stClient> &vClients)
    {
        stClient client;
        char answer = 'n';

        if (findClientByAccountNumberWithoutLoadingFromFile(accountNumber, vClients, client))
        {
            printClientCard(client);

            cout << "\n\nAre you sure you want to delete this client with this account Number " << client.accountNumber << " y/n ?";
            cin >> answer;

            if (toupper(answer) == 'Y')
            {
                //Mark client for delete
                markClientForDeleteByAccountNumber(accountNumber, vClients);
                saveClientsMarkedToDeleteToFile(FILENAME,vClients);
                
                //Refresh the vector with the new clients without the clients marked for delete
                vClients = loadClientDataFromFile(FILENAME);
                cout << "\n\nClient Deleted Successfully." << endl;
            }
            else 
            cout << "Deleting Was Canceld\n";
            return false;
        }
         else
            cout << "Client with Account Number (" << accountNumber << ") Not Found!" << endl;
        
        return false;
    }

    bool updateClientByAccountNumber(string accountNumber, vector <stClient> &vClients)
    {
        stClient client;
        char answer = 'n';

        if(findClientByAccountNumberWithoutLoadingFromFile(accountNumber, vClients, client))
        {
            printClientCard(client);

            cout << "Are you sure you wanna update this client? Y/N" << endl << endl;
            cin >> answer;

            if(toupper(answer) == 'Y')
            {
                for (stClient &c : vClients)
                {
                    if (c.accountNumber == accountNumber)
                    {   
                        c = changeClientRecord(accountNumber);
                        break;
                    }
                }
                saveClientsToFile(FILENAME, vClients);
                cout << "\n\nClient Updates Successfully." << endl;
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << accountNumber
            << ") is Not Found!" << endl;
        }
            return false;

    }

}