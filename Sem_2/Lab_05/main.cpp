#include <iostream>

using namespace std;

int main(){
    cout << "Lab_05 var_4" << endl;

    struct List{
        string NameOfElement;
        List *next, *prev;
    };
    List *currentElement, *firstElement, *lastElement;
    currentElement = new(List);
    firstElement = currentElement;
    int counter01 = 0;
    do{
        lastElement = currentElement;
        cout << "Enter name of "<< counter01 + 1 << " element (or \".\" to stop input):\n";
        cin >> currentElement->NameOfElement;
        if (currentElement->NameOfElement != ".") {
            currentElement->next = new(List);
            currentElement = currentElement->next;
            currentElement->prev = lastElement;
            counter01++;
        }
    } while (lastElement->NameOfElement != ".");
    lastElement = lastElement->prev;
    lastElement->next = firstElement;
    firstElement->prev = lastElement;
    if (counter01 < 2){
        cout << "Too few elements.\n";
        return 0;
    }
    currentElement = firstElement;
    int counter02 = counter01;
    for(int i = 0; i < counter01; i++){
        if (i == 0){
            List *element = firstElement;
            List *next = firstElement->next;
            List *last = firstElement->prev;
            next->prev = last;
            last->next = next;
            firstElement = element->next;
            delete element;
            currentElement = next;
            counter02--;
        } else if (i % 2 == 0 && i != counter01 - 1){
            List *element = currentElement;
            List *next = element->next;
            List *last = element->prev;
            next->prev = last;
            last->next = next;
            delete element;
            currentElement = next;
            counter02--;
        } else if(i % 2 == 0 && i == counter01 - 1){
            List *element = firstElement;
            while (element->next != lastElement){
                element = element->next;
            }
            element->next = firstElement;
            firstElement->prev = element;
            currentElement = currentElement->next->prev;
            delete lastElement;
            counter02--;
            currentElement = currentElement->prev;
            lastElement = element;
        } else {
            currentElement = currentElement->next;
        }
    }
    currentElement = firstElement->prev;
    cout << "Output:\n";
    for (int i = 0; i < counter02; i++){
        currentElement = currentElement->next;
        cout << i + 1 << ":\n";
        cout << currentElement->NameOfElement << endl;
    }
    cout << "Name of current element:\n";
    cout << currentElement->NameOfElement << endl;
    return 0;
}