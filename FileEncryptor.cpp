#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;


bool IsFileExist(const string& name) {
    ifstream ifile;
    ifile.open(name);
    if (ifile) {
        return true;
    }
    else {
        return false;
    }
}


void EncryptFile(string InputFile, string outputname, int key) {
    char c;
    ifstream fin;
    ofstream fout; 

    fin.open(InputFile.c_str(), ios::binary);
    InputFile = outputname;
    fout.open(InputFile.c_str(), ios::binary);
    while (!fin.eof()) {
        fin >> noskipws >> c;
        int temp = (c + key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();
}

void DecryptFile(string InputFile, string outputname, int key) {
    char c;
    ifstream fin; 
    ofstream fout;

    fin.open(InputFile.c_str(), ios::binary);
    InputFile = outputname;
    fout.open(InputFile.c_str(), ios::binary);

    while (!fin.eof()) {
        fin >> noskipws >> c;
        int temp = (c - key);
        fout << (char)temp;
    }

    fin.close();
    fout.close();
}

void RunProgram() {

    int answer;
    string name;

    cout << "[1] Encrypt a File" << endl;
    cout << "[2] Decrypt a File" << endl;
    cin >> answer;
    
    if (answer != 1 && answer != 2) {
        cout << "Invaild Answer" << endl;
        cin.clear();
        cin.ignore(40, '\n');
        return;
    }
    
    int key;
    string InputFile;

    cout << "Enter File Name: " << endl;
    cin >> InputFile;
    if (!IsFileExist(InputFile)) {
        cout << "Error File does not Exist (File not Found)";
        return;
    }

    cout << "Enter Encryption Key (only numbers): " << endl;
    cin >> key;

    if (key < 4) {
        cout << "Key is to short (only numbers)" << endl;
        cin.clear();
        cin.ignore(40, '\n');
        return;
    }
    
    cout << "Any Output File Name: " << endl;
    cin >> name;

    if (name.length() < 1) {
        cout << "No output file name" << endl;
        cin.clear();
        cin.ignore(40, '\n');
        return;
    }

    if (IsFileExist(name)) {
        cout << "Output file name already Exist!" << endl;
        cin.clear();
        cin.ignore(40, '\n');
        return;
    }

    if (answer == 1) {
        EncryptFile(InputFile, name, key);
    }
    else {
        DecryptFile(InputFile, name, key);
    }
}


int main()
{
    while (true) {
        system("cls");
        RunProgram(); 
       _getch();
    }

    return 0;   
}

