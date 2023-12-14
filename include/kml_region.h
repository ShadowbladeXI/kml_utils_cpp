/*
 * kml_region.h
 *
 *  Created on: 17 Jun 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_REGION_H_
#define INCLUDE_KML_REGION_H_

#include "kml_object.h"

namespace kml {

class Region : public Object{
private:
	static constexpr std::string_view xml_nodeName = "Region";

	float bound_north_deg_n;
	float bound_south_deg_n;
	float bound_east_deg_e;
	float bound_west_deg_e;
	float bound_minAlt_m;
	float bound_maxAlt_m;

	float lod_minPx;
	float lod_maxPx;
	float lod_minFade_extend;
	float lod_maxFade_extend;

public:
	Region(float bound_north_deg_n, float bound_south_deg_n, float bound_east_deg_e, float bound_west_deg_e, float bound_minAlt_m = 0, float bound_maxAlt_m = 0, float lod_minPx = 0, float lod_maxPx =-1, float lod_minFade_extend = 0, float lod_maxFade_extend = 0);

	virtual ~Region();

	const std::string_view& get_xml_nodeName() const override;

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

};

} /* namespace kml */

#endif /* INCLUDE_KML_REGION_H_ */
