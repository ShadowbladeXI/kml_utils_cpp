/*
 * kml_style.cpp
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#include "../include/kml_style.h"

namespace kml {

Style::Style(const std::optional<std::string>& id)
	:StyleSelector(id)
{}

const std::string_view& Style::get_xml_nodeName() const {
	return xml_nodeName;
}

rapidxml::xml_node<Ch_T>* Style::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
	auto* node = StyleSelector::create_xml(doc);

	if(iconStyle.has_value()){
		auto* node_iconStyle = iconStyle->create_xml(doc);
		node->append_node(node_iconStyle);
	}

	if(labelStyle.has_value()){
		auto* node_labelStyle = labelStyle->create_xml(doc);
		node->append_node(node_labelStyle);
	}

	return node;
}

Style::~Style() {}

} /* namespace kml */
