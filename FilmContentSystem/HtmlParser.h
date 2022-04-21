#pragma once

#include "HtmlTag.h"
#include "Stack.hpp"
#include "CharString.h"
#include "FilmInfo.h"

/*
HtmlReader
Description: HtmlParser encapsulates some operations for reading html text, so that HtmlParser does not directly operate and store the reading status of html
Interface: For various read operations, please refer to the function declaration comments
*/

class HtmlReader {
private:
	CharString html;
	int hp;		// html pointer£¬point to the next character that should be read
public:
	HtmlReader();
	HtmlReader(const CharString &html);
	void setHtml(const CharString &_html);

	// Whether it is finished, the judgment condition is hp >= html.length()
	bool eof() const;
	// Read a character, move the hp pointer back by one
	wchar_t getChar();
	//Returns the character pointed to by the hp pointer, the hp pointer does not move
	wchar_t curChar() const;
	// Returns the character after the location pointed to by hp
	wchar_t nextChar() const;
	// Returns the previous character at the location pointed to by hp
	wchar_t prevChar() const;
	// Backspace: move the hp pointer forward one place
	void backSpace();

	// Read a string until stopChar is encountered, at the end of which hp points to the position of stopChar
	CharString getBlock(bool stopChar(wchar_t));
	CharString getBlock(wchar_t stopChar);
	// Skip a string until stopChar is encountered, at the end hp points to the position of stopChar
	void skipBlock(bool stopChar(wchar_t));
	void skipBlock(wchar_t stopChar);

	// Read JavaScript code, at the end hp points to the first position of </script> '<'
	// Assume that the script tag must be closed, and the closing tag exactly matches "</script>"
	// TODO: maybe </script>, etc
	CharString readScript();
};

// The status of the label (a segment of characters surrounded by '<' and '>'): open, closed, self-closing, comment, respectively
// eg: <p>, </p>, <br/>, <!--->
enum TagState {
	OPEN, CLOSED,SELFCLOSED, COMMENT
};

/*
HtmlParser
Description: Parse the desired movie information from html text
Full stack tag traversal: maintain a stack (HtmlTag type, including tag type, tag attributes, tag content),
The stack is maintained at all times as the hierarchical relationship between the current label and its outer labels
Has good scalability
Interface: parse: parse
*/

class HtmlParser
{
private:
	HtmlReader reader;
	// The stack is maintained at all times as the hierarchical relationship between the current label and its outer labels
	Stack<HtmlTag> tags;
	
	// Read a section of tags surrounded by '<' and '>', the hp of the reader should point to '<' when called
	HtmlTag readTag(TagState & closeState);

	CharString postProcessTitle(const CharString &name);
	// Process the synopsis, specifically, strip leading and trailing whitespace characters and convert <br> to '\n'
	CharString postProcessSummary(const CharString &summary);
	// Process a line in info, specifically, remove the leading to the colon, and break the following content according to " / "
	void postProcessInfoLine(const CharString &line, CharStringLink *item);
	// Process the text content of the div containing info, specifically, call postProcessInfoLine on the branch
	void postProcessInfo(const CharString &content, FilmInfo &info);
	// Process the label popped from the stack, specifically, determine whether it is the required movie information and call the corresponding function
	void postProcessTag(const HtmlTag& tag, FilmInfo &info);

public:
	HtmlParser();
	~HtmlParser();
	
	// Parse html, extract movie information and maintain tag stack at the same time
	FilmInfo parse(const CharString &html);
};

//Size of SELF_CLOSED_TAG array
const int NUM_SELF_CLOSED_TAG = 16;
//Self-closing tags specified in html
const wchar_t SELF_CLOSED_TAG[][10] = { L"area", L"base", L"br", L"col", L"command", L"embed", L"hr", L"img", L"input", L"keygen", L"link", L"meta", L"param", L"source", L"track", L"wbr" };
// Determine whether it is a self-closing tag such as isSelfClosed(L"br")==true
extern bool isSelfClosed(const CharString &tag);

