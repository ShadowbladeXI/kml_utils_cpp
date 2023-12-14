/*
 * kml_file.h
 *
 *  Created on: 25 Mar 2023
 *      Author: Alex
 */

#ifndef KML_FILE_H_
#define KML_FILE_H_

#include <memory>
#include <optional>

#include "../external/rapidxml-1.13/rapidxml.hpp"

#include "kml_types.h"
#include "kml_feature.h"

namespace kml {

	//Forward declaration
	class Feature;

	class File{

	private:
		//rapidxml::xml_document<Ch_T> doc;
		//rapidxml::xml_node<Ch_T>* kmlNode;

		std::unique_ptr<Feature> containedFeature;

	public:
		File();

		~File(){
			//doc.clear();
		}

		template<typename Feature_Type>
		Feature_Type& add_feature(std::unique_ptr<Feature_Type>&& feature){
			static_assert(std::is_base_of<Feature, Feature_Type>::value, "Feature_Type must inherit from Feature");

			if(containedFeature){
				throw "Already contains a kml feature!";//TODO: Make own exceptions
			}else{
				//link_object(*feature);
				containedFeature = std::move(feature);

				//if(containedFeature->get_xml_node() == nullptr){
				//	containedFeature->create_xml();
				//}
				//kmlNode->append_node(containedFeature->get_xml_node());

				return dynamic_cast<Feature_Type&>(*containedFeature);
			}
		}

		//Link kml object to this file for xml cration (does not add it to the hirarchy)
		//void link_object(Object& kml_object);

		void create_xmlDocument(rapidxml::xml_document<Ch_T>& xml_document_out) const;

		//const rapidxml::xml_document<Ch_T>& get_xmlDocument() const;
		//rapidxml::xml_document<Ch_T>& get_xmlDocument();
	};

}

#endif /* KML_FILE_H_ */
