#include "LinkedListAssociativeArray.h"
#include "menu.h"
void runArrayOperations(LinkedListAssociativeArray<int, string>& array) {
    int choice;

    do {
        cout << "1. Add key-value pair" << endl;
        cout << "2. Remove key-value pair" << endl;
        cout << "3. Find minimum key-value pair" << endl;
        cout << "4. Clear array" << endl;
        cout << "5. Print array elements" << endl;
        cout << "6. Is array empty?" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int key;
                string value;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                array.insert(key, value);
                cout << "Key-value pair added successfully." << endl;
                break;
            }
            case 2: {
                int key;
                cout << "Enter key to remove: ";
                cin >> key;
                if (array.remove(key)) {
                    cout << "Key-value pair removed successfully." << endl;
                } else {
                    cout << "Key not found in the array." << endl;
                }
                break;
            }
            case 3: {
                int key;
                string value;
                if (array.findMinimum(key, value)) {
                    cout << "Minimum key-value pair: Key=" << key << ", Value=" << value << endl;
                } else {
                    cout << "Array is empty." << endl;
                }
                break;
            }
            case 4: {
                array.clear();
                cout << "Array cleared." << endl;
                break;
            }
            case 5: {
                cout << "Array elements: ";
                bool isFirstElement = true;
                for (typename LinkedListAssociativeArray<int, string>::Iterator it = array.begin(); it != array.end(); ++it) {
                    if (!isFirstElement) {
                        cout << ", ";
                    }
                    cout << *it;
                    isFirstElement = false;
                }
                cout << endl;
                break;
            }
            case 6: {
                if (array.isEmpty()) {
                    cout << "Array is empty." << endl;
                } else {
                    cout << "Array is not empty." << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 0);
}
