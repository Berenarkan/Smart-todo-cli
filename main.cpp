#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    bool isrunning = true;
    vector<string> tasks;
    string task;

    while (isrunning) {
        int choice;
        int deleteindex;

        system("clear");

        cout << "==== Smart TODO CLI ===" << endl << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Show Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Select: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1: {
                char again;

                do {
                    cout << "\nAdd Task Selected" << endl;
                    cout << "Enter task: ";
                    getline(cin, task);

                    tasks.push_back(task);
                    cout << "Task added successfully." << endl;

                    cout << "Add another task? (e/h): ";
                    cin >> again;
                    cin.ignore();

                } while (again == 'y' || again == 'Y');

                break;
            }

            case 2: {
                cout << "\nShow Tasks Selected" << endl;

                if (tasks.empty()) {
                    cout << "No tasks yet." << endl;
                } else {
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }

                cout << "\nPress Enter to return to menu...";
                cin.get();
                break;
            }

            case 3: {
                if (tasks.empty()) {
                    cout << "\nNo tasks!" << endl;
                    cout << "Press Enter to return to menu...";
                    cin.get();
                    break;
                }

                char again;

                do {
                    cout << "\nDelete Task Selected" << endl;

                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }

                    cout << "Which task to delete? ";
                    cin >> deleteindex;
                    cin.ignore();

                    if (deleteindex < 1 || deleteindex > tasks.size()) {
                        cout << "Invalid number!" << endl;
                    } else {
                        tasks.erase(tasks.begin() + (deleteindex - 1));
                        cout << "Task deleted successfully." << endl;
                    }

                    if (tasks.empty()) {
                        cout << "No tasks left." << endl;
                        break;
                    }

                    cout << "Delete another task? (e/h): ";
                    cin >> again;
                    cin.ignore();

                } while (again == 'e' || again == 'E');

                break;
            }

            case 4:
                cout << "Goodbye!" << endl;
                isrunning = false;
                break;

            default:
                cout << "Invalid choice!" << endl;
                cout << "Press Enter to continue...";
                cin.get();
        }
    }

    return 0;
}