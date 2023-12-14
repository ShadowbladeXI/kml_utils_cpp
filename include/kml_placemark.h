/*
 * kml_placmark.h
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_PLACEMARK_H_
#define INCLUDE_KML_PLACEMARK_H_

#include <memory>

#include "kml_feature.h"
#include "kml_geometry.h"

namespace kml{

	class Placemark : public Feature{

	public:
		constexpr static std::string_view xml_nodeName = "Placemark";

	protected:
		std::unique_ptr<Geometry> geometry;

	public:
		Placemark();

		Placemark(std::string name);

		void set_geometry(std::unique_ptr<Geometry>&& geometry_new);

		const std::string_view& get_xml_nodeName() const override;

		rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

	protected:
		//void link_toFile(File* file) override;
	};

}

#endif /* INCLUDE_KML_PLACEMARK_H_ */
