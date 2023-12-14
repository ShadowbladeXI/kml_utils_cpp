/*
 * kml_region.cpp
 *
 *  Created on: 17 Jun 2023
 *      Author: Alex
 */

#include "../include/kml_region.h"

#include <string>

namespace kml {

Region::Region(float bound_north_deg_n, float bound_south_deg_n, float bound_east_deg_e, float bound_west_deg_e, float bound_minAlt_m, float bound_maxAlt_m, float lod_minPx, float lod_maxPx, float lod_minFade_extend, float lod_maxFade_extend)
	:bound_north_deg_n(bound_north_deg_n)
	,bound_south_deg_n(bound_south_deg_n)
	,bound_east_deg_e(bound_east_deg_e)
	,bound_west_deg_e(bound_west_deg_e)
	,bound_minAlt_m(bound_minAlt_m)
	,bound_maxAlt_m(bound_maxAlt_m)
	,lod_minPx(lod_minPx)
	,lod_maxPx(lod_maxPx)
	,lod_minFade_extend(lod_minFade_extend)
	,lod_maxFade_extend(lod_maxFade_extend)
{}

Region::~Region() {}

const std::string_view& Region::get_xml_nodeName() const{
	return xml_nodeName;
}

rapidxml::xml_node<Ch_T>* Region::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
	auto* node = Object::create_xml(doc);

	auto* node_boundBox = doc.allocate_node(rapidxml::node_element, "LatLonAltBox");

	auto* bound_north_str = doc.allocate_string(std::to_string(bound_north_deg_n).c_str());
	auto* node_bound_north = doc.allocate_node(rapidxml::node_element, "north", bound_north_str);
	node_boundBox->append_node(node_bound_north);

	auto* bound_south_str = doc.allocate_string(std::to_string(bound_south_deg_n).c_str());
	auto* node_bound_south = doc.allocate_node(rapidxml::node_element, "south", bound_south_str);
	node_boundBox->append_node(node_bound_south);

	auto* bound_east_str = doc.allocate_string(std::to_string(bound_east_deg_e).c_str());
	auto* node_bound_east = doc.allocate_node(rapidxml::node_element, "east", bound_east_str);
	node_boundBox->append_node(node_bound_east);

	auto* bound_west_str = doc.allocate_string(std::to_string(bound_west_deg_e).c_str());
	auto* node_bound_west = doc.allocate_node(rapidxml::node_element, "west", bound_west_str);
	node_boundBox->append_node(node_bound_west);

	auto* bound_minAlt_str = doc.allocate_string(std::to_string(bound_minAlt_m).c_str());
	auto* node_minAlt = doc.allocate_node(rapidxml::node_element, "minAltitude", bound_minAlt_str);
	node_boundBox->append_node(node_minAlt);

	auto* bound_maxAlt_str = doc.allocate_string(std::to_string(bound_maxAlt_m).c_str());
	auto* node_maxAlt = doc.allocate_node(rapidxml::node_element, "maxAltitude", bound_maxAlt_str);
	node_boundBox->append_node(node_maxAlt);

	node->append_node(node_boundBox);

	auto* node_lod = doc.allocate_node(rapidxml::node_element, "Lod");

	auto* lod_minPx_str = doc.allocate_string(std::to_string(lod_minPx).c_str());
	auto* node_lod_minPx = doc.allocate_node(rapidxml::node_element, "minLodPixels", lod_minPx_str);
	node_lod->append_node(node_lod_minPx);

	auto* lod_maxPx_str = doc.allocate_string(std::to_string(lod_maxPx).c_str());
	auto* node_lod_maxPx = doc.allocate_node(rapidxml::node_element, "maxLodPixels", lod_maxPx_str);
	node_lod->append_node(node_lod_maxPx);

	auto* lod_minFade_str = doc.allocate_string(std::to_string(lod_minFade_extend).c_str());
	auto* node_lod_minFade = doc.allocate_node(rapidxml::node_element, "minFadeExtent", lod_minFade_str);
	node_lod->append_node(node_lod_minFade);

	auto* lod_maxFade_str = doc.allocate_string(std::to_string(lod_maxFade_extend).c_str());
	auto* node_lod_maxFade = doc.allocate_node(rapidxml::node_element, "maxFadeExtent", lod_maxFade_str);
	node_lod->append_node(node_lod_maxFade);

	node->append_node(node_lod);

	return node;
}

} /* namespace kml */
