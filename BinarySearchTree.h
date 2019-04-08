//
// Created by ruben on 4/5/19.
//
#pragma once

#include <iostream>
#include <fstream>
#include "Location.h"
#include "utils.h"

namespace UTEC {

  struct Node {
	Location data;
	Node* right;
	Node* left;
	Node(const Location &data) : data(data), right(nullptr), left(nullptr) { }
  };

  class BinarySearchTree {
	public:
	  BinarySearchTree();
	  ~BinarySearchTree();
	  void insert(const Location &data);
	  void clear();
	  bool is_empty();
	  Node* get_root();
	  Node* search(const int position_id);
	  void print();
	private:
	  void remove(Node *node);
	  Node* root = nullptr;
  };

  void load_locations(BinarySearchTree* bst, std::string file_name);
  void print_node(Node* node);
}

