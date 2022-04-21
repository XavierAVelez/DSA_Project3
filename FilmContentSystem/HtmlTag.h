#pragma once

#include "Vector.hpp"
#include "CharString.h"
#include <cstdio>
#include <cstdlib>

/*
TagAttribute
Description: A data structure used to represent attributes of html tags, storing a pair of key values
Interface: Read: key/value
*/

class TagAttribute {
private:
	CharString _key, _value;
public:
	TagAttribute() { }
	TagAttribute(const CharString &key, const CharString &value) :_key(key), _value(value) { }
	TagAttribute(const CharString &key):_key(key),_value() { }
	const CharString &key() const { return _key; }
	const CharString &value() const { return _value; }
};

/*
HtmlTag
Description: The data structure used to represent the html tag, which stores the tag type, tag attributes, and the text content in the tag
Interface: Read operation: type/attributes/content
Modify operation: addAttribute/pushContent
Query operation: hasAttribute
*/

class HtmlTag
{
	CharString _type;				
	Vector<TagAttribute> _attr;		
	CharString _content;			
public:
	HtmlTag();
	HtmlTag(const CharString &type);
	~HtmlTag();
	const CharString &type() const { return _type; }
	const Vector<TagAttribute>& attributes() const { return _attr; }
	const CharString &content() const { return _content; }
	
	// Add property, only key without value
	void addAttribute(const CharString &key);
	// Add property, key-value pair
	void addAttribute(const CharString &key, const CharString &value);
	// concat to the end of the text content
	void pushContent(const CharString &content);

	// Find if there is a given property
	bool hasAttribute(const CharString &key) const;
	bool hasAttribute(const CharString &key, const CharString &value) const;
	CharString attributeValue(const CharString &key) const;
};

