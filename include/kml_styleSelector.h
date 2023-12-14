/*
 * kml_styleSelector.h
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_STYLESELECTOR_H_
#define INCLUDE_KML_STYLESELECTOR_H_

#include "kml_object.h"

#include <string>

namespace kml {

class StyleSelector : public Object{
public:
	const std::optional<std::string> id;

public:
	StyleSelector(const std::optional<std::string>& id = std::nullopt);

	virtual ~StyleSelector();

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

};

} /* namespace kml */

#endif /* INCLUDE_KML_STYLESELECTOR_H_ */
