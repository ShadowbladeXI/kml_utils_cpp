/*
 * kml_coordinates.h
 *
 *  Created on: 8 Apr 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_COORDINATES_H_
#define INCLUDE_KML_COORDINATES_H_

#include <optional>
#include <string>

#include "kml_object.h"

namespace kml{

	class Coordinates : public Object{

	public:
		constexpr static std::string_view xml_nodeName = "coordinates";

	protected:
		const double loaction_n_deg, location_e_deg;
		const std::optional<double> altitude_m;

		std::string string;

	public:
		Coordinates(double loaction_n_deg, double location_e_deg, std::optional<double> altitude_m = std::nullopt);

		Coordinates(double loaction_n_deg, double location_e_deg, double altitude_m);

		const std::string_view& get_xml_nodeName() const;

	protected:
		const std::optional<std::string_view> xml_content_persistent(rapidxml::xml_document<Ch_T>& doc) const override;
	};

}



#endif /* INCLUDE_KML_COORDINATES_H_ */
