//
// Created by ruben on 4/5/19.
//

#include "Location.h"
#include <iostream>

Location::Location(int position_id, std::string state_code, std::string county, 
				   double latitude, double longitude, std::string line, 
				   std::string construction) 
				  : position_id(position_id), state_code(state_code), county(county),
				    latitude(latitude), longitude(longitude), line(line),
					construction(construction) { }


Location::Location(const Location &data)
				  : position_id(data.position_id), state_code(data.state_code),
					county(data.county), latitude(data.latitude), 
					longitude(data.longitude), line(data.line), 
					construction(data.construction) { }
