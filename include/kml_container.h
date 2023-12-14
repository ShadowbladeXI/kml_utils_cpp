/*
 * kml_container.h
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#ifndef KML_CONTAINER_H_
#define KML_CONTAINER_H_

#include <assert.h>
#include <vector>
#include <memory>

#include "kml_feature.h"

namespace kml {

	class Container : public Feature{
	private:
		std::vector<std::unique_ptr<Feature>> containedFeatures;

	public:
		Container();

		template<typename Feature_Type>
		Feature_Type& add_feature(std::unique_ptr<Feature_Type>&& feature){
			static_assert(std::is_base_of<Feature, Feature_Type>::value, "Feature_Type must inherit from Feature");

			std::unique_ptr<Feature>& feature_moved = add_feature_helper(std::move(feature));

			return dynamic_cast<Feature_Type&>(*feature_moved);
		}

		rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

		//void link_toFile(File* file) override;

	protected:
		//Helper class to get virtual behavior for part of template function
		virtual std::unique_ptr<Feature>& add_feature_helper(std::unique_ptr<Feature>&& feature);

	};

}

#endif /* KML_CONTAINER_H_ */
