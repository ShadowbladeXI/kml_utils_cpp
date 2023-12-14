/*
 * kml_document.h
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#ifndef KML_DOCUMENT_H_
#define KML_DOCUMENT_H_

#include "kml_container.h"

namespace kml {

	class Document : public Container{
	private:
		constexpr static std::string_view xml_nodeName = "Document";

	public:
		Document();

		const std::string_view& get_xml_nodeName() const override;
	};

}

#endif /* KML_DOCUMENT_H_ */
