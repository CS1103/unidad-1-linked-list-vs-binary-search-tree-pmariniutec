//
// Created by ruben on 4/5/19.
//
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Location.h"
#include "utils.h"

namespace UTEC {

  struct NodeLL {
	Location data;
	NodeLL* next;
	NodeLL(const Location &data) : data(data) { }
  };

  class LinkedList {
	public:
	  LinkedList();
	  ~LinkedList();
	  int size();
	  bool is_empty();
	  NodeLL* get_head();
	  NodeLL* get_tail();
	  void add_head(const Location &data);
	  void add_tail(const Location &data);
	  void print();
	  void insert(NodeLL* position, const Location& data);
	  NodeLL* search(const int position_id);
	private:
	  NodeLL* head;
	  NodeLL* tail;
  };

  void load_locations(LinkedList *ll, const std::string file_name);
}

