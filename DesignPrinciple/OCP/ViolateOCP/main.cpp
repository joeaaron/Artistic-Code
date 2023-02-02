#include <string>
#include <vector>
#include <iostream>

enum class COLOR
{
	eRed = 0,
	eGreen,
	eBlue
};

enum class SIZE
{
	eSmall = 0,
	eMedium,
	eLarge
};

struct Product
{
	std::string m_strName;
	COLOR m_color;
	SIZE m_size;
};

using Items = std::vector<Product*>;

struct ProductFilter
{
	static Items FilterByColor(Items items, const COLOR eColor)
	{
		Items result;
		for (auto& item:items)
		{
			if (item->m_color == eColor)
			{
				result.emplace_back(item);
			}
		}

		return result;
	}

	static Items FilterBySize(Items items, const SIZE eSize)
	{
		Items result;
		for (auto& item : items)
		{
			if (item->m_size == eSize)
			{
				result.emplace_back(item);
			}
		}

		return result;
	}

	static Items FilterBySizeAndColor(Items items, const SIZE eSize, const COLOR eColor)
	{
		Items result;
		for (auto& item : items)
		{
			if (item->m_size == eSize && item->m_color == eColor)
			{
				result.emplace_back(item);
			}
		}

		return result;
	}
};

int main()
{
	const Items all{
		new Product{"Apple", COLOR::eGreen, SIZE::eSmall},
		new Product{"Tree", COLOR::eGreen, SIZE::eLarge},
		new Product{"House", COLOR::eBlue, SIZE::eLarge},
	};

	for (auto& p:ProductFilter::FilterByColor(all, COLOR::eGreen))
	{
		std::cout << p->m_strName << " is green\n";
	}

	for (auto& p : ProductFilter::FilterBySizeAndColor(all, SIZE::eLarge, COLOR::eGreen))
	{
		std::cout << p->m_strName << " is green & large\n";
	}

	return EXIT_SUCCESS;
}