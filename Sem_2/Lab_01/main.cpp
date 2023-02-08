#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << "Lab_01 var_4" << endl;

    cout << "What is part of lab_01 (1-3)?";
    int partOfLab;
    cin >> partOfLab;
    if (partOfLab == 1) {

        cout << "Lab_01.1" << endl;

        double boatSpeed;
        double riverSpeed;
        double lakeTravelTime;
        double riverTravelTime;
        double path1, path2;
        cout << "Enter boat speed (V, km/h):\n";
        cin >> boatSpeed;
        cout << "Enter river speed (U, km/h):\n";
        cin >> riverSpeed;
        cout << "Enter the driving time on the lake (T1, h):\n";
        cin >> lakeTravelTime;
        cout << "Enter the driving time on the river (T2, h):\n";
        cin >> riverTravelTime;
        path1 = boatSpeed * lakeTravelTime;
        path2 = (boatSpeed + riverSpeed) * riverTravelTime;
        cout << "The path that the boat will take along the lake at a speed V in time T1 is (km):\n";
        cout << path1 << endl;
        cout
                << "The path that the boat will travel along the river at a speed V in time T2, at a speed of the river U, is (km)\n";
        cout << path2 << endl;
    }
    else if (partOfLab == 2) {

        cout << "Lab_01.2" << endl;

        cout << "y = (1 + x) / (1 + cos^2(x))" << endl;
        double x, y;
        cout << "Enter x:\n";
        cin >> x;
        double cosX = cos(x);
        double squareCosX = cosX * cosX;
        y = (1 + x) / (1 + squareCosX);
        cout << "y = " << y << endl;
    }
    else if (partOfLab == 3) {

        cout << "Lab_01.3" << endl;

        char first1, second1;
        int first2, second2;
        cout << "Enter the first coordinate of the first field (a - h):\n";
        cin >> first1;
        cout << "Enter the second coordinate of the first field (1 - 8):\n";
        cin >> first2;
        cout << "Enter the first coordinate of the second field (a - h):\n";
        cin >> second1;
        cout << "Enter the second coordinate of the second field (1 - 8):\n";
        cin >> second2;
        if (first1 == second1 || first2 == second2) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    else {
        cout << "Incorrect input.\n";
    }
    return 0;
}