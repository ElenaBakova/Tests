#include "FSM.h"
#include <stdbool.h>
#include <ctype.h>

enum States {
	start,
	firstGroup,
	atSign, 
	secondGroup,
	point,
	thirdDigit
};

bool isFirstGroup(char sign)
{
	return (sign >= 'A' && sign <= 'Z' || isdigit(sign) || sign == '.' || sign == '_' || sign == '%' || sign == '+' || sign == '-');
}

bool isSecondGroup(char sign)
{
	return (sign >= 'A' && sign <= 'Z' || isdigit(sign) || sign == '-');
}

bool isValid(char* string)
{
	enum States state = start;
	int current = 0;
	while (true)
	{
		char token = string[current];
		switch (state)
		{
		case start:
			if (isFirstGroup(token))
			{
				state = firstGroup;
				break;
			}
			return false;
		case firstGroup:
			if (isFirstGroup(token))
			{
				break;
			}
			if (token == '@')
			{
				state = atSign;
				break;
			}
			return false;
		case atSign:
			if (isSecondGroup(token))
			{
				state = secondGroup;
				break;
			}
			return false;
		case secondGroup:
			if (isSecondGroup(token))
			{
				break;
			}
			if (token == '.')
			{
				state = point;
				break;
			}
			return false;
		case point:
			if (token >= 'A' && token <= 'Z')
			{
				state = thirdDigit;
				break;
			}
			if (isSecondGroup(token))
			{
				state = secondGroup;
				break;
			}
			return false;
		case thirdDigit:
			if (token == '.')
			{
				state = point;
				break;
			}
			if (token == '\0' || token == '\n')
			{
				return true;
			}
			return false;
		default:
			break;
		}
		current++;
	}
}