/*
 * kml_timeSpan.h
 *
 *  Created on: 4 Jul 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_TIMESPAN_H_
#define INCLUDE_KML_TIMESPAN_H_

#include "kml_timePrimitive.h"

#include <string>

namespace kml {

class TimeSpan : public TimePrimitive {
public:
	constexpr static std::string_view xml_nodeName = "TimeSpan";

private:
	std::optional<std::string> begin;
	std::optional<std::string> end;

public:
	TimeSpan(std::optional<std::string>&& begin, std::optional<std::string>&& end);

	virtual ~TimeSpan();

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

	const std::string_view& get_xml_nodeName() const override;
};

} /* namespace kml */

#endif /* INCLUDE_KML_TIMESPAN_H_ */
