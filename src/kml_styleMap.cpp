/*
 * kml_styleMap.cpp
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#include "../include/kml_styleMap.h"

namespace kml {

/*StyleMap::StyleMap(const std::string& id, const Style& normal, const std::optional<std::string>& normal_url, const Style& highlight, const std::optional<std::string>& highlight_url)
	:StyleSelector(id)
	,normal(normal), normal_url(normal_url)
	,highlight(highlight), highlight_url(highlight_url)
{}

StyleMap::StyleMap(const std::string& id, const Style& normal, const Style& highlight, const std::optional<std::string>& url)
	:StyleMap(id, normal, url, highlight, url)
{}

StyleMap::StyleMap(const std::string& id, const Style& normal, const Style& highlight)
	:StyleMap(id, normal, highlight, std::nullopt)
{}*/

rapidxml::xml_node<Ch_T>* StyleMap::create_xml(rapidxml::xml_document<Ch_T>& doc) const {
	auto* node = StyleSelector::create_xml(doc);

	if(normal.has_value()){
		auto* node_normal = create_pair_xml(doc, "normal", *normal);
		node->append_node(node_normal);
	}

	if(highlight.has_value()){
		auto* node_highlight = create_pair_xml(doc, "highlight", *highlight);
		node->append_node(node_highlight);
	}

	return node;
}

rapidxml::xml_node<Ch_T>* StyleMap::create_pair_xml(rapidxml::xml_document<Ch_T>& doc, const std::string_view& key, const std::variant<Style_Link, Style>& style) const {
	auto* node = doc.allocate_node(rapidxml::node_element, "Pair");

	auto* key_node = doc.allocate_node(rapidxml::node_element, "key", key.data(), 0, key.length());
	node->append_node(key_node);

	if(std::holds_alternative<Style_Link>(style)){
		const Style_Link& style_link = std::get<Style_Link>(style);

		const std::string& style_link_string_temp = style_link.get_string();
		auto style_link_string = doc.allocate_string(style_link_string_temp.c_str());

		auto* style_node = doc.allocate_node(rapidxml::node_element, "styleUrl", style_link_string);
		node->append_node(style_node);
	}else{
		const Style& style_ref = std::get<Style>(style);

		auto* style_node = style_ref.create_xml(doc);
		node->append_node(style_node);
	}

	return node;
}

std::variant<StyleMap::Style_Link, Style> StyleMap::make_style_external(const Style& style, std::optional<std::string> url) const{
	return Style_Link(style, url);
}

std::variant<StyleMap::Style_Link, Style> StyleMap::make_style_internal(Style&& style) const{
	return std::move(style);
}

} /* namespace kml */
