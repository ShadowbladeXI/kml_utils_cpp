/*
 * kml_coordinates.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_coordinates.h"

#include <string>

namespace kml{

	Coordinates::Coordinates(double loaction_n_deg, double location_e_deg, std::optional<double> altitude_m)
		:loaction_n_deg(loaction_n_deg)
		,location_e_deg(location_e_deg)
		,altitude_m(altitude_m)
	{
		std::string string_alt;
		if(altitude_m.has_value()){
			string_alt = "," + std::to_string(*altitude_m);
		}else{
			string_alt = "";
		}
		string = (std::to_string(location_e_deg) + "," + std::to_string(loaction_n_deg) + string_alt);

	}

	Coordinates::Coordinates(double loaction_n_deg, double location_e_deg, double altitude_m)
		:Coordinates(loaction_n_deg, location_e_deg, std::make_optional(altitude_m))
	{}

	const std::string_view& Coordinates::get_xml_nodeName() const{
		return xml_nodeName;
	}

	const std::optional<std::string_view> Coordinates::xml_content_persistent(rapidxml::xml_document<Ch_T>& doc) const{
		return string;
	}

}


