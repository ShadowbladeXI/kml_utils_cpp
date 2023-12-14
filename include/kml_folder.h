/*
 * kml_folder.h
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#ifndef KML_FOLDER_H_
#define KML_FOLDER_H_

#include "kml_container.h"

namespace kml {

	class Folder : public Container{
	private:
		constexpr static std::string_view xml_nodeName = "Folder";

	public:
		Folder();

		const std::string_view& get_xml_nodeName() const override;
	};

}

#endif /* KML_FOLDER_H_ */
