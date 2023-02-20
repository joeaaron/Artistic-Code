#include "GoPiece.h"

int main()
{
	GoPieceFactory *factory = new GoPieceFactory;

	std::string personA = "A";
	std::string personB = "B";

	factory->GetGoPiece("black")->MoveTo(personA, 1, 1);
	factory->GetGoPiece("white")->MoveTo(personB, 2, 2);
	factory->GetGoPiece("black")->MoveTo(personA, 1, 2);
	factory->GetGoPiece("white")->MoveTo(personB, 2, 1);

	SAFE_DELETE(factory);

	return 0;
}