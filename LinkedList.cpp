//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"

UTEC::LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

UTEC::LinkedList::~LinkedList() {
  if (head == nullptr) return;

  NodeLL *next = head;
  NodeLL *cur = nullptr;
  while (next != nullptr) {
	cur = next;
	next = next->next;
	delete cur;
  }
}

int UTEC::LinkedList::size() {
  int count = 0;
  NodeLL* actual = head;
  while(actual != nullptr) {
	count++;
	actual = actual->next;
  }
  return count;
}

void UTEC::LinkedList::print() {
  NodeLL *tmp = head;
  while (tmp != nullptr) {
	std::cout << tmp->data.position_id << ' ';
	tmp = tmp->next;
  }
  std::cout << '\n';
}

bool UTEC::LinkedList::is_empty() {
  return head == nullptr;
}

UTEC::NodeLL *UTEC::LinkedList::get_head() {
  return head;
}

UTEC::NodeLL *UTEC::LinkedList::get_tail() {
  return tail;
}

// Linear Search
UTEC::NodeLL *UTEC::LinkedList::search(const int position_id) {
  NodeLL *tmp = head;
  while (tmp != nullptr) {
	if (tmp->data.position_id == position_id)  {
	  return tmp;
	}
	tmp = tmp->next;
  }
  return nullptr;
}

void UTEC::LinkedList::add_head(const Location &data) {
  NodeLL *tmp = new NodeLL(data);
  if (!is_empty()) {
	tmp->next = head;
	head = tmp;
  } else {
	tail = tmp;
	head = tmp;
  }
}

void UTEC::LinkedList::add_tail(const Location &data) {
  NodeLL *tmp = new NodeLL(data);

  if (!is_empty()) {
	tail->next = tmp;
	tail = tmp;
  } else {
	tail = tmp;
	head = tmp;
  }
}

void UTEC::load_locations(LinkedList *ll, const std::string file_name) {

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
	ll->add_tail(data);
	count++;
  }

}
