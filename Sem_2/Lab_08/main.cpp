#include <iostream>

using namespace std;

int linearSearch(int sizeA, int sizeB, int arrA[], int arrB[], int countersA[], int countersB[]);
int lineSearchWithBarrier(int sizeA, int sizeB, int arrA[], int arrB[], int countersA[], int countersB[]);
void shellSort(int arr[], int N);

int main(){
    cout << "Lab_08 var_4" << endl;

    int sizeA;
    cout << "Enter the size of array A:\n";
    cin >> sizeA;
    int arrA[sizeA];
    cout << "You want to populate array A...\n" <<
            "1 - from the keyboard.\n" <<
            "2 - random numbers from 0 to 50.\n";
    int populateA;
    cin >> populateA;
    switch (populateA){
        case 1: {
            for(int i = 0; i < sizeA; i++){
                cout << i+1 << ":\n";
                cin >> arrA[i];
            }
            break;
        }
        case 2: {
            for (int i = 0; i < sizeA; i++){
                arrA[i] = rand()%51;
            }
            break;
        }
        default:{
            cout << "Invalid input is regarded as a desire to fill the " <<
                    "array with numbers from 0 to 50.\n";
            for (int i = 0; i < sizeA; i++){
                arrA[i] = rand()%51;
            }
            break;
        }
    }

    int sizeB;
    cout << "Enter the size of array B:\n";
    cin >> sizeB;
    int arrB[sizeB];
    cout << "You want to populate array B...\n" <<
         "1 - from the keyboard.\n" <<
         "2 - random numbers from 0 to 50.\n";
    int populateB;
    cin >> populateB;
    int counter;
    switch (populateB){
        case 1: {
            for(int i = 0; i < sizeB; i++){
                cout << i+1 << ":\n";
                cin >> arrB[i];
            }
            break;
        }
        case 2: {
            for (int i = 0; i < sizeB; i++){
                arrB[i] = rand()%51;
            }
            break;
        }
        default:{
            cout << "Invalid input is regarded as a desire to fill the " <<
                 "array with numbers from 0 to 50.\n";
            for (int i = 0; i < sizeB; i++){
                arrB[i] = rand()%51;
            }
            break;
        }
    }
    cout << "Input:\n";
    cout << "A:\n";
    for (int i = 0; i < sizeA; i++){
        cout << arrA[i] << "  ";
    }
    cout << endl;
    cout << "B:\n";
    for (int i = 0; i < sizeB; i++){
        cout << arrB[i] << "  ";
    }
    cout << endl;

    int countersA[sizeA];
    for (int i = 0; i < sizeA; i++){
        countersA[i] = 0;
    }
    int countersB[sizeB];
    for (int i = 0; i < sizeB; i++){
        countersB[i] = 0;
    }

    int searchAlgorithm;
    cout << "Select search algorithm:\n" <<
            "1 - linear search\n" <<
            "2 - line search with barrier\n";
    cin >> searchAlgorithm;
    switch (searchAlgorithm) {
        case 1: {
            counter = linearSearch(sizeA, sizeB, arrA, arrB, countersA, countersB);
            break;
        }
        case 2: {
            counter = lineSearchWithBarrier(sizeA, sizeB, arrA, arrB, countersA, countersB);
            break;
        }
        default: {
            cout << "Invalid input is regarded as a desire to find elements that satisfy a condition by a linear search.\n";
            counter = linearSearch(sizeA, sizeB, arrA, arrB, countersA, countersB);
            break;
        }
    }
    cout << "After Shell sort:\n";
    int arrRes[counter];
    counter = 0;
    if (sizeA <= sizeB) {
        for (int i = 0; i < sizeA; i++){
            if (countersA[i] > 1 && countersB[i] > 1){
                arrRes[counter] = arrA[counter];
                counter++;
            }
        }

    } else {
        for (int i = 0; i < sizeB; i++){
            if (countersA[i] > 1 && countersB[i] > 1){
                arrRes[counter] = arrB[counter];
                counter++;
            }
        }
    }
    int N = sizeof(arrRes)/sizeof(arrRes[0]);
    shellSort(arrRes, N);
    int last = -1;
    for (int i = 0; i < counter; i++){
        if(arrRes[i] != last){
            cout << arrRes[i] << "  ";
            last = arrRes[i];
        }
    }

    return 0;
}

