/*
 * kml_point.cpp
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_POINT_CPP_
#define INCLUDE_KML_POINT_CPP_

#include <string_view>
#include <optional>

#include "kml_geometry.h"
#include "kml_coordinates.h"

namespace kml{

	class Point : public Geometry{

	public:
		constexpr static std::string_view xml_nodeName = "Point";

	protected:
		Coordinates coordinates;

	public:

		Point(Coordinates coordinates);

		const std::string_view& get_xml_nodeName() const;

		rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

	protected:
		//void link_toFile(File* file) override;
	};

}



#endif /* INCLUDE_KML_POINT_CPP_ */
