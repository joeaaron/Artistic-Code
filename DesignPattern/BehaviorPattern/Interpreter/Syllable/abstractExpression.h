#pragma once
#include <string>
#include <list>
#include <iostream>

#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

std::list<std::string> split(const std::string& str, const std::string& pattern)
{
	std::list<std::string> ret;
	if (pattern.empty()) return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos)
	{
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
	return ret;
}

class AbstractExpression
{
public:
	virtual ~AbstractExpression() {}
	virtual std::string Interpret(std::string context) = 0;
};

class Scale_NonTerminalExpression : public AbstractExpression
{
public:
	virtual std::string Interpret(std::string context) {
		if (context == "1")
			return "Do";
		else if (context == "2")
			return "Re";
		else if (context == "3")
			return "Mi";
		else if (context == "4")
			return "Fa";
		else if (context == "5")
			return "Sol";
		else if (context == "6")
			return "La";
		else
			return "Xi";
	}
};

class Note_NonTerminalExpression : public AbstractExpression
{
public:
	virtual std::string Interpret(std::string context) {
		if (context == "1")
			return "全音符";
		else if (context == "1/2")
			return "二分音符";
		else if (context == "1/4")
			return "四分音符";
		else
			return "八分音符";
	}
};

class TerminalExpression : public AbstractExpression {
public:
	TerminalExpression() : m_scale(new Scale_NonTerminalExpression), m_note(new Note_NonTerminalExpression) {}
	~TerminalExpression() { SAFE_DELETE(m_scale); SAFE_DELETE(m_note); }

	virtual std::string Interpret(std::string context) {
		std::list<std::string> split_result = split(context, " ");
		if (split_result.size() != 2) return "";

		std::string scale = m_scale->Interpret(split_result.front());
		std::string note = m_note->Interpret(split_result.back());
		return scale + " " + note;
	}

private:
	Scale_NonTerminalExpression * m_scale;
	Note_NonTerminalExpression * m_note;
};

