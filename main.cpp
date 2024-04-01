#include <iostream>
#include <vector>

const int size = 9;



void addEdges(std::vector<int> (&matrix)[size+1], std::vector<std::vector<int>> &weights, int firstNode, int secondNode, int weight)
{
    matrix[firstNode].push_back(secondNode);
    matrix[secondNode].push_back(firstNode);
    weights[firstNode][secondNode] = weight;
    weights[secondNode][firstNode] = weight;
}

std::vector<int> dijkstra(std::vector<int> (&matrix)[size+1], std::vector<std::vector<int>> &weights, int startNode, int destinationNode)
{
    int nextNode = 0;
    std::vector<int> result;
    std::vector<bool> visited(size + 1, false);
    result.push_back(startNode);
    for(int i = startNode; i < size + 1;)
    {
        visited[i] = true;
        int min = 1000;
        for(const auto &node : matrix[i])
        {
            std::cout << "I'm on the node: " << node << "\t" << "The weight is: " << weights[i][node] << std::endl;
            if(node == destinationNode)
            {
                result.push_back(node);
                return result;
            }
            if(!visited[node] && weights[i][node] < min)
            {
                min = weights[i][node];
                nextNode = node;
            }
        }
        i = nextNode;
        result.push_back(i);        
    }
    return {1};
}

int main()
{
    std::vector<int> matrix[size + 1];
    std::vector<std::vector<int>> weights(size + 1, std::vector<int>(size + 1));

    addEdges(matrix, weights, 1, 2, 3);
    addEdges(matrix, weights, 1, 4, 4);
    addEdges(matrix, weights, 1, 5, 5);
    addEdges(matrix, weights, 2, 3, 2);
    addEdges(matrix, weights, 2, 6, 6);
    addEdges(matrix, weights, 3, 8, 7);
    addEdges(matrix, weights, 4, 6, 1);
    addEdges(matrix, weights, 5, 7, 7);
    addEdges(matrix, weights, 6, 8, 4);
    addEdges(matrix, weights, 7, 8, 2);
    addEdges(matrix, weights, 7, 9, 3);
    addEdges(matrix, weights, 8, 9, 5);

    for(int i = 1; i < size + 1; i++)
    {
        std::cout << "Node: " << i << "\t";
        for(const auto &node : matrix[i])
        {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    std::vector<int> result = dijkstra(matrix, weights, 1, 6);
    for(const auto &node : result)
    {
        std::cout << node << " ";
    }
}