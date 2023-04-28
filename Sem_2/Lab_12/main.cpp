#include <iostream>

using namespace std;

void PopulateArray (int size, long int** arr, char letter);
void PrintInput (int size, long int** arr, char letter);
void SearchAndPrintOutput (int size, long int** arr, char letter);
void DeleteArray(long int** arr);

int main(){
    cout << "Lab_12 var_4" << endl;

    int sizeA = 6;
    auto ** arrA = (long int**) malloc (sizeof (long int*) * sizeA);
    for(int m = 0; m < sizeA; m++){
        arrA [m] = (long int*) malloc (sizeof (long int)*sizeA);
    }
    PopulateArray(sizeA, arrA, 'A');

    int sizeB = 8;
    auto ** arrB = (long int**) malloc (sizeof (long int*) * sizeB);
    for(int m = 0; m < sizeB; m++){
        arrB [m] = (long int*) malloc (sizeof (long int)*sizeB);
    }
    PopulateArray(sizeB, arrB, 'B');

    cout << "Input:\n";
    PrintInput(sizeA, arrA, 'A');
    PrintInput(sizeB, arrB, 'B');

    cout << "Output:\n";
    SearchAndPrintOutput(sizeA, arrA, 'A');
    DeleteArray(arrA);
    SearchAndPrintOutput(sizeB, arrB, 'B');
    DeleteArray(arrB);
    return 0;
}

void PopulateArray (int size, long int** arr, char letter){
    int populateArrayWay;
    cout << "You want to populate array " << letter << "...\n" <<
         "1 - from the keyboard.\n" <<
         "2 - random numbers from 0 to 100.\n";
    cin >> populateArrayWay;
    switch (populateArrayWay) {
        case 1: {
            for(int m = 0; m < size; m++){
                for(int n = 0; n < size; n++){
                    cout << "[" << m << "]" << "[" << n << "]:\n";
                    cin >> arr[m][n];
                }
            }
            break;
        }
        case 2: {
            for(int m = 0; m < size; m++){
                for(int n = 0; n < size; n++){
                    arr[m][n] = rand() % 101;
                }
            }
            break;
        }
        default: {
            cout << "Invalid input is regarded as a desire to fill the array A with random numbers from 0 to 100.\n";
            for(int m = 0; m < size; m++){
                for(int n = 0; n < size; n++){
                    arr[m][n] = rand() % 101;
                }
            }
            break;
        }
    }
}
void PrintInput (int size, long int** arr, char letter){
    cout << letter << ":\n";
    for(int m = 0; m < size; m++){
        for(int n = 0; n < size; n++){
            cout << arr[m][n] << "   ";
        }
        cout << "\n";
    }
}
void SearchAndPrintOutput (int size, long int** arr, char letter){
    long long int sum = 0;
    long long int product = 1;
    for(int m = 0; m < size; m++){
        for(int n = 0; n < size; n++){
            if(m + 1 == n)
                sum += arr[m][n];
            if(m - 1 == n)
                product *= arr[m][n];
        }
    }
    cout << letter << ":\n";
    cout << "The sum of the elements above the main diagonal:\n";
    cout << sum << endl;
    cout << "The product of the elements under the main diagonal:\n";
    cout << product << endl;
}
void DeleteArray(long int** arr){
    delete arr;
}
