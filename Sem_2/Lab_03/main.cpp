#include <iostream>

using namespace std;

struct Aeroflot {
    string City;
    int Num{};
    string Type;
};
int numberOfFlights;
void EnterInformationAboutFlight(Aeroflot air[]);
void Sort(Aeroflot air[]);
void Output(Aeroflot air[]);

int main(){
    cout << "Lab_03 var_4" << endl;

    cout << "Enter the number of flights:\n";
    cin >> numberOfFlights;
    Aeroflot air[numberOfFlights];
    EnterInformationAboutFlight(air);
    Sort(air);
    Output(air);
    return 0;
}

void EnterInformationAboutFlight(Aeroflot air[]){
    for (int i = 0; i < numberOfFlights; i++){
        cout << "Enter information about " << i + 1 << " flight.\n";
        cout << "Name of the locality of destination:\n";
        cin >> air[i].City;
        cout << "Flight number:\n";
        cin >> air[i].Num;
        cout << "Aircraft type:\n";
        cin >> air[i].Type;
    }
}

void Sort(Aeroflot air[]){
    for(int i = 0; i < numberOfFlights; i++){
        for(int comparableI = 0; comparableI < numberOfFlights; comparableI++){
            if (air[comparableI].Num > air[i].Num){
                string variable01 = air[i].City;
                air[i].City = air[comparableI].City;
                air[comparableI].City = variable01;
                int variable02 = air[i].Num;
                air[i].Num = air[comparableI].Num;
                air[comparableI].Num = variable02;
                string variable03 = air[i].Type;
                air[i].Type = air[comparableI].Type;
                air[comparableI].Type = variable03;
            }
        }
    }
}

void Output(Aeroflot air[]){
    cout << "Enter the desired name of the locality of the destination:\n";
    string nameOfLocalityOfDestination;
    cin >> nameOfLocalityOfDestination;
    int counter01 = 0;
    for(int i = 0; i < numberOfFlights; i++){
        if (air[i].City == nameOfLocalityOfDestination){
            cout << air[i].Num << "   " << air[i].Type << endl;
            counter01++;
        }
    }
    if (counter01 == 0){
        cout << "No flights found.\n";
    }
}