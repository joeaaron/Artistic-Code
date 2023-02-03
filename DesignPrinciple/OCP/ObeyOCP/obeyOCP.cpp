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

template <typename T>
struct ISpecification
{
	virtual ~ISpecification() = default;
	virtual bool IsSatisfied(T* item) const = 0;
};

struct ColorSpecification : ISpecification<Product>
{
	COLOR color;
	ColorSpecification(COLOR _color)
		:color(_color){}

	bool IsSatisfied(Product* item) const 
	{ 
		return item->m_color == color; 
	};
};

struct SizeSpecification : ISpecification<Product>
{
	SIZE size;
	SizeSpecification(SIZE _size) 
		: size(_size) {}

	bool IsSatisfied(Product* item) const 
	{ 
		return item->m_size == size; 
	};
};

template <typename T>
struct AndSpecification : ISpecification<T>
{
	const ISpecification<T>& first;
	const ISpecification<T>& second;

	AndSpecification(const ISpecification<T>& _first, const ISpecification<T>& _second)
		: first(_first), second(_second){}

	bool IsSatisfied(T* item) const
	{
		return first.IsSatisfied(item) && second.IsSatisfied(item);
	}
};

template <typename T>
AndSpecification<T> operator&&(const ISpecification<T>& first, const ISpecification<T>& second)
{
	return { first, second };
}

template <typename T>
struct IFilter
{
	virtual std::vector<T*> filter(std::vector<T*> items, const ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter<Product>
{
	Items filter(Items items, const ISpecification<Product>& spec)
	{
		Items result;
		for (auto& item:items)
		{
			if (spec.IsSatisfied(item))
			{
				result.emplace_back(item);
			}
		}

		return result;
	}
};

// ------------------------------------------------------------------------------------
int main()
{
	const Items all{
		new Product{"Apple", COLOR::eGreen, SIZE::eSmall},
		new Product{"Tree", COLOR::eGreen, SIZE::eLarge},
		new Product{"House", COLOR::eBlue, SIZE::eLarge},
	};

	BetterFilter bf;
	for (auto& x : bf.filter(all, ColorSpecification(COLOR::eGreen)))
	{
		std::cout << x->m_strName << " is green\n";
	}

	ColorSpecification green(COLOR::eGreen);
	SizeSpecification large(SIZE::eLarge);

	AndSpecification<Product> greenAndLarge{ green, large };
	for (auto& x : bf.filter(all, greenAndLarge))
	{
		std::cout << x->m_strName << " is green and large\n";
	}
	return EXIT_SUCCESS;
}
