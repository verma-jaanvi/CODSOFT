#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int key = 1, choice, question, delete_key, edit_key;
    string val;
    map<int, string> myTask;
    map<int, int> mymap; 

start:
    cout << "\n------------------------- TO-DO LIST -------------------------\n";
    cout << "What would you like to do?\n\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
    cout << "\nSelect your choice: ";
    cin >> choice;

  
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice! Please enter a number.\n";
        goto start;
    }

    switch (choice) {
        case 1:
            cout << endl;
            do {
                cin.ignore();
                cout << "Enter Your Task Details: ";
                getline(cin, val);
                if (val.empty()) {
                    cout << "Task cannot be empty. Please enter a valid task.\n";
                } else {
                    myTask.insert({key, val});
                    mymap.insert({key, 0});
                    cout << "Task added successfully as Task-" << key << ".\n";
                    key++;
                }
                cout << "Do you want to add another task? (1=Yes / 0=No): ";
                cin >> question;
            } while (question == 1);
            goto start;
            break;

        case 2:
            cout << endl;
            if (myTask.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "Tasks:\n";
                for (const auto &x : myTask) {
                    cout << "Task-" << x.first << ": " << x.second;
                    if (mymap.at(x.first) == 1) {
                        cout << " [Completed]";
                    } else {
                        cout << " [Pending]";
                    }
                    cout << endl;
                }
            }
            goto start;
            break;

        case 3:
            cout << "\nEnter the task number you want to delete: ";
            cin >> delete_key;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid task number. Please enter a valid number.\n";
            } else if (myTask.find(delete_key) != myTask.end()) {
                myTask.erase(delete_key);
                mymap.erase(delete_key);
                cout << "Task-" << delete_key << " deleted successfully.\n";
            } else {
                cout << "Invalid task number. Please try again.\n";
            }
            goto start;
            break;

        case 4:
            cout << "\nEnter the task number you want to mark as completed: ";
            cin >> edit_key;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid task number. Please enter a valid number.\n";
            } else if (myTask.find(edit_key) != myTask.end()) {
                mymap[edit_key] = 1;
                cout << "Task-" << edit_key << " marked as completed successfully.\n";
            } else {
                cout << "Invalid task number. Please try again.\n";
            }
            goto start;
            break;

        case 5:
            cout << "\nThank you for using the To-Do List Application!\n";
            exit(0);
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            goto start;
            break;
    }

    return 0;
}