//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LOCATION_H
#define LINKEDLISTVSBINARYTREE_LOCATION_H
#include <string>

struct Location {
  Location(int position_id,
		   std::string state_code,
		   std::string county,
		   double latitude,
		   double longitude,
		   std::string line,
		   std::string construction);

  Location(const Location &data);

  int position_id;
  double latitude;
  double longitude;
  std::string state_code;
  std::string county;
  std::string line;
  std::string construction;
};


#endif //LINKEDLISTVSBINARYTREE_LOCATION_H
