/*
 * kml_object.h
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#ifndef KML_OBJECT_H_
#define KML_OBJECT_H_

#include <string_view>
#include <memory>
#include <optional>

#include "../external/rapidxml-1.13/rapidxml.hpp"

#include "kml_types.h"

namespace kml {

	/*
	 * forward declarations
	 */
	class File;

	class Container;


	class Object{
	protected:

		//File* associatedFile;
		//rapidxml::xml_node<Ch_T>* xml_node;

	public:
		Object();

		virtual ~Object(){}

		//const File* get_file() const;

		//bool has_file() const;

		//const rapidxml::xml_node<Ch_T>* get_xml_node() const;
		//rapidxml::xml_node<Ch_T>* get_xml_node();

	protected:

		//friend class File;
		//virtual void link_toFile(File* file);

	public:
		virtual rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const;

	public:
		virtual const std::string_view& get_xml_nodeName() const = 0;

	protected:
		//Has to return a string view which lasts at least until this object is modified
		//Alternatively, the string can be allocated in the provided xml_document
		//If no text content is dsired, return an empty optional (default behavior)
		virtual const std::optional<std::string_view> xml_content_persistent(rapidxml::xml_document<Ch_T>& doc) const{
			return std::nullopt;
		}
	};


}

#endif /* KML_OBJECT_H_ */
