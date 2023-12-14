/*
 * kml_iconStyle.h
 *
 *  Created on: 21 May 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_ICONSTYLE_H_
#define INCLUDE_KML_ICONSTYLE_H_

#include "kml_colorStyle.h"

namespace kml {

class IconStyle: public ColorStyle {
public:

	constexpr static std::string_view xml_nodeName = "IconStyle";

private:
	std::optional<std::string> icon_href;
	float scale;
	float heading_deg;


public:

	IconStyle(std::optional<std::string> icon_href, float scale = 1.0f, float heading_deg = 0.0f)
		:ColorStyle()
		,icon_href(icon_href)
		,scale(scale)
		,heading_deg(heading_deg)
	{}

	const std::string_view& get_xml_nodeName() const override{
		return xml_nodeName;
	}

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override{
		auto* node = ColorStyle::create_xml(doc);

		if(icon_href.has_value()){
			auto* node_icon = doc.allocate_node(rapidxml::node_element, "Icon");

			auto* node_icon_href = doc.allocate_node(rapidxml::node_element, "href", icon_href->c_str());
			node_icon->append_node(node_icon_href);

			node->append_node(node_icon);
		}

		auto* scale_str = doc.allocate_string(std::to_string(scale).c_str());
		auto* node_scale = doc.allocate_node(rapidxml::node_element, "scale", scale_str);
		node->append_node(node_scale);

		auto* heading_str = doc.allocate_string(std::to_string(heading_deg).c_str());
		auto* node_heading = doc.allocate_node(rapidxml::node_element, "heading", heading_str);
		node->append_node(node_heading);

		return node;
	}

};

} /* namespace kml */

#endif /* INCLUDE_KML_ICONSTYLE_H_ */
