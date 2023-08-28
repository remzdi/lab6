#include "LinkedListAssociativeArray.h"
#include "menu.h"

int main() {
    int choice;
    cout << "Choose the types for key and value:\n";
    cout << "1. int, string\n";
    cout << "2. string, double\n";
    cout << "3. string, string\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            LinkedListAssociativeArray<int, string> array;
            runArrayOperations(array);
            break;
        }
        case 2: {
            LinkedListAssociativeArray<string, double> array;
            runArrayOperations(array);
            break;
        }
        case 3: {
            LinkedListAssociativeArray<string, string> array;
            runArrayOperations(array);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
}
    return 0;
}
