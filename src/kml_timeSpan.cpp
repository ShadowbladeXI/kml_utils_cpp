/*
 * kml_timeSpan.cpp
 *
 *  Created on: 4 Jul 2023
 *      Author: Alex
 */

#include "../include/kml_timeSpan.h"

namespace kml {

TimeSpan::TimeSpan(std::optional<std::string>&& begin, std::optional<std::string>&& end)
	:begin(std::move(begin)), end(std::move(end))
{}

TimeSpan::~TimeSpan() {}

rapidxml::xml_node<Ch_T>* TimeSpan::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
	auto* node = TimePrimitive::create_xml(doc);

	if(begin.has_value()){
		auto* begin_node = doc.allocate_node(rapidxml::node_element, "begin", begin->c_str());
		node->append_node(begin_node);
	}
	if(end.has_value()){
		auto* end_node = doc.allocate_node(rapidxml::node_element, "end", end->c_str());
		node->append_node(end_node);
	}

	return node;
}

const std::string_view& TimeSpan::get_xml_nodeName() const {
	return xml_nodeName;
}

} /* namespace kml */
