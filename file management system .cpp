#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>

using namespace std;

// Function to create a new file
void createFile() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ofstream file(filename);
    if (file.is_open()) {
        cout << "File created successfully!" << endl;
        file.close();
    } else {
        cout << "Unable to create file." << endl;
    }
}

// Function to delete a file
void deleteFile() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully!" << endl;
    } else {
        cout << "Unable to delete file." << endl;
    }
}

// Function to list all files in a directory
void listFiles() {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            cout << ent->d_name << endl;
        }
        closedir(dir);
    } else {
        cout << "Unable to open directory." << endl;
    }
}

// Function to search for a specific file
void searchFile() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    if (file.is_open()) {
        cout << "File found!" << endl;
        file.close();
    } else {
        cout << "File not found." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "File Management System" << endl;
        cout << "1. Create a new file" << endl;
        cout << "2. Delete a file" << endl;
        cout << "3. List all files" << endl;
        cout << "4. Search for a file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                listFiles();
                break;
            case 4:
                searchFile();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
