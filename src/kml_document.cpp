/*
 * kml_document.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_document.h"

namespace kml {

	Document::Document()
		:Container()
	{}

	const std::string_view& Document::get_xml_nodeName() const{
		return xml_nodeName;
	}

}
