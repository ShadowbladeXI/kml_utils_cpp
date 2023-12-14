/*
 * kml_style.h
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_STYLE_H_
#define INCLUDE_KML_STYLE_H_

#include "kml_styleSelector.h"

#include <string_view>

#include "kml_iconStyle.h"
#include "kml_labelStyle.h"

namespace kml {

class Style: public StyleSelector {
public:
	static constexpr std::string_view xml_nodeName = "Style";

private:
	std::optional<IconStyle> iconStyle;
	std::optional<LabelStyle> labelStyle;

	//TODO: Implment LineStyle
	//TODO: Implment PolyStyle
	//TODO: Implment BalloonStyle
	//TODO: Implment ListStyle

public:
	Style(const std::optional<std::string>& id = std::nullopt);
	virtual ~Style();

	const std::string_view& get_xml_nodeName() const override;

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

	void set_iconStyle(IconStyle&& iconStyle_new){
		iconStyle.reset();
		iconStyle = std::make_optional(std::move(iconStyle_new));
	}

	void set_labelStyle(LabelStyle&& labelStyle_new){
		labelStyle.reset();
		labelStyle = std::make_optional(std::move(labelStyle_new));
	}
};

} /* namespace kml */

#endif /* INCLUDE_KML_STYLE_H_ */
