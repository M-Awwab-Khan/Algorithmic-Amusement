#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Awwab_Lab4{
    public:
    void bubbleSort(int* arr, int size, bool analyze=false) {
        int swaps = 0;
        int comparisions = 0;

        for (int i = 0; i < size - 1; ++i) {
            bool sorted = true;
            for (int j = 0; j < size - i - 1; ++j) {
                comparisions++;
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swaps++;
                    sorted = false;
                }
            }
            if (sorted) break;
        }

        if (analyze) {
            cout << "Number of swaps: " << swaps << endl;
            cout << "Number of comparisions: " << comparisions << endl;
        }
    }

    void insertionSort(int* arr, int size, bool analyze=false) {
        int swaps = 0;
        int comparisions = 0;

        for (int i = 1; i < size; ++i) {
            int j = i - 1;
            int temp = arr[i];

            comparisions++;
            while (temp < arr[j] && j >= 0) {
                comparisions++;
                arr[j+1] = arr[j];
                j -= 1;
            }

            arr[j+1] = temp;
        }

        if (analyze) {
            cout << "Number of swaps: " << swaps << endl;
            cout << "Number of comparisions: " << comparisions << endl;
        }
    }

    void selectionSort(int* arr, int size, bool analyze=false) {
        int swaps = 0;
        int comparisions = 0;

        for (int i = 0; i < size; ++i) {
            int min_index = i;

            for (int j = i+1; j < size; ++j) {
                comparisions++;
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(arr[i], arr[min_index]);
                swaps++;
            }
        }

        if (analyze) {
            cout << "Number of swaps: " << swaps << endl;
            cout << "Number of comparisions: " << comparisions << endl;
        }
    }

    void print(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

    void randomSort() {
        srand(static_cast<unsigned int>(time(nullptr)));
        int size;
        cout << "Enter number of elements for random sorting: ";
        cin >> size;

        int* randomArray = new int[size];

        for (int i = 0; i < size; ++i) {
            randomArray[i] = rand() % (100 + 1);
        }

        cout << "Random Array: ";
        print(randomArray, size);

        int* bubbleArray = new int[size];
        int* insertionArray = new int[size];
        int* selectionArray = new int[size];

        for (int i = 0; i < size; ++i) {
            bubbleArray[i] = randomArray[i];
            insertionArray[i] = randomArray[i];
            selectionArray[i] = randomArray[i];
        }

        bubbleSort(bubbleArray, size, true);
        cout << "Sorted Array (Bubble Sort): ";
        print(bubbleArray, size);

        insertionSort(insertionArray, size, true);
        cout << "Sorted Array (Insertion Sort): ";
        print(insertionArray, size);

        selectionSort(selectionArray, size, true);
        cout << "Sorted Array (Selection Sort): ";
        print(selectionArray, size);

        delete[] randomArray;
        delete[] bubbleArray;
        delete[] insertionArray;
        delete[] selectionArray;
    }

    void interface() {
        int size;
        cout << "Enter number of elements for choice sort: ";
        cin >> size;

        int* arr = new int[size];

        for (int i = 0; i < size; ++i) {
            cout << "Enter element: ";
            cin >> arr[i];
        }
        int choice;
        cout << "[1] Bubble Sort\n[2] Selection Sort\n[3] Insertion Sort\nEnter your choice: ";
        cin >> choice;

        choiceSort(arr, size, choice);
        print(arr, size);

    }

    void choiceSort(int* arr, int size, int choice) {
        switch (choice) {
            case 1:
                bubbleSort(arr, size);
                break;
            case 2:
                selectionSort(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
};

int main() {

    Awwab_Lab4 lab;

    lab.interface();

    lab.randomSort();

    return 0;
}