int linearSearch(int sizeA, int sizeB, int arrA[], int arrB[], int countersA[], int countersB[]){
    int counter = 0;
    if (sizeA <= sizeB) {
        for (int i = 0; i < sizeA; i++){
            for (int j = 0; j < sizeB; j++) {
                if (arrA[i] == arrB[j]) {
                    countersB[i]++;
                }
            }
        }
        for (int i = 0; i < sizeA; i++){
            if(countersB[i] > 1){
                for (int j = 0; j < sizeA; j++){
                    if (arrA[i] == arrA[j]) countersA[i]++;
                }
                if (countersA[i] > 1) {
                    cout << arrA[i] << " (" << countersA[i] << " in A, " << countersB[i] << " in B" << ")\n";
                    counter++;
                }
            }
        }
    }
    else {
        for (int i = 0; i < sizeB; i++){
            for (int j = 0; j < sizeA; j++) {
                if (arrB[i] == arrA[j]) {
                    countersA[i]++;
                }
            }
        }
        for (int i = 0; i < sizeB; i++){
            if(countersA[i] > 1){
                for (int j = 0; j < sizeB; j++){
                    if (arrB[i] == arrB[j]) countersB[i]++;
                }
                if (countersB[i] > 1) {
                    cout << arrB[i] << " (" << countersA[i] << " in A, " << countersB[i] << " in B)\n";
                    counter++;
                }
            }
        }
    }
    return counter;
}

int lineSearchWithBarrier(int sizeA, int sizeB, int arrA[], int arrB[], int countersA[], int countersB[]){
    int counter = 0;
    if (sizeA <= sizeB) {
        for (int i = 0; i < sizeA; i++){
            if (arrB[sizeB-1] == arrA[i]){
                countersB[i]++;
            }
            int temp = arrB[sizeB-1];
            arrB[sizeB-1] = arrA[i];
            int index = -1;
            for (int j = 0; arrB[j] != arrB[sizeB-1]; j++) {
                if (arrA[i] == arrB[j]) {
                    countersB[i]++;
                    if (j == sizeB-1) countersB[i]--;
                    else index = j;
                }
            }
            if (index >= 0){
                for (int j = index+1; arrB[j] != arrB[sizeB-1]; j++) {
                    if (arrA[i] == arrB[j]) {
                        countersB[i]++;
                        if (j == sizeB-1) countersB[i]--;
                    }
                }
            }
            arrB[sizeB-1] = temp;
        }
        for (int i = 0; i < sizeA; i++){
            if(countersB[i] > 1){
                for (int j = 0; j < sizeA; j++){
                    if (arrA[i] == arrA[j]) countersA[i]++;
                }
                if (countersA[i] > 1) {
                    cout << arrA[i] << "\n";
                    counter++;
                }
            }
        }
    }
    else {
        for (int i = 0; i < sizeB; i++){
            if (arrA[sizeA-1] == arrB[i]){
                countersA[i]++;
            }
            int temp = arrA[sizeA-1];
            arrA[sizeA-1] = arrB[i];
            int index = -1;
            for (int j = 0; arrA[j] != arrA[sizeA-1]; j++) {
                if (arrB[i] == arrA[j]) {
                    countersA[i]++;
                    if (j == sizeB-1) countersB[i]--;
                    else index = j;
                }
            }
            if(index >= 0){
                for (int j = 0; arrA[j] != arrA[sizeA-1]; j++) {
                    if (arrB[i] == arrA[j]) {
                        countersA[i]++;
                        if (j == sizeB-1) countersB[i]--;
                    }
                }
            }
            arrA[sizeA-1] = temp;
        }
        for (int i = 0; i < sizeB; i++){
            if(countersA[i] > 1){
                for (int j = 0; j < sizeB; j++){
                    if (arrB[i] == arrB[j]) countersB[i]++;
                }
                if (countersB[i] > 1) {
                    cout << arrB[i] << "\n";
                    counter++;
                }
            }
        }
    }
    return counter;
}

void shellSort(int arr[], int N) {
    for (int gap = N/2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i += 1) {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}