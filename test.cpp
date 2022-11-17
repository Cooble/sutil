#include <iostream>

#include "sutil.h"
#include <cassert>

using namespace sil;


int main(int, const char**)
{
	{
		// removeComments
		Stringo src =
			R"(Hello there /*this is comment*///helpme
	sup)";

		Stringo target =
			R"(Hello there                            
	sup)";

		removeComments(src);
		assert(src == target);
	}

	{
		// toLower
		Stringo src = R"(WHy Me)";
		Stringo target = R"(why me)";

		toLower(src);
		assert(src == target);
	}
	{
		// toUpper
		Stringo src = R"(WHy Me)";
		Stringo target = R"(WHY ME)";

		toUpper(src);
		assert(src == target);
	}
	{
		//splitString
		std::string s = " Yet Another\n  Fun";

		std::vector<Stringo> t0;
		std::vector<Stringo> t;
		t.push_back("Yet");
		t.push_back("Another");
		t.push_back("Fun");

		splitString(s, t0, "\n ");
		assert(t0 == t);
	}
	{
		//spliterator
		std::string s = " Yet Another\n  Fun";
		auto split = Spliterator<>(s, " \n");

		std::vector<Stringo> t0;
		std::vector<Stringo> t;
		t.emplace_back("");
		t.emplace_back("Yet");
		t.emplace_back("Another");
		t.emplace_back("");
		t.emplace_back("");
		t.emplace_back("Fun");

		while(split)
		{
			t0.emplace_back(*split);
			++split;
		}
		assert(t0 == t);
	}
	{
		//spliterator no blanks
		std::string s = " Yet Another\n  Fun";
		auto split = Spliterator<true>(s, " \n");

		std::vector<Stringo> t0;
		std::vector<Stringo> t;
		t.emplace_back("Yet");
		t.emplace_back("Another");
		t.emplace_back("Fun");

		while (split)
		{
			t0.emplace_back(*split);
			++split;
		}
		assert(t0 == t);
	}
}
