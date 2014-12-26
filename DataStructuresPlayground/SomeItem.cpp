#include "stdafx.h"
#include "SomeItem.h"
#include <stdlib.h>
#include <time.h>

SomeItem::SomeItem()
{
	srand(time(NULL));
	someInt = rand() % 10 + 1;
	someChar = someInt;
}


SomeItem::~SomeItem()
{
}
