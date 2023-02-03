struct Document;

struct IPrinter
{
	virtual void Print(Document& doc) = 0;
};

struct IScanner
{
	virtual void Scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
	void Print(Document& doc) override;
};

struct Scanner : IScanner
{
	void Scan(Document& doc) override;
};

struct IMachine : IPrinter, IScanner{};

struct Machine : IMachine
{
	IPrinter& m_printer;
	IScanner& m_scanner;

	Machine(IPrinter& p, IScanner& s):m_printer(p), m_scanner(s){}

	void Print(Document& doc) override { m_printer.Print(doc); }
	void Scan(Document& doc) override { m_scanner.Scan(doc); }

};