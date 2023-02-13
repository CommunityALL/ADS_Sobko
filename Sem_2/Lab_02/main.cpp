#include <iostream>

using namespace std;

int main(){
    cout << "Lab_02 var_4" << endl;

    cout << "What is part of lab_02 (1-4)?\n";
    int partOfLab;
    cin >> partOfLab;
    if (partOfLab == 1) {

        cout << "Lab_02.1" << endl;

        int numberOfArrayElements;
        cout << "Enter number of array elements:\n";
        cin >> numberOfArrayElements;
        int arr[numberOfArrayElements];
        cout << "Fill array with...\n1 - keyboard.\n2 - random numbers (-100 - 100).\n";
        int input01;
        cin >> input01;
        if (input01 == 1){
            for(int i = 0; i < numberOfArrayElements; i++){
                cout << i+1 << " element:\n";
                cin >> arr[i];
            }
        }
        else if (input01 == 2){
            for(int i = 0; i < numberOfArrayElements; i++){
                arr[i] = rand() % 200 - 100;
            }
        }
        else {
            cout << "Incorrect input.";
            return -1;
        }
        cout << "Input:\n";
        int firstNegative = 0;
        int secondNegative = 0;
        int counter01 = 0;
        for(int i = 0; i < numberOfArrayElements; i++){
            cout << arr[i] << "   ";
            if (arr[i] < 0 && counter01 == 0){
                firstNegative = i;
                counter01++;
            }
            secondNegative = i;
        }
        cout << "\n";
        int sumOfUnpairedElements = 0;
        for(int i = 1; i < numberOfArrayElements;){
            sumOfUnpairedElements += arr[i];
            i += 2;
        }
        cout << "Sum of array elements with unpaired numbers:\n";
        cout << sumOfUnpairedElements << endl;
        int sumOfElementsInMiddle = 0;
        for(int i = firstNegative + 1; i < secondNegative; i++){
            sumOfElementsInMiddle += arr[i];
        }
        cout << "Sum of array elements that are between the first and last negative elements:\n";
        cout << sumOfElementsInMiddle << endl;
    }
    else if (partOfLab == 2) {

        cout << "Lab_02.2" << endl;

        int numberOfArrayElements;
        cout << "Enter number of array elements:\n";
        cin >> numberOfArrayElements;
        int arr[numberOfArrayElements];
        cout << "Fill array with...\n1 - keyboard.\n2 - random numbers (-100 - 100).\n";
        int input01;
        cin >> input01;
        if (input01 == 1){
            for(int i = 0; i < numberOfArrayElements; i++){
                cout << i+1 << " element:\n";
                cin >> arr[i];
            }
        }
        else if (input01 == 2){
            for(int i = 0; i < numberOfArrayElements; i++){
                arr[i] = rand() % 200 - 100;
            }
        }
        else {
            cout << "Incorrect input.";
            return -1;
        }
        cout << "Input:\n";
        for(int i = 0; i < numberOfArrayElements; i++){
            cout << arr[i] << "   ";
        }
        cout << "\n";
        cout << "Enter the number of elements to be rearranged:\n";
        int numberOfElementsToBeRearranged;
        cin >> numberOfElementsToBeRearranged;
        if (numberOfElementsToBeRearranged >= numberOfArrayElements){
            cout << "Incorrect input";
            return -1;
        }
        int finishArr[numberOfArrayElements];
        int counter01 = 0;
        for (int i = 0; i < numberOfArrayElements; i++){
            if (i < numberOfArrayElements - numberOfElementsToBeRearranged){
                finishArr[i] = arr[numberOfElementsToBeRearranged + i];
            }
            else{
                finishArr[i] = arr[counter01];
                counter01++;
            }
        }
        cout << "Output:\n";
        for(int i = 0; i < numberOfArrayElements; i++){
            cout << finishArr[i] << "   ";
        }
        cout << "\n";
    }
    else if (partOfLab == 3) {

        cout << "Lab_02.3" << endl;

        cout << "Enter the number of rows of the matrix:\n";
        int numberOfRows;
        cin >> numberOfRows;
        cout << "Enter the number of columns of the matrix:\n";
        int numberOfColumns;
        cin >> numberOfColumns;
        int arr[numberOfRows][numberOfColumns];
        cout << "Fill array with...\n1 - keyboard.\n2 - random numbers (-50 - 50).\n";
        int input01;
        cin >> input01;
        if (input01 == 1){
            for(int m = 0; m < numberOfRows; m++){
                for(int n = 0; n < numberOfColumns; n++){
                    cout << m + 1 << "." << n + 1 << ". element:\n";
                    cin >> arr[m][n];
                }
            }
        }
        else if (input01 == 2){
            for(int m = 0; m < numberOfRows; m++){
                for(int n = 0; n < numberOfColumns; n++){
                    arr[m][n] = rand() % 100 - 50;
                }
            }
        }
        else {
            cout << "Incorrect input.";
            return -1;
        }
        cout << "Input:\n";
        for(int m = 0; m < numberOfRows; m++){
            for(int n = 0; n < numberOfColumns; n++){
                cout << arr[m][n] << "   ";
            }
            cout << "\n";
        }
        cout << "The product of elements in those rows that do not have negative elements:\n";
        int commonProduct = 1;
        int counter02 = 0;
        for(int m = 0; m < numberOfRows; m++){
            int product = 1;
            int counter01 = 0;
            for(int n = 0; n < numberOfColumns; n++){
                product *= arr[m][n];
                if(arr[m][n] < 0){
                    counter01 = -1;
                }
            }
            if (counter01 == 0){
                cout << m + 1 << ":\n" << product << endl;
                commonProduct *= product;
                counter02++;
            }
        }
        if (counter02 > 0) {
            cout << "All:\n" << commonProduct << endl;
        }
        else {
            cout << "-\n";
        }
        int sumOfElementsOfDiagonal;
        int maxSumOfElementsOfDiagonal = 0;
        for(int i = 0; i < numberOfRows + numberOfColumns - 1; i++) {
            sumOfElementsOfDiagonal = 0;
            for (int m = 0; m < numberOfRows; m++) {
                for (int n = 0; n < numberOfColumns; n++) {
                    if (m == n - numberOfColumns + i){
                        sumOfElementsOfDiagonal += arr[m][n];
                    }
                }
            }
            if(sumOfElementsOfDiagonal > maxSumOfElementsOfDiagonal){
                maxSumOfElementsOfDiagonal = sumOfElementsOfDiagonal;
            }
        }
        cout << "Maximum among the sums of elements of diagonals parallel to the main diagonal of the matrix:\n";
        cout << maxSumOfElementsOfDiagonal << endl;
    }
    else if (partOfLab == 4){

        cout << "Lab_02.4" << endl;

        cout << "Enter the dimension of the square matrix:\n";
        int dimensionOfMatrix;
        cin >> dimensionOfMatrix;
        double arr[dimensionOfMatrix][dimensionOfMatrix];
        int center;
        if (dimensionOfMatrix % 2 == 1){
            center = (dimensionOfMatrix - 1) / 2;
        }
        else {
            center = dimensionOfMatrix / 2;
        }
        for(int m = 0; m < dimensionOfMatrix; m++){
            for(int n = 0; n < dimensionOfMatrix; n++){
                arr[m][n] = 0;
                if (dimensionOfMatrix % 2 == 0 && m >= center && n <= m  && m + n > (center - 1) * 2) {
                    arr[m][n] = 1;
                }
                if (dimensionOfMatrix % 2 == 1 && m >= center && n <= m && m + n > center * 2 - 1) {
                    arr[m][n] = 1;
                }
            }
        }
        for(int m = 0; m < dimensionOfMatrix; m++){
            for(int n = 0; n < dimensionOfMatrix; n++){
                cout << arr[m][n] << "   ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Incorrect input.\n";
    }
    return 0;
}