#include "article.h"

Article::Article(const char inName[MAX_NAME], char*inMagazineName, Date& inPublicitaion)
{
	copyName(inName, name);
	copyName(inMagazineName, magazineName);
	publicationDate = inPublicitaion;
}


Article::Article(const Article& other)
{
	copyName(other.name, name);
	copyName(other.magazineName, magazineName);
	publicationDate = other.publicationDate;
}

Article::~Article()
{
	delete[]name;
	delete[]magazineName;
}

const char* Article::getName() const
{
	return name;
}
const char* Article::getMagazineName() const
{
	return magazineName;
}
void Article::showDate() const
{
	publicationDate.showDate();
}

