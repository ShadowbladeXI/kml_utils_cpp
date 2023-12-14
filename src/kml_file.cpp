/*
 * kml_file.cpp
 *
 *  Created on: 26 Mar 2023
 *      Author: Alex
 */

#include "../include/kml_file.h"

namespace kml {

	File::File(){}

	/*void File::link_object(Object& kml_object){
		kml_object.link_toFile(this);
	}*/

	void File::create_xmlDocument(rapidxml::xml_document<Ch_T>& xml_document_out) const{
		auto& doc = xml_document_out;

		//Add declaration node with standard attributes
		auto* declarationNode = doc.allocate_node(rapidxml::node_declaration);
		auto* declarationNode_version = doc.allocate_attribute("version", "1.0");
		declarationNode->append_attribute(declarationNode_version);
		auto* declarationNode_encoding = doc.allocate_attribute("encoding", "UTF-8");
		declarationNode->append_attribute(declarationNode_encoding);
		auto* declarationNode_standaloneFlag = doc.allocate_attribute("standalone", "yes");
		declarationNode->append_attribute(declarationNode_standaloneFlag);
		doc.append_node(declarationNode);

		//Add kml node
		auto* kmlNode = doc.allocate_node(rapidxml::node_element, "kml");
		auto* kmlNode_xmlns = doc.allocate_attribute("xmlns", "http://www.opengis.net/kml/2.2");
		kmlNode->append_attribute(kmlNode_xmlns);
		auto* kmlNode_xmlnsAtom = doc.allocate_attribute("xmlns:atom", "http://www.w3.org/2005/Atom");
		kmlNode->append_attribute(kmlNode_xmlnsAtom);
		auto* kmlNode_xmlnsGx = doc.allocate_attribute("xmlns:gx", "http://www.google.com/kml/ext/2.2");
		kmlNode->append_attribute(kmlNode_xmlnsGx);
		auto* kmlNode_xmlnsKml = doc.allocate_attribute("xmlns:kml", "http://www.opengis.net/kml/2.2");
		kmlNode->append_attribute(kmlNode_xmlnsKml);
		doc.append_node(kmlNode);

		if(containedFeature){
			auto* containedFeature_kml = containedFeature->create_xml(doc);
			kmlNode->append_node(containedFeature_kml);
		}
	}

	/*const rapidxml::xml_document<Ch_T>& File::get_xmlDocument() const{
		return doc;
	}
	rapidxml::xml_document<Ch_T>& File::get_xmlDocument(){
		return doc;
	}*/

}
