#include <iostream>
#include <cmath>

using namespace std;

double SearchMemberValueSeries(int, double);
double SearchSumMembersSeries(double, double);
double TheFirstWay(int, int, double, double);
double TheSecondWay(int, int, double, double, int);
double TheThirdWay(int, int, double, double);

int main() {
    cout << "Lab_11 var_4" << endl;

    cout << "You want to find the sum of the terms of a series...\n" <<
    "1 - the first way;\n" <<
    "2 - the second way;\n" <<
    "3 - the third way.\n";
    int way;
    cin >> way;
    cout << "Enter the number of terms in the series whose sum you want to find:\n";
    int numberOfMembersSeries;
    cin >> numberOfMembersSeries;
    double sumOfMembersOfSeries = 1;
    if (numberOfMembersSeries == 1){
        sumOfMembersOfSeries = 1;
    }
    else if (numberOfMembersSeries == 0){
        sumOfMembersOfSeries = 0;
    }
    else if (numberOfMembersSeries < 0){
        cout << "Incorrect input";
        return -1;
    }
    else {
        switch (way) {
            case 1: {
                sumOfMembersOfSeries = TheFirstWay(numberOfMembersSeries, 2, 1, sumOfMembersOfSeries);
                break;
            }
            case 2: {
                sumOfMembersOfSeries = TheSecondWay(numberOfMembersSeries, 1, 1, sumOfMembersOfSeries, 1);
                break;
            }
            case 3: {
                sumOfMembersOfSeries = TheThirdWay(numberOfMembersSeries, 1, 1, sumOfMembersOfSeries);
                break;
            }
            default:{}
        }
    }
    cout << "The sum of the members of the series:\n" <<
            sumOfMembersOfSeries << endl;

    return 0;
}

double SearchMemberValueSeries(int numberMember, double lastMemberValue){
    double memberValue = 2 * lastMemberValue - cos(numberMember);
    return memberValue;
}
double SearchSumMembersSeries(double sumValue, double memberValue){
    double sumMembersSeries = sumValue + memberValue;
    return sumMembersSeries;
}

double TheFirstWay(int numberOfMembersSeries, int numberMember, double lastMemberValue, double sumValue){
    if (numberMember <= numberOfMembersSeries){
        double memberValue = SearchMemberValueSeries(numberMember, lastMemberValue);
        double sumMembersSeries = SearchSumMembersSeries(sumValue, memberValue);
        numberMember++;
        sumMembersSeries = TheFirstWay(numberOfMembersSeries, numberMember, memberValue, sumMembersSeries);
    return sumMembersSeries;
    }
    return sumValue;
}

double TheSecondWay(int numberOfMembersSeries, int numberMember, double lastMemberValue, double sumValue, int counter){
    if (numberOfMembersSeries - counter > 0){
        counter++;
        double sumMembersSeries = TheSecondWay(numberOfMembersSeries, numberMember, lastMemberValue, sumValue, counter);
        numberMember = numberMember + counter + 2;
        double memberValue = SearchMemberValueSeries(numberMember, lastMemberValue);
        sumMembersSeries = SearchSumMembersSeries(sumMembersSeries, memberValue);
    return sumMembersSeries;
    }
    return sumValue;
}

double TheThirdWay(int numberOfMembersSeries, int numberMember, double lastMemberValue, double sumValue){
    if (numberMember < numberOfMembersSeries){
        numberMember++;
        double memberValue = SearchMemberValueSeries(numberMember, lastMemberValue);
        double sumMembersSeries = TheThirdWay(numberOfMembersSeries, numberMember, memberValue, sumValue);
        sumMembersSeries = SearchSumMembersSeries(sumMembersSeries, memberValue);
    return sumMembersSeries;
    }
    return sumValue;
}
