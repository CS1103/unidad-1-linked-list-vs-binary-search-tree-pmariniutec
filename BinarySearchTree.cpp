//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"

void UTEC::print_node(UTEC::Node *node) {
  if (node != nullptr) { 
	auto data = node->data;
	std::cout << "Position Id: " << data.position_id << '\n';
	std::cout << "State Code: " << data.state_code << '\n';
	std::cout << "Construction: " << data.construction << '\n';
	std::cout << "County: " << data.county << '\n';
	std::cout << "Latitude: " << data.latitude << '\n';
	std::cout << "Line: " << data.line << '\n';
	std::cout << "Longitude: " << data.longitude << '\n';
  }
}

UTEC::BinarySearchTree::BinarySearchTree() : root(nullptr) {}

UTEC::BinarySearchTree::~BinarySearchTree() {
  remove(root);
}

void UTEC::BinarySearchTree::remove(UTEC::Node *node) {
  if (node == nullptr)
	return;

  if (node->left) remove(node->left);
  if (node->right) remove(node->right);
  delete node;
}

UTEC::Node *UTEC::BinarySearchTree::search(const int position_id) {
  Node *current = root;

  while (current != nullptr) {
	if (current->data.position_id == position_id) return current;

	if (position_id >= current->data.position_id)
	  current = current->right;  
	else
	  current = current->left;
  }

  return nullptr;
}

void UTEC::BinarySearchTree::insert(const Location &data) {
  Node *current = root;
  Node *parent = nullptr;

  if (root == nullptr) {
	root = new Node(data);
	return;
  }

  while (current != nullptr) {
	parent = current;
	if (data.position_id >= current->data.position_id)
	  current = current->right;
	else
	  current = current->left;
  }

  if (data.position_id >= parent->data.position_id)
	parent->right = new Node(data);
  else
	parent->left = new Node(data);
}

UTEC::Node *UTEC::BinarySearchTree::get_root() { return root; }

void UTEC::load_locations(BinarySearchTree* bst, std::string file_name) {

  std::ifstream f(file_name);

  if (!f.is_open()) {
	std::cout << "Couldn't open file\n";
	return;
  }

  std::string content;
  int count = 0;

  while(std::getline(f, content, '\n')) {
	if (count == 0) {
	  count++;
	  continue; 
	}

	std::vector<std::string> tokens = UTEC::split(content, ',');

	Location data = Location(std::stoi(tokens[0]), tokens[1], tokens[2], 
		std::stoi(tokens[3]), std::stoi(tokens[4]),
		tokens[5], tokens[6]);
	bst->insert(data);
	count++;
  }
}
