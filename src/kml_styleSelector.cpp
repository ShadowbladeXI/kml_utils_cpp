/*
 * kml_styleSelector.cpp
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#include "../include/kml_styleSelector.h"

namespace kml {

StyleSelector::StyleSelector(const std::optional<std::string>& id)
	:id(id)
{

}

StyleSelector::~StyleSelector() {}

rapidxml::xml_node<Ch_T>* StyleSelector::create_xml(rapidxml::xml_document<Ch_T>& doc) const {
	auto* node = Object::create_xml(doc);

	if(id.has_value()){
		auto* id_attribute = doc.allocate_attribute("id", id->c_str());
		node->append_attribute(id_attribute);
	}

	return node;
}

} /* namespace kml */
