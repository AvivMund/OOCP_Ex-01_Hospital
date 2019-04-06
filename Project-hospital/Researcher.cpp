#include "researcher.h"

Researcher::Researcher(const char inName[MAX_NAME])
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	articleStock = nullptr;
	logSizeOfArticles = 0;
	phySizeOfArticles = 0;
}

Researcher::~Researcher()
{
	delete[] name;
	for (int i = 0; i < logSizeOfArticles; i++)
		delete articleStock[i];
	delete[] articleStock;
}

void Researcher::addArticle(Article& art)
{
	allocationArticlesArr();
	articleStock[logSizeOfArticles] = &art;
	logSizeOfArticles++;
}

void Researcher:: allocationArticlesArr()
{
	if (phySizeOfArticles == 0) // If this is the 1st Department
	{
		articleStock = new Article*;
		phySizeOfArticles++;
	}
	else if (logSizeOfArticles == phySizeOfArticles) //if there is no place in the array
	{
		phySizeOfArticles *= 2;
		Article** newArr = new Article*[phySizeOfArticles];
		for (int i = 0; i < logSizeOfArticles; i++)
		{
			newArr[i] = articleStock[i];
		}
		delete[] articleStock;
		articleStock = newArr;
	}
	else
		return;
}

const char* Researcher::getName() const
{
	return name;
}

void Researcher::showArticles() const
{
	if (logSizeOfArticles)
	{
		for (int i = 0; i < logSizeOfArticles; i++)
		{
			cout << "Article name: " << articleStock[i]->getName() << endl;
			cout << "Magazine in which was published: " << articleStock[i]->getMagazineName() << endl;;
			cout << "Publication date: ";
			articleStock[i]->showDate();
			cout << endl;
		}
	}
	else
		cout << "There is no article for this researcher" << endl;
}






