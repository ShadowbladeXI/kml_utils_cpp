/*
 * kml_labelStyle.cpp
 *
 *  Created on: 18 Jun 2023
 *      Author: Alex
 */

#include "../include/kml_labelStyle.h"

#include <string>

namespace kml {

LabelStyle::LabelStyle(float scale)
	:scale(scale)
{}

LabelStyle::~LabelStyle() {}

const std::string_view& LabelStyle::get_xml_nodeName() const {
	return xml_nodeName;
}

rapidxml::xml_node<Ch_T>* LabelStyle::create_xml(rapidxml::xml_document<Ch_T>& doc) const {
	auto* node = ColorStyle::create_xml(doc);

	auto* scale_str = doc.allocate_string(std::to_string(scale).c_str());
	auto* node_scale = doc.allocate_node(rapidxml::node_element, "scale", scale_str);
	node->append_node(node_scale);

	return node;
}

} /* namespace kml */
