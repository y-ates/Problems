#include <vector>
#include <iostream>

int tiefensuche(std::vector<std::vector<bool> > matrix, std::vector<int> nodes,
				std::vector<bool> nodesvisited,
				int current_node, int searched_node) {
	if (nodes[current_node] == searched_node) {
		std::cout << current_node << std::endl;
		return current_node;  // found
	} else {
		nodesvisited[current_node] = true;
		
		for (int i=0; i<nodes.size(); ++i) {
			if (matrix[current_node][i] && !nodesvisited[i]) {
				tiefensuche(matrix, nodes, nodesvisited, i, searched_node);
			}
		}
	}

	return -1;  // not found
}

int main(int argc, char* argv[]) {
	/**
	 * Testvalues
	 */

	std::vector<std::vector<bool> > matrix(10);
	std::vector<int> nodes {9, 8, 7, 5, 6, 4, 3, 1, 2, 0};
	std::vector<bool> nodesvisited(false);
	int current_node = 0;
	int searched_node = 2;
	
	return tiefensuche(matrix, nodes, nodesvisited, current_node,
					   searched_node);
}
