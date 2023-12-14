/*
 * kml_styleMap.h
 *
 *  Created on: 14 May 2023
 *      Author: Alex
 */

#ifndef INCLUDE_KML_STYLEMAP_H_
#define INCLUDE_KML_STYLEMAP_H_

#include <variant>

#include "kml_styleSelector.h"
#include "kml_style.h"

namespace kml {

class StyleMap: public StyleSelector {
public:
	static constexpr std::string_view xml_nodeName = "StyleMap";

private:
	//class to hold link to a style
	class Style_Link{
	public:
		const Style& style;
		const std::optional<std::string> url;//url to file if the style is defined in another document

	private:
		const std::string& style_id;

	public:
		Style_Link(const Style& style, const std::optional<std::string>& url = std::nullopt)
			:style(style)
			,url(url)
			,style_id(style.id.value())
		{
			//if(!style.id.has_value()){
			//	throw "Shared styles need an id";//TODO: Make dedicated exceptions
			//}
		}

		std::string get_string() const{
			if(url.has_value()){
				return *url + "#" + style_id;
			}else{
				return "#" +style_id;
			}
		}
	};


	//TODO: Change to unordered map? Are other than "normal" and "highlight" possible?
	std::optional<std::variant<Style_Link, Style>> normal;
	std::optional<std::variant<Style_Link, Style>> highlight;

	//const Style* normal;
	//const std::optional<std::string> normal_url;

	//const Style* highlight;
	//const std::optional<std::string> highlight_url;

public:
	StyleMap(const std::optional<std::string>& id = std::nullopt)
		:StyleSelector(id)
		,normal(std::nullopt), highlight(std::nullopt)
	{}

	//reference to style must be kept valid, style must be added to the document at url (or same document if no url is provided)
	void set_normal_external(const Style& style, std::optional<std::string> url = std::nullopt){
		normal.emplace(make_style_external(style, url));
	}
	void set_normal_internal(Style&& style){
		normal.emplace(make_style_internal(std::move(style)));
	}

	//reference to style must be kept valid, style must be added to the document at url (or same document if no url is provided)
	void set_highlight_external(const Style& style, std::optional<std::string> url = std::nullopt){
		highlight.emplace(make_style_external(style, url));
	}
	void set_highlight_internal(Style&& style){
		highlight.emplace(make_style_internal(std::move(style)));
	}

	/*
	//"normal" and "highlight" references have to be kept valid
	//"normal" and "highlight" have to be implemented in documents at the indicated urls
	StyleMap(const std::string& id, const Style& normal, const std::optional<std::string>& normal_url, const Style& highlight, const std::optional<std::string>& highlight_url);

	//"normal" and "highlight" references have to be kept valid
	//"normal" and "highlight" have to be implemented in a document at the indicated url
	StyleMap(const std::string& id, const Style& normal, const Style& highlight, std::optional<const std::string>& url);

	//"normal" and "highlight" references have to be kept valid
	//"normal" and "highlight" have to be implemented in the same document as this Style Map
	StyleMap(const std::string& id, const Style& normal, const Style& highlight);
	 */

	virtual ~StyleMap(){}

public:

	const std::string_view& get_xml_nodeName() const override{
		return xml_nodeName;
	}


public:

	rapidxml::xml_node<Ch_T>* create_xml(rapidxml::xml_document<Ch_T>& doc) const override;

private:
	//reference to style must be kept valid, style must be added to the document at url (or same document if no url is provided)
	std::variant<Style_Link, Style> make_style_external(const Style& style, std::optional<std::string> url = std::nullopt) const;

	std::variant<Style_Link, Style> make_style_internal(Style&& style) const;

	rapidxml::xml_node<Ch_T>* create_pair_xml(rapidxml::xml_document<Ch_T>& doc, const std::string_view& key, const std::variant<Style_Link, Style>& style) const;

};

} /* namespace kml */

#endif /* INCLUDE_KML_STYLEMAP_H_ */
