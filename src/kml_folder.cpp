/*
 * kml_folder.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#include "../include/kml_folder.h"

namespace kml {

	Folder::Folder()
		:Container()
	{}

	const std::string_view& Folder::get_xml_nodeName() const{
		return xml_nodeName;
	}

}
