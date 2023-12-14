/*
 * kml_container.cpp
 *
 *  Created on: 7 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_container.h"

#include "../include/kml_file.h"

namespace kml {

	Container::Container()
		:Feature()
		,containedFeatures()
	{}

	rapidxml::xml_node<Ch_T>* Container::create_xml(rapidxml::xml_document<Ch_T>& doc) const {
		auto* container_node = Feature::create_xml(doc);

		for(auto& feature : containedFeatures){
			auto* feature_node = feature->create_xml(doc);
			container_node->append_node(feature_node);
		}

		return container_node;
	}

	/*void Container::link_toFile(File* file){
		Feature::link_toFile(file);

		for(auto& feature : containedFeatures){
			file->link_object(*feature);
		}
	}*/

	std::unique_ptr<Feature>& Container::add_feature_helper(std::unique_ptr<Feature>&& feature){
		assert(!feature->has_parent());

		feature->link_toParent(this);

		containedFeatures.push_back(std::move(feature));

		return containedFeatures.back();
	}
}
