#include "Graf.h"
using namespace std;
Graf::Graf() {
    clear();
}
void Graf::createVertices(int ile) {
    numberOfVertices = ile;
}
void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if (i_Vertex_Index_1 < numberOfVertices && i_Vertex_Index_2 < numberOfVertices) {
            matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 1;
        }
}
void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 0;
}
bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
    if (i_Vertex_Index_1 < numberOfVertices && i_Vertex_Index_2 < numberOfVertices) {
        return matrix[i_Vertex_Index_1][i_Vertex_Index_2] == 1;
    }
    return false;
}
int Graf::vertexDegree(int idx) {
    int vertexDegreeCount = 0;
    if (idx < numberOfVertices) {
        for (int i = 0; i < numberOfVertices; ++i) {
            if (matrix[idx][i]==1)
                vertexDegreeCount++;
        }
    }
    return vertexDegreeCount;
}

vector<int> Graf::getNeighbourIndices(int idx) {
    vector<int> neighbours;
    if (idx < numberOfVertices) {
        for (int i = 0; i < numberOfVertices; ++i) {
            if (matrix[idx][i]==1)
                neighbours.push_back(i);
        }
    }
    return neighbours;
}

void Graf::printNeighbourIndices(int idx) {
    if (idx < numberOfVertices) {
        cout << "Neighbours of vertex " << idx << ": ";
        for (int i = 0; i < numberOfVertices; ++i) {
            if (matrix[idx][i]==1)
                cout << i << " ";
        }
        cout << endl;
    }
}

int Graf::getNumberOfEdges() {
    int numEdge = 0;
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (matrix[i][j] == 1)
                numEdge++;
        }
    }
    return numEdge;
}

void Graf::readFromFile(string path){
    ifstream file(path);
    if (file.is_open()){
        int vertex1, vertex2, numberOfV;
        file >> numberOfV;
        createVertices(numberOfV);
        while(file >> vertex1 >> vertex2){
            addEdge(vertex1, vertex2);
        }
        file.close();
    } else {
        cerr << "ERROR: something is wrong with loading from file" << endl;
    }
}

void Graf::clear() {
    numberOfVertices = 0;
    for (auto & i : matrix) {
        for (int & j : i) {
            j = 0;
        }
    }
}
