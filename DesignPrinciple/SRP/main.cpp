#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Journal
{
public:
	explicit Journal(const std::string& strTitle)
		:m_strTitile{strTitle}{}
	
	void AddEntries(const std::string& strEntry)
	{
		static uint32_t count = 1;
		m_vStrEntries.emplace_back(std::to_string(count++) + ": " + strEntry);
	}

	auto GetEntries() const { return m_vStrEntries; }

	//void Save(const std::string& strFileName) 
	//{
	//	std::ofstream ofs(strFileName);
	//	for (auto &s : m_vStrEntries)
	//	{
	//		ofs << s << std::endl;
	//	}
	//}

private:
	std::string m_strTitile;
	std::vector<std::string> m_vStrEntries;
};

struct SavingManager
{
	static void Save(const Journal& j, const std::string& strFileName)
	{
		std::ofstream ofs(strFileName);
		for (auto &s : j.GetEntries())
		{
			ofs << s << std::endl;
		}
	}
};


int main()
{
	Journal journal{ "Dear XYZ" };
	journal.AddEntries("I ate a bug");
	journal.AddEntries("I cried today");
	journal.AddEntries("I quit the job");
	//journal.Save("diary.txt");
	SavingManager::Save(journal, "diary.txt");

	return EXIT_SUCCESS;
}