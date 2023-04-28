#include <iostream>

using namespace std;

int main(){
    cout << "Lab_12 var_4" << endl;

    int populateArrayWay;
    int sizeA = 6;
    long int ** arrA = (long int**) malloc (sizeof (long int*) * sizeA);
    for(int m = 0; m < sizeA; m++){
        arrA [m] = (long int*) malloc (sizeof (long int)*sizeA);
    }
    cout << "You want to populate array A...\n" <<
            "1 - from the keyboard.\n" <<
            "2 - random numbers from 0 to 100.\n";
    cin >> populateArrayWay;
    switch (populateArrayWay) {
        case 1: {
            for(int m = 0; m < sizeA; m++){
                for(int n = 0; n < sizeA; n++){
                    cout << "[" << m << "]" << "[" << n << "]:\n";
                    cin >> arrA[m][n];
                }
            }
            break;
        }
        case 2: {
            for(int m = 0; m < sizeA; m++){
                for(int n = 0; n < sizeA; n++){
                    arrA[m][n] = rand() % 101;
                }
            }
            break;
        }
        default: {
            cout << "Invalid input is regarded as a desire to fill the array A with random numbers from 0 to 100.\n";
            for(int m = 0; m < sizeA; m++){
                for(int n = 0; n < sizeA; n++){
                    arrA[m][n] = rand() % 101;
                }
            }
            break;
        }
    }

    int sizeB = 8;
    int ** arrB = (int**) malloc (sizeof (int*) * sizeB);
    for(int m = 0; m < sizeB; m++){
        arrB [m] = (int*) malloc (sizeof (int)*sizeB);
    }
    cout << "You want to populate array B...\n" <<
         "1 - from the keyboard.\n" <<
         "2 - random numbers from 0 to 100.\n";
    cin >> populateArrayWay;
    switch (populateArrayWay) {
        case 1: {
            for(int m = 0; m < sizeB; m++){
                for(int n = 0; n < sizeB; n++){
                    cout << "[" << m << "]" << "[" << n << "]:\n";
                    cin >> arrB[m][n];
                }
            }
            break;
        }
        case 2: {
            for(int m = 0; m < sizeB; m++){
                for(int n = 0; n < sizeB; n++){
                    arrB[m][n] = rand() % 101;
                }
            }
            break;
        }
        default: {
            cout << "Invalid input is regarded as a desire to fill the array B with random numbers from 0 to 100.\n";
            for(int m = 0; m < sizeB; m++){
                for(int n = 0; n < sizeB; n++){
                    arrB[m][n] = rand() % 101;
                }
            }
            break;
        }
    }

    cout << "Input:\n";
    cout << "A:\n";
    for(int m = 0; m < sizeA; m++){
        for(int n = 0; n < sizeA; n++){
            cout << arrA[m][n] << "   ";
        }
        cout << "\n";
    }
    cout << "B:\n";
    for(int m = 0; m < sizeB; m++){
        for(int n = 0; n < sizeB; n++){
            cout << arrB[m][n] << "   ";
        }
        cout << "\n";
    }

    cout << "Output:\n";
    long int sum = 0;
    long int product = 1;

    for(int m = 0; m < sizeA; m++){
        for(int n = 0; n < sizeA; n++){
            if(m + 1 == n)
                sum += arrA[m][n];
            if(m - 1 == n)
                product *= arrA[m][n];
        }
    }
    cout << "A:\n";
    cout << "The sum of the elements above the main diagonal:\n";
    cout << sum << endl;
    cout << "The product of the elements under the main diagonal:\n";
    cout << product << endl;
    delete arrA;

    sum = 0;
    product = 1;

    for(int m = 0; m < sizeB; m++){
        for(int n = 0; n < sizeB; n++){
            if(m + 1 == n)
                sum += arrB[m][n];
            if(m - 1 == n)
                product *= arrB[m][n];
        }
    }
    cout << "B:\n";
    cout << "The sum of the elements above the main diagonal:\n";
    cout << sum << endl;
    cout << "The product of the elements under the main diagonal:\n";
    cout << product << endl;
    delete arrB;
    return 0;
}