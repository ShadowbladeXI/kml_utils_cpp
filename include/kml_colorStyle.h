/*
 * kml_colorStyle.h
 *
 *  Created on: 21 May 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_COLORSTYLE_H_
#define INCLUDE_KML_COLORSTYLE_H_

#include "kml_object.h"

namespace kml {

class ColorStyle: public Object {
public:
	ColorStyle(){}

	virtual ~ColorStyle(){}
};

} /* namespace kml */

#endif /* INCLUDE_KML_COLORSTYLE_H_ */
