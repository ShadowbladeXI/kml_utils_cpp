/*
 * kml_feature.h
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#ifndef KML_FEATURE_H_
#define KML_FEATURE_H_



#include <string>
#include <optional>

#include "kml_object.h"
#include "kml_styleSelector.h"
#include "kml_region.h"
#include "kml_timePrimitive.h"

namespace kml {

	//forward declaration
	class KML_Container;

	class Feature : public Object{
	protected:

		Container* parent;

		std::optional<std::string> name;
		std::optional<std::string> description;
		//rapidxml::xml_node<Ch_T>* name_node;

		std::unique_ptr<StyleSelector> styleSelector;

		std::optional<Region> region;

		std::unique_ptr<TimePrimitive> timePrimitive;

	public:

		Feature();

		Feature(std::string name);

		virtual ~Feature(){}

		bool has_parent() const;

		const Feature* get_parent() const;

		void set_name(const std::string& name);

		void set_description(const std::string& description);

		template<typename StyleSelector_Type>
		void set_styleSelector(const StyleSelector_Type& styleSelector){
			this->styleSelector = std::make_unique<StyleSelector_Type>(styleSelector);
		}

		void set_region(Region&& region_new){
			region.reset();
			region = std::make_optional(std::move(region_new));
		}

		template<typename TimePrimitive_Type>
		void set_timePrimitive(TimePrimitive_Type timePrimitive){
			this->timePrimitive = std::make_unique<TimePrimitive_Type>(timePrimitive);
		}

	protected:
		/*
		 * Functions for linking
		 */

		//These classes should initiate the linking and therfore need access
		friend class Container;

		virtual void link_toParent(Container* parent);

	public:
		rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

	private:
		//void append_nameNode_noCheck();

	};




}

#endif /* KML_FEATURE_H_ */
