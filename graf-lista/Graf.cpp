#include "Graf.h"
#include "edge.h"
using namespace std;
Graf::Graf(){}
void Graf::createVertices(int ile){
    vertexList.resize(ile);
}
void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
        vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2));
        vertexList[i_Vertex_Index_2].push_back(edge(i_Vertex_Index_2, i_Vertex_Index_1));
}
bool Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    for(auto item = vertexList[i_Vertex_Index_1].begin(); item != vertexList[i_Vertex_Index_1].end(); item++){
        if(item->vertex_Index2==i_Vertex_Index_2){
            vertexList[i_Vertex_Index_1].erase(item);
            break;
        }
    }
    for(auto item = vertexList[i_Vertex_Index_2].begin(); item != vertexList[i_Vertex_Index_2].end(); item++){
        if(item->vertex_Index2==i_Vertex_Index_1){
            vertexList[i_Vertex_Index_2].erase(item);
            return true;
        }
    }
    return false;
}
bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    for(const auto& item : vertexList[i_Vertex_Index_1]){
        if (item.vertex_Index2==i_Vertex_Index_2)
            return true;
    }
    return false;
}
int Graf::vertexDegree(int idx){
    return vertexList[idx].size();
}
vector<int> Graf::getNeighbourIndices(int idx){
    vector<int> neighbours;
    for(auto& item : vertexList[idx]){
        neighbours.push_back(item.vertex_Index2);
    }
    return neighbours;
}
void Graf::printNeighbourIndices(int idx){
    vector<int> neighbours = getNeighbourIndices(idx);
    cout << "Neighbours of vertex " << idx << ": ";
    int lastPrint= -1;
    for(int i : neighbours){
        if (i != lastPrint) {
            cout << i << " ";
            lastPrint= i;
        }
    }
    cout << endl;
}
int Graf::getNumberOfEdges() {
    int numEdge = 0;
    for(const auto& vertex : vertexList){
        numEdge += vertex.size();
    }
    return numEdge/2;
}

void Graf::readFromFile(std::string path){
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
