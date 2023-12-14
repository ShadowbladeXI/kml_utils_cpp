/*
 * kml_placemark.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_placemark.h"

#include <string>

#include "../include/kml_file.h"

namespace kml{

	Placemark::Placemark()
		:Feature()
		,geometry(nullptr)
	{}

	void Placemark::set_geometry(std::unique_ptr<Geometry>&& geometry_new){
		geometry = std::move(geometry_new);
	}

	/*void Placemark::link_toFile(File* file){
		Feature::link_toFile(file);

		if(geometry != nullptr){
			associatedFile->link_object(*geometry);
		}
	}*/

	const std::string_view& Placemark::get_xml_nodeName() const{
		return xml_nodeName;
	}

	rapidxml::xml_node<Ch_T>* Placemark::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
		auto* xml_node = Feature::create_xml(doc);

		if(geometry){
			auto* geometry_node = geometry->create_xml(doc);
			xml_node->append_node(geometry_node);
		}

		return xml_node;
	}
}
