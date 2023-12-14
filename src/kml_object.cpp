/*
 * kml_object.cpp
 *
 *  Created on: 7 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_object.h"

#include <assert.h>

#include "../include/kml_file.h"

namespace kml {

	Object::Object(){}

	/*const File* Object::get_file() const{
		return associatedFile;
	}*/

	/*bool Object::has_file() const{
		return get_file() != nullptr;
	}*/

	/*const rapidxml::xml_node<Ch_T>* Object::get_xml_node() const{
		return xml_node;
	}
	rapidxml::xml_node<Ch_T>* Object::get_xml_node() {
		return xml_node;
	}*/

	rapidxml::xml_node<Ch_T>* Object::create_xml(rapidxml::xml_document<Ch_T>& doc) const{
		const std::optional<std::string_view>& xml_content_opt = xml_content_persistent(doc);
		const Ch_T* xml_content_first;
		std::size_t xml_content_size;
		if(xml_content_opt.has_value()){
			xml_content_first = xml_content_opt->data();
			xml_content_size = xml_content_opt->size();
		}else{
			xml_content_first = 0;
			xml_content_size = 0;
		}

		return doc.allocate_node(rapidxml::node_element, get_xml_nodeName().data(), xml_content_first, get_xml_nodeName().size(), xml_content_size);
	}

	/*void Object::link_toFile(File* file){
		if(associatedFile != nullptr){
			if(associatedFile != file){
				throw "Already linked to a different file!";//TODO: Make own exceptions
			}
		}
		associatedFile = file;
	}*/

}
