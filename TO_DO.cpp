#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

#define CLEAR_COMMAND "cls"

// ANSI color codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

// Declaration of classes and functions used in the program
class QuoteGenerator {
private:
    vector<string> forstorequotes;

public:
    QuoteGenerator() {
        // Initialize quotes
        forstorequotes = {
            "I'm king of the world! - Titanic",
            "There's no place like home. - The Wizard of Oz",
            "You're gonna need a bigger boat. - Jaws",
            "Here's Johnny! - The Shining",
            "Frankly, my dear, I don't give a damn. - Gone with the Wind",
            "You shall not pass! - The Lord of the Rings: The Fellowship of the Ring",
            "Hasta la vista, baby. - Terminator 2: Judgment Day",
            "Why so serious? - The Dark Knight",
            "Just keep swimming. - Finding Nemo",
            "I am Groot. - Guardians of the Galaxy",
            "May the Force be with you. - Star Wars",
            "Here's looking at you, kid. - Casablanca",
            "You can't handle the truth! - A Few Good Men",
            "I'll be back. - The Terminator",
            "My precious. - The Lord of the Rings: The Two Towers",
            "Life is like a box of chocolates; you never know what you're gonna get. - Forrest Gump",
            "To infinity and beyond! - Toy Story",
            "You talking to me? - Taxi Driver",
            "Bond. James Bond. - Various James Bond films",
            "Houston, we have a problem. - Apollo 13",
        };
    }

    string forRandomQuote() {
        // Generate a random index
        int x = rand() % forstorequotes.size();

        // Return the random quote
        return forstorequotes[x];
    }
};


struct Task {
    string name;
    time_t time;
};

class ToDo {
private:
    vector<Task> tasks;

public:
    void foraddt(const string& name, const tm& time) {
        tm time_copy = time;
        time_t Time1 = mktime(&time_copy);
        tasks.push_back({name, Time1});
    }

    void displayt() {
        system(CLEAR_COMMAND); // Clear screen
        cout << "Tasks : \n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "  " << i + 1 << ". " << tasks[i].name << " - Time : " << ctime(&tasks[i].time) <<endl;
        }
    }

    void removet(int remove_task) {
        if (remove_task >= 0 && remove_task < tasks.size()) {
            tasks.erase(tasks.begin() + remove_task);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

tm current_time() {
    time_t current_time = time(nullptr);
    return *localtime(&current_time);
}

tm get_task() {
    int choice;
    tm Time;
    cout << "\nEnter task due date and time:\n";
    cout << "  1. Enter specific date and time\n";
    cout << "  2. Use current date and time\n";
    cout << "\nEnter your choice : ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nEnter task due date and time (YYYY-MM-DD HH:MM): ";
        cin >> get_time(&Time, "%Y-%m-%d %H:%M");

    } else if (choice == 2) {
        Time = current_time();
    } else {
        cout << "\nInvalid choice. Using current Date and Time by default.\n";
        Time = current_time();
    }

    return Time;
}

int main() {

    QuoteGenerator obj1;
    ToDo obj2;
    int choice;

    // Seed the random number generator
    srand(time(nullptr));

    do {
        system(CLEAR_COMMAND); // Clear screen

        cout << CYAN << " __________________________________ "<< RESET << endl;
        cout << CYAN << "|                                  |"<< RESET << endl;
        cout << CYAN << "|              Menu                |"<< RESET << endl;
        cout << CYAN << "|__________________________________|"<< RESET << endl;
        cout << CYAN << "|                                  |"<< RESET << endl;
        cout << CYAN << "| 1. To-Do List                    |"<< RESET << endl;
        cout << CYAN << "| 2. Random Quote Generator        |"<< RESET << endl;
        cout << CYAN << "| 3. Exit                          |"<< RESET << endl;
        cout << CYAN << "|__________________________________|"<< RESET << endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int select;
                do {
                    system(CLEAR_COMMAND); // Clear screen

                    cout << BLUE << " __________________________________ "<< RESET << endl;
                    cout << BLUE << "|                                  |"<< RESET << endl;
                    cout << BLUE << "|          To-Do List Menu         |"<< RESET << endl;
                    cout << BLUE << "|__________________________________|"<< RESET << endl;
                    cout << BLUE << "|                                  |"<< RESET << endl;
                    cout << BLUE << "| 1. Add Task                      |"<< RESET << endl;
                    cout << BLUE << "| 2. Display Tasks                 |"<< RESET << endl;
                    cout << BLUE << "| 3. Remove Task                   |"<< RESET << endl;
                    cout << BLUE << "| 4. Back to Main Menu             |"<< RESET << endl;
                    cout << BLUE << "|__________________________________|"<< RESET << endl;

                    cout << "\nEnter your choice : ";
                    cin >> select;

                    switch (select) {
                        case 1: {
                            string task_name;
                            tm task_time = get_task();
                            cout << "\nEnter Task : ";
                            cin.ignore();
                            getline(cin, task_name);
                            obj2.foraddt(task_name, task_time);
                            obj2.displayt();
                            break;
                        }
                        case 2:
                            obj2.displayt();
                            break;
                        case 3: {
                            int remove_task;
                            cout << "\nEnter index of task to remove : ";
                            cin >> remove_task;
                            obj2.removet(remove_task - 1); // Adjust index to match vector indexing
                            obj2.displayt();         // Clear and display tasks after removing
                            break;
                        }
                        case 4:
                            break; // Exit to main menu
                        default:
                            cout << "\nInvalid choice. Please try again.\n";
                    }

                    if (select != 4) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore(); // Wait for Enter key
                        cin.get();
                    }
                } while (select != 4);
                break;
            }
            case 2: {
                system(CLEAR_COMMAND); // Clear screen

                cout << "\nRandom Quote :  " << endl;
                cout << obj1.forRandomQuote() << endl;

                cout << "\nPress Enter to continue...";
                cin.ignore(); // Wait for Enter key
                cin.get();
                break;
            }

            case 3:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

