/*
 * kml_labelStyle.h
 *
 *  Created on: 18 Jun 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_LABELSTYLE_H_
#define INCLUDE_KML_LABELSTYLE_H_

#include "kml_colorStyle.h"

namespace kml {

class LabelStyle : public ColorStyle{
private:
	static constexpr std::string_view xml_nodeName = "LabelStyle";

	float scale;

public:
	LabelStyle(float scale = 1);

	virtual ~LabelStyle();

	const std::string_view& get_xml_nodeName() const override;

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;
};

} /* namespace kml */

#endif /* INCLUDE_KML_LABELSTYLE_H_ */
