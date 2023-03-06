/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */

#include <iostream>
#include <algorithm>
#include <string>

class Strategy
{
public:
	virtual ~Strategy() = default;
	virtual std::string DoAlgorithm(std::string strViewData) const = 0;
};

/**
 * The Context defines the interface of interest to clients.
 */
class Context
{
	/**
	 * @var Strategy The Context maintains a reference to one of the Strategy
	 * objects. The Context does not know the concrete class of a strategy. It
	 * should work with all strategies via the Strategy interface.
	 */
private:
	std::unique_ptr<Strategy> strategy_;
	/**
	* Usually, the Context accepts a strategy through the constructor, but also
	* provides a setter to change it at runtime.
	*/
public:
	explicit Context(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy))
	{
	}
	/**
	 * Usually, the Context allows replacing a Strategy object at runtime.
	 */
	void SetStrategy(std::unique_ptr<Strategy> &&strategy)
	{
		strategy_ = std::move(strategy);
	}
	/**
	* The Context delegates some work to the Strategy object instead of
	* implementing +multiple versions of the algorithm on its own.
	*/
	void DoSomeBusinessLogic() const
	{
		if (strategy_) {
			std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
			std::string strResult = strategy_->DoAlgorithm("aecbd");
			std::cout << strResult << "\n";
		}
		else {
			std::cout << "Context: Strategy isn't set\n";
		}
	}
};

/**
* Concrete Strategies implement the algorithm while following the base Strategy
* interface. The interface makes them interchangeable in the Context.
*/
class ConcreteStrategyA :public Strategy
{
public:
	std::string DoAlgorithm(std::string strViewData) const override
	{
		std::string strResult(strViewData);
		std::sort(std::begin(strResult), std::end(strResult));

		return strResult;
	}
};

class ConcreteStrategyB :public Strategy
{
public:
	std::string DoAlgorithm(std::string strViewData) const override
	{
		std::string strResult(strViewData);
		std::sort(std::begin(strResult), std::end(strResult), std::greater<>());

		return strResult;
	}
};

/**
 * The client code picks a concrete strategy and passes it to the context. The
 * client should be aware of the differences between strategies in order to make
 * the right choice.
 */
void clientCode()
{
	Context context(std::make_unique<ConcreteStrategyA>());
	std::cout << "Client: Strategy is set to normal sorting.\n";
	context.DoSomeBusinessLogic();
	std::cout << "\n";
	std::cout << "Client: Strategy is set to reverse sorting.\n";
	context.SetStrategy(std::make_unique<ConcreteStrategyB>());
	context.DoSomeBusinessLogic();
}

int main()
{
	clientCode();
	return 0;
}