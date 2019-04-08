#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <fstream>

#include "utils.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

  // Declarando variables
  LinkedList *ll = new LinkedList();
  BinarySearchTree *bst = new BinarySearchTree();
  std::vector<int> vsearch;

  double avgtime_ll = 0;
  double avgtime_bst = 0;

  std::ifstream f(SEARCH_FILE);
  std::string content;
  if (!f.is_open()) {
	std::cout << "Couldn't open file\n";
	delete ll;
	delete bst;
	return -1;
  }

  while(std::getline(f, content, '\n')) {
	vsearch.push_back(std::stoi(content)); 
  }

  UTEC::load_locations(ll, LOCATION_FILE);
  auto start = std::chrono::high_resolution_clock::now();
  for (const auto& id: vsearch) {
	ll->search(id);
  }
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  avgtime_ll = elapsed.count() * 1000;

  UTEC::load_locations(bst, LOCATION_FILE);
  start = std::chrono::high_resolution_clock::now();
  for (const auto& id: vsearch) {
	bst->search(id);
  }
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish - start;
  avgtime_bst = elapsed.count() * 1000;

  std::cout << "LL: " << avgtime_ll << "ms \n";
  std::cout << "BST: " << avgtime_bst << "ms \n";

  delete ll;
  delete bst;


  return 0;
}
