/*
 * kml_point.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_point.h"
#include "../include/kml_file.h"

namespace kml{

	Point::Point(Coordinates coordinates)
		:Geometry()
		,coordinates(coordinates)
	{}

	const std::string_view& Point::get_xml_nodeName() const{
		return xml_nodeName;
	}

	rapidxml::xml_node<Ch_T>* Point::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
		auto* xml_node = Geometry::create_xml(doc);

		xml_node->append_node(coordinates.create_xml(doc));

		return xml_node;
	}

	/*void Point::link_toFile(File* file){
		Geomtry::link_toFile(file);

		file->link_object(coordinates);
	}*/

}

