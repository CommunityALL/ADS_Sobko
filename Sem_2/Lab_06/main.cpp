#include <iostream>

using namespace std;

struct List_06{
    string String;
    struct List_06 *next{};
};
List_06 *currentElement;
struct Queue_06{
    struct List_06 *first;
    struct List_06 *last;
};

void Creation_06(Queue_06*);
bool IsEmpty_06(Queue_06*);
void Enqueue_06(Queue_06*);
int Dequeue_06(Queue_06*);
int Print_06(Queue_06*);

int main(){
    cout << "Lab_06 var_4" << endl;

    auto *queue = new Queue_06;
    queue->first = nullptr;
    queue->last = nullptr;
    int input01 = 1;
    while(input01 != 0) {
        cout << "You want to...\n1 - add element to queue.\n2 - delete first element of queue.\n" <<
                "3 - display the queue.\n(0 - finish program.)\n";
        cin >> input01;
        switch (input01) {
            case 1: {
                Enqueue_06(queue);
                break;
            }
            case 2: {
                Dequeue_06(queue);
                break;
            }
            case 3: {
                Print_06(queue);
                break;
            }
            case 0:{
                break;
            }
            default: {
                cout << "Incorrect input.\n";
                return -1;
            }
        }
    }

    currentElement = queue->first;
    string allStrings;
    while (currentElement != queue->last){
        currentElement = currentElement->next;
        allStrings += currentElement->String;
    }
    cout << allStrings << " (" << allStrings.size() << ")" << endl;

    return 0;
}

void Creation_06(Queue_06 *queue){
    queue->first = new List_06;
    string value;
    cout << "Enter string:\n";
    cin >> value;
    queue->first->String = value;
    queue->first->next = nullptr;
    queue->last = queue->first;
}
bool IsEmpty_06(Queue_06 *queue){
    if(queue->first == nullptr){
        return true;
    } else{
        return false;
    }
}
void Enqueue_06(Queue_06 *queue){
    if(IsEmpty_06(queue)){
        Creation_06(queue);
        return;
    }
    string value;
    cout << "Enter string:\n";
    cin >> value;
    queue->last->next = new List_06;
    currentElement = queue->last->next;
    currentElement->String = value;
    currentElement->next = nullptr;
    queue->last = currentElement;
    cout << "Element is added.\n";
}
int Dequeue_06(Queue_06 *queue){
    struct List_06 *temp;
    string x;
    if(IsEmpty_06(queue)){
        cout << "Queue is empty.\n";
        return -1;
    }
    x = queue->first->String;
    temp = queue->first;
    queue->first = queue->first->next;
    free(temp);
    cout << "First element (" << x << ") is removed.\n";
    return 0;
}
int Print_06(Queue_06 *queue){
    if(IsEmpty_06(queue)){
        cout << "Queue is empty.\n";
        return -1;
    }
    cout << "Queue:\n";
    currentElement = queue->first;
    while (currentElement != queue->last){
        cout << currentElement->String << endl;
        currentElement = currentElement->next;
    }
    cout << currentElement->String << endl;
    return 0;
}