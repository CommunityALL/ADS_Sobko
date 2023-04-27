#include <iomanip>
#include <climits>
#include <iostream>

using namespace std;

const unsigned START = 2;
const unsigned VERTICES = 6;
const unsigned ADJACENCY_MATRIX[VERTICES][VERTICES] = {
        {1, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
void simplePathfindingAlgorithmDijkstra(const unsigned ADJACENCY_MATRIX[VERTICES][VERTICES], const unsigned &START);
void simplePathfindingAlgorithmDijkstraFloyd(const unsigned ADJACENCY_MATRIX[VERTICES][VERTICES], const unsigned VERTICES);

int main(){
    cout << "Lab_10 var_4" << endl;
    simplePathfindingAlgorithmDijkstra(ADJACENCY_MATRIX, START);

    simplePathfindingAlgorithmDijkstraFloyd(ADJACENCY_MATRIX, VERTICES);
    return 0;
}

void simplePathfindingAlgorithmDijkstra(const unsigned ADJACENCY_MATRIX[VERTICES][VERTICES], const unsigned &START) {
    cout << "Dijkstra's algorithm.\n";
    string letters[6] ={"a", "b", "c", "d", "e", "f"};
    bool visited[VERTICES];
    unsigned distances[VERTICES];
    unsigned minimalWeight, minimalIndex;

    for (unsigned i = 0; i < VERTICES; ++i)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[START] = 0;

    do {
        minimalIndex = INT_MAX;
        minimalWeight = INT_MAX;

        for (unsigned i = 0; i < VERTICES; ++i) {
            if (!visited[i] && distances[i] < minimalWeight) {
                minimalIndex = i;
                minimalWeight = distances[i];
            }
        }

        if (minimalIndex != INT_MAX) {
            for (unsigned i = 0; i < VERTICES; ++i) {
                if (ADJACENCY_MATRIX[minimalIndex][i]) {
                    unsigned temp = minimalWeight + ADJACENCY_MATRIX[minimalIndex][i];

                    if (temp < distances[i])
                        distances[i] = temp;
                }
            }

            visited[minimalIndex] = true;
        }
    }
    while (minimalIndex < INT_MAX);

    for (unsigned i = 0; i < VERTICES; ++i) {
        if (distances[i] != INT_MAX) {
            cout << "Weight: " << letters[START] << " ~> " << letters[i] << " = " << setw(6) << left << distances[i] << "\t";

            unsigned end = i;
            unsigned weight = distances[end];
            string way = letters[end] + " >~ ";

            while (end != START) {
                for (unsigned j = 0; j < VERTICES; ++j) {
                    if (ADJACENCY_MATRIX[j][end]) {
                        int temp = weight - ADJACENCY_MATRIX[j][end];

                        if (temp == distances[j]) {
                            end = j;
                            weight = temp;
                            way += letters[j] + " >~ ";
                        }
                    }
                }
            }

            cout << "Path: ";

            for (int j = way.length() - 5; j >= 0; --j)
                cout << way[j];

            cout << endl;
        }
        else
            cout << "Weight: " << letters[START] << " ~ " << letters[i] << " = " << "route is unavailable" << endl;
    }

}


void simplePathfindingAlgorithmDijkstraFloyd(const unsigned ADJACENCY_MATRIX[VERTICES][VERTICES], const unsigned VERTICES) {
    cout << "Floyd's algorithm\n";
    cout << "Shortest path matrix:\n";
    string letters[6] ={"a", "b", "c", "d", "e", "f"};
    int D[VERTICES][VERTICES];
    for(int i = 0; i < VERTICES; i++){
        for(int j = 0; j < VERTICES; j++){
            D[i][j] = ADJACENCY_MATRIX[i][j];
        }
    }
    for (int i = 0; i < VERTICES; i++) D[i][i]=0;

    for (int k = 0; k < VERTICES; k++)
        for (int i = 0; i < VERTICES; i++)
            for (int j = 0; j < VERTICES; j++)
                if (D[i][k] && D[k][j] && i!=j)
                    if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
                        D[i][j] = D[i][k] + D[k][j];

    for (int i = 0; i < VERTICES; i++){
        cout << " \t" << letters[i];
    }
    cout << endl;
    for (int i = 0; i < VERTICES; i++) {
        cout << letters[i] << "\t";
        for (int j = 0; j < VERTICES; j++) cout << D[i][j] << "\t";
        cout << endl;
    }
}