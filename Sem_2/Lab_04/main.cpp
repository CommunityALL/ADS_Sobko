#include <iostream>

using namespace std;

int main(){
    cout << "Lab_04 var_4" << endl;

    cout << "What is part of lab_04 (1-2)?\n";
    int partOfLab;
    cin >> partOfLab;
    switch (partOfLab) {
        case 1: {
            struct Aeroflot_04 {
                string City;
                int Num{};
                string Type;
                Aeroflot_04 *next;
            };
            Aeroflot_04 *element, *firstElement, *lastElement;
            element = new(Aeroflot_04);
            firstElement = element;
            int counter01 = 0;
            do {
                lastElement = element;
                cout << "Enter information about " << counter01 + 1 << " flight.\n";
                cout << "Enter name of the locality of destination (or \".\" to stop input):\n";
                cin >> element->City;
                if (element->City != ".") {
                    counter01++;
                    cout << "Enter flight number:\n";
                    cin >> element->Num;
                    cout << "Enter aircraft type:\n";
                    cin >> element->Type;
                    element->next = new(Aeroflot_04);
                    element = element->next;
                }
            } while (lastElement->City != ".");
            lastElement->next = nullptr;

            int input01 = 1;
            while (input01 != 0) {
                cout << "You want to...\n1 - remove an element from the list.\n" <<
                     "2 - add an element to the end of the list.\n" <<
                     "3 - find the element beyond the specified field.\n" <<
                     "4 - display the list.\n" <<
                     "(0 - finish working with the list.)\n";
                cin >> input01;
                switch (input01) {
                    case 1: {
                        if (counter01 == 0) {
                            cout << "List is empty.\n";
                        } else {
                            int input02;
                            cout << "You want to enter...\n1 - city.\n2 - flight number.\n3 - aircraft type.\n";
                            cin >> input02;
                            string String;
                            int Int;
                            switch (input02) {
                                case 1: {
                                    cout << "Enter name of the locality of destination:\n";
                                    cin >> String;
                                    if (firstElement->City == String) {
                                        Aeroflot_04 *el = firstElement;
                                        firstElement = el->next;
                                        delete el;
                                    } else if (lastElement->City == String) {
                                        if (firstElement == lastElement) {
                                            Aeroflot_04 *el = firstElement;
                                            firstElement = el->next;
                                            delete el;
                                        } else {
                                            Aeroflot_04 *el = firstElement;
                                            while (el->next != lastElement) {
                                                el = el->next;
                                            }
                                            el->next = nullptr;
                                            delete lastElement;
                                            lastElement = el;
                                        }
                                    } else {
                                        Aeroflot_04 *slow = firstElement;
                                        Aeroflot_04 *fast = firstElement->next;
                                        while (fast != nullptr && fast->City != String) {
                                            fast = fast->next;
                                            slow = slow->next;
                                        }
                                        if (!fast) {
                                            cout << "This element does not exist." << endl;
                                        } else {
                                            slow->next = fast->next;
                                            delete fast;
                                        }
                                    }
                                    break;
                                }
                                case 2: {
                                    cout << "Enter flight number:\n";
                                    cin >> Int;
                                    if (firstElement->Num == Int) {
                                        Aeroflot_04 *el = firstElement;
                                        firstElement = el->next;
                                        delete el;
                                    } else if (lastElement->Num == Int) {
                                        if (firstElement == lastElement) {
                                            Aeroflot_04 *el = firstElement;
                                            firstElement = el->next;
                                            delete el;
                                        } else {
                                            Aeroflot_04 *el = firstElement;
                                            while (el->next != lastElement) {
                                                el = el->next;
                                            }
                                            el->next = nullptr;
                                            delete lastElement;
                                            lastElement = el;
                                        }
                                    } else {
                                        Aeroflot_04 *slow = firstElement;
                                        Aeroflot_04 *fast = firstElement->next;
                                        while (fast != nullptr && fast->Num != Int) {
                                            fast = fast->next;
                                            slow = slow->next;
                                        }
                                        if (!fast) {
                                            cout << "This element does not exist." << endl;
                                        } else {
                                            slow->next = fast->next;
                                            delete fast;
                                        }
                                    }
                                    break;
                                }
                                case 3: {
                                    cout << "Enter aircraft type:\n";
                                    cin >> String;
                                    if (firstElement->Type == String) {
                                        Aeroflot_04 *el = firstElement;
                                        firstElement = el->next;
                                        delete el;
                                    } else if (lastElement->Type == String) {
                                        if (firstElement == lastElement) {
                                            Aeroflot_04 *el = firstElement;
                                            firstElement = el->next;
                                            delete el;
                                        } else {
                                            Aeroflot_04 *el = firstElement;
                                            while (el->next != lastElement) {
                                                el = el->next;
                                            }
                                            el->next = nullptr;
                                            delete lastElement;
                                            lastElement = el;
                                        }
                                    } else {
                                        Aeroflot_04 *slow = firstElement;
                                        Aeroflot_04 *fast = firstElement->next;
                                        while (fast != nullptr && fast->Type != String) {
                                            fast = fast->next;
                                            slow = slow->next;
                                        }
                                        if (!fast) {
                                            cout << "This element does not exist." << endl;
                                        } else {
                                            slow->next = fast->next;
                                            delete fast;
                                        }
                                    }
                                    break;
                                }
                                default: {
                                    cout << "Incorrect input\n";
                                    return 0;
                                }
                            }
                            counter01--;
                        }
                        break;
                    }
                    case 2: {
                        Aeroflot_04 *el = new Aeroflot_04;
                        cout << "Enter name of the locality of destination:\n";
                        cin >> element->City;
                        cout << "Enter flight number:\n";
                        cin >> element->Num;
                        cout << "Enter aircraft type:\n";
                        cin >> element->Type;
                        if (counter01 == 0) {
                            firstElement = el;
                            lastElement = el;
                        } else {
                            lastElement->next = el;
                            lastElement = el;
                        }
                        counter01++;
                        break;
                    }
                    case 3: {
                        int input02;
                        cout << "You want to enter...\n1 - city.\n2 - flight number.\n3 - aircraft type.\n";
                        cin >> input02;
                        string String;
                        int Int;
                        switch (input02) {
                            case 1: {
                                cout << "Enter name of the locality of destination:\n";
                                cin >> String;
                                Aeroflot_04 *el = firstElement;
                                while (el != nullptr && el->City != String) {
                                    el = el->next;
                                }
                                if (!el) {
                                    cout << "This element does not exist." << endl;
                                } else {
                                    cout << "City:\n" << el->City << endl;
                                    cout << "Flight number:\n" << el->Num << endl;
                                    cout << "Aircraft type:\n" << el->Type << endl;
                                }
                                break;
                            }
                            case 2: {
                                cout << "Enter flight number:\n";
                                cin >> Int;
                                Aeroflot_04 *el = firstElement;
                                while (el != nullptr && el->Num != Int) {
                                    el = el->next;
                                }
                                if (!el) {
                                    cout << "This element does not exist." << endl;
                                } else {
                                    cout << "City:\n" << el->City << endl;
                                    cout << "Flight number:\n" << el->Num << endl;
                                    cout << "Aircraft type:\n" << el->Type << endl;
                                }
                                break;
                            }
                            case 3: {
                                cout << "Enter aircraft type:\n";
                                cin >> String;
                                Aeroflot_04 *el = firstElement;
                                while (el != nullptr && el->Type != String) {
                                    el = el->next;
                                }
                                if (!el) {
                                    cout << "This element does not exist." << endl;
                                } else {
                                    cout << "City:\n" << el->City << endl;
                                    cout << "Flight number:\n" << el->Num << endl;
                                    cout << "Aircraft type:\n" << el->Type << endl;
                                }
                                break;
                            }
                            default: {
                                cout << "Incorrect input\n";
                                return 0;
                            }
                        }
                        break;
                    }
                    case 4: {
                        Aeroflot_04 *el;
                        el = firstElement;
                        for (int i = 0; i < counter01; i++) {
                            cout << i + 1 << ":\n";
                            cout << "City:\n" << el->City << endl;
                            cout << "Flight number:\n" << el->Num << endl;
                            cout << "Aircraft type:\n" << el->Type << endl;
                            el = el->next;
                        }
                        break;
                    }
                    default: {
                        cout << "Incorrect input\n";
                        return 0;
                    }
                }
            }
            break;
        }
        case 2: {
            struct Participants {
                string Surname;
                Participants *next, *prev;
            };
            struct Prizes {
                string NamePrize;
                Prizes *next, *prev;
            };
            int counter01 = 0;
            int counter02 = 0;
            Participants *currentParticipant, *firstParticipant, *lastParticipant;
            currentParticipant = new(Participants);
            firstParticipant = currentParticipant;
            do {
                lastParticipant = currentParticipant;
                cout << "Enter information about " << counter01 + 1 << " participant.\n";
                cout << "Enter surname of participant (or \".\" to stop input):\n";
                cin >> currentParticipant->Surname;
                currentParticipant->next = new(Participants);
                currentParticipant = currentParticipant->next;
                currentParticipant->prev = lastParticipant;
                counter01++;
            } while (lastParticipant->Surname != ".");
            currentParticipant = lastParticipant;
            currentParticipant->next = firstParticipant;
            firstParticipant->prev = currentParticipant;
            counter01--;
            Prizes *currentPrize, *firstPrize, *lastPrize;
            currentPrize = new(Prizes);
            firstPrize = currentPrize;
            do {
                lastPrize = currentPrize;
                cout << "Enter information about " << counter02 + 1 << " prize.\n";
                cout << "Enter the name of the prize (or \".\" to stop input):\n";
                cin >> currentPrize->NamePrize;
                currentPrize->next = new(Prizes);
                currentPrize = currentPrize->next;
                currentPrize->prev = lastPrize;
                counter02++;
            } while (lastPrize->NamePrize != ".");
            currentPrize = lastPrize;
            currentPrize->next = firstPrize;
            firstPrize->prev = currentPrize;
            counter02--;
            cout << "Number of participants:\n";
            cout << counter01 << endl;
            cout << "Number of prizes:\n";
            cout << counter02 << endl;
            cout << "Enter the number of winners (no more than the number of prizes, no more than the number of participants):\n";
            int numberOfWinners;
            cin >> numberOfWinners;
            if (numberOfWinners > counter01){
                cout << "Incorrect input.\n";
                return -1;
            }
            if (numberOfWinners > counter02){
                cout << "Incorrect input.\n";
                return -1;
            }
            cout << "Enter the number to convert the winners:\n";
            int numberToConvertWinners;
            cin >> numberToConvertWinners;
            cout << "Enter a number to convert prizes:\n";
            int numberToConvertPrizes;
            cin >> numberToConvertPrizes;
            struct Winners{
                string NameWinner;
                string NamePrize;
            };
            Winners winners [numberOfWinners];
            currentParticipant = firstParticipant->prev;
            currentPrize = firstPrize->prev;
            for (int i = 0; i < numberOfWinners; i++){
                for (int participant = 0; participant < numberToConvertWinners; participant++){
                    currentParticipant = currentParticipant->next;
                }
                winners[i].NameWinner = currentParticipant->Surname;

                for (int prizes = 0; prizes < numberToConvertPrizes; prizes++){
                    currentPrize = currentPrize->next;
                }
                winners[i].NamePrize = currentPrize->NamePrize;
            }
            cout << "Information about the winners.\n";
            for (int i = 0; i < numberOfWinners; i++){
                cout << i + 1 << ":\n";
                cout << "Surname:\n" << winners[i].NameWinner << endl;
                cout << "Prize:\n" << winners[i].NamePrize << endl;
            }
            break;
        }
        default:{
            cout << "Incorrect input.\n";
            break;
        }
    }
    return 0;
}