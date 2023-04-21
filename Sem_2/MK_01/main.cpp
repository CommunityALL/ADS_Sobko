// Модульний контроль 1
// Виконала: Собко Вікторія, ПП-11
// Варіант №22 (Задачі №2)
// №1.2
// Програма отримує наступні значення: розмір масиву – 1 <= n <=10^5,
// число k – 1 <= k <=100, та значення, що вводяться в масив S з умовою,
// що кожне значення масиву – 1 <= S[i] <=10^9. Програма повинна
// обрахувати суми чисел масиву, що не дорівнюють k. Результатом роботи
// має бути кількість таких сум та їх список.
// №2.2
// Напишіть програму, яка реалізує чергу за допомогою масиву. Ваша
// черга має мати функції, які дозволяють додавати елементи до черги,
// видаляти елементи з черги і повертати довжину черги.

#include <iostream>
#include <vector>

using namespace std;

int Sum(std::vector<int>& result, const std::vector<int>& v, int index, int curSum, int k);

int const maxSize = 1000;

struct Queue{
    int storage[maxSize];
    int start;
    int finish;
    Queue(){
        start = 0;
        finish = 0;
    }

    void push(int n){
        if ((finish == maxSize - 1 && start == 0) || finish + 1 == start){
            cout << "Do you want to refill the queue?\n1 - yes\n2 - no\n";
            int inputRefill;
            cin >> inputRefill;
            switch (inputRefill) {
                case 1: {
                    if (finish == maxSize - 1) {
                        finish = 0;
                    }
                    else if (finish + 1 == start) {
                        finish++;
                    }
                    break;
                }
                case 2: {
                    return;
                }
                default:{
                    cout << "Invalid input is understood as \"no\".\n";
                    return;
                }
            }
        }
        storage[finish] = n;
        if (finish + 1 != start) {
            finish++;
        }
        cout << "Element \"" << n << "\" is added.\n";
    }

    int remove(){
        int a = storage[start];
        start++;
        if (start == maxSize){
            start = 0;
        }
        return a;
    }

    int size(){
        return finish - start;
    }

    void print(){
        if (finish - start == 0){
            cout << "Queue is empty.\n";
            return;
        }
        int counter = 1;
        if (start > finish){
            for (int i = start; i < maxSize; i++){
                cout << counter << ": " << storage[i];
            }
            for (int i = 0; i <= finish; i++){
                cout << counter << ": " << storage[i];
            }
            return;
        }
        else if (start < finish) {
            for (int i = start; i < finish; i++) {
                cout << counter << ": " << storage[i] << endl;
                counter++;
            }
            return;
        }
    }
};

int main() {
    cout << "1.2\n";

    int n = 0;
    while (n < 1 || n > 100000){
        cout << "Enter the size of the array (from 1 to 10^5):\n";
        cin >> n;
        if (n < 1 || n > 100000){
            cout << "Incorrect input.\n";
        }
    }
    int S[n];
    int k = 0;
    while (k < 1 || k > 100){
        cout << "Enter number k (from 1 to 100):\n";
        cin >> k;
    }
    cout << "You want...\n" <<
            "1 - fill array from keyboard (from 1 to 10^9).\n" <<
            "2 - fill array with random numbers (from 1 to 10^9).\n";
    int fillArrayInt;
    cin >> fillArrayInt;
    switch (fillArrayInt) {
        case 1: {
            for (int i = 0; i < n; i++){
                S[i] = -2;
                while(S[i] < 1 || S[i] > 1000000000){
                    cout << "Element " << i+1 << ":\n" <<
                            "Enter an element value (from 1 to 10^9):\n";
                    cin >> S[i];
                    if (S[i] < 1 || S[i] > 1000000000){
                        cout << "Incorrect input.\n";
                    }
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < n; i++){
                S[i] = rand()%1000000000 + 1;
            }
            break;
        }
        default: {
            cout << "Incorrect input.\n";
            return -1;
        }
    }
    cout << "Input:\n";
    for (int i = 0; i < n; i++){
        cout << S[i] << "   ";
    }
    cout << "\n";

    vector<int> vectorS;
    for (int i = 0; i < n; i++){
        vectorS.push_back(S[i]);
    }
    vector<int> result;
    for (int i = 0; i < vectorS.size(); ++i)
    {
        int res = Sum(result, vectorS, i, 0, k);
        if (res != k) {
            result.push_back(res);
        }
    }
    cout << "The number of eligible sums:\n" << result.size() << endl;
    for (const int currentNumber : result) {
        cout << currentNumber << "   ";
    }
    cout << endl;

    cout << "2.2\n";

    Queue queue;
    int input01 = 1;
    while(input01 != 0) {
        cout << "You want to...\n1 - add element to queue.\n2 - delete first element of queue.\n" <<
        "3 - print size of queue.\n4 - display the queue.\n(0 - finish program.)\n";
        cin >> input01;
        switch (input01) {
            case 1: {
                int number;
                cout << "Enter number you want to add:\n";
                cin >> number;
                queue.push(number);
                break;
            }
            case 2: {
                cout << "The first element (" << queue.remove() << ")  has been removed.\n";
                break;
            }
            case 3: {
                cout << "Size of queue: \n" << queue.size() << endl;
                break;
            }
            case 4: {
                queue.print();
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

    return 0;
}

int Sum(std::vector<int>& result, const std::vector<int>& v, int index, int curSum, int k) {
    if (index < v.size())
    {
        curSum += v[index];
        for (int i = index + 1; i < v.size(); ++i)
        {
            int res = Sum(result, v, i, curSum, k);
            if (res != k) {
                result.push_back(res);
            }
        }
    }
    return curSum;
}


