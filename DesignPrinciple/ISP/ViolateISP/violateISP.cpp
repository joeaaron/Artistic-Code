struct Document;

struct IMachine
{
	virtual void Print(Document& doc) = 0;
	virtual void Fax(Document& doc) = 0;
	virtual void Scan(Document& doc) = 0;
};

struct MultiFunctionPrinter :IMachine					// OK
{
	void Print(Document& doc) override {};
	void Fax(Document& doc) override {};
	void Scan(Document& doc) override {};
};

struct Scanner : IMachine								// Not OK
{
	void Print(Document& doc) override {};
	void Fax(Document& doc) override {};
	void Scan(Document& doc) override {};
};

int main()
{
	return 0;
}