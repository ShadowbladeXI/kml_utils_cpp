/*
 * kml_feature.cpp
 *
 *  Created on: 7 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_feature.h"

#include <assert.h>

#include "../include/kml_file.h"
#include "../include/kml_container.h"

namespace kml {

	Feature::Feature()
		:Object()
		,parent(nullptr)
		,name(std::nullopt)
		,description(std::nullopt)
		,styleSelector(nullptr)
		,timePrimitive(nullptr)
	{}

	bool Feature::has_parent() const{
		return get_parent() != nullptr;
	}


	const Feature* Feature::get_parent() const{
		return parent;
	}

	void Feature::set_name(const std::string& name){
		this->name = name;
	}

	void Feature::set_description(const std::string& description){
		this->description = description;
	}

	void Feature::link_toParent(Container* parent){
		this->parent = parent;

		/*if(!has_file()){
			link_toFile(parent->associatedFile);
		}else{
			assert(parent->get_file() == get_file());
		}*/
	}

	rapidxml::xml_node<Ch_T>* Feature::create_xml(rapidxml::xml_document<Ch_T>& doc) const {
		auto* xml_node = Object::create_xml(doc);

		if(name.has_value()){
			auto* name_node = doc.allocate_node(rapidxml::node_element, "name", name->c_str());
			xml_node->append_node(name_node);
		}

		if(description.has_value()){
			auto* description_node = doc.allocate_node(rapidxml::node_element, "description", description->c_str());
			xml_node->append_node(description_node);
		}

		if(styleSelector){
			auto* styleSelector_node = styleSelector->create_xml(doc);
			xml_node->append_node(styleSelector_node);
		}

		if(region.has_value()){
			auto* region_node = region->create_xml(doc);
			xml_node->append_node(region_node);
		}

		if(timePrimitive){
			auto* timePrimitive_node = timePrimitive->create_xml(doc);
			xml_node->append_node(timePrimitive_node);
		}

		return xml_node;
	}

	/*void Feature::append_nameNode_noCheck(){
		assert(name_node == nullptr);
		name_node = associatedFile->get_xmlDocument().allocate_node(rapidxml::node_element, "name", name->c_str());
		xml_node->append_node(name_node);
	}*/

}
