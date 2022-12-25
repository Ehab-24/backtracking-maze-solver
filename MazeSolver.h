#pragma once

#include<unordered_set>
#include"structs.h"

void _findTarget(Node*** grid, Node* current, Node* target, std::unordered_set<Node*>& visited) {

	if (current == target) {
		return;
	}

	visited.insert(current);

	for (Node* n : current->neighbours) {
		if (n->isTraversable && visited.find(n) == visited.end()) {
			n->parent = current;
			_findTarget(grid, n, target, visited);
		}
	}
}

void findTarget(Node*** grid, Node* startingNode, Node* target) {

	std::unordered_set<Node*>visited;

	_findTarget(grid, startingNode, target, visited);
}