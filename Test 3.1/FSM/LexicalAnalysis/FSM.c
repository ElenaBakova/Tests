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

}

bool isRealNumber(char* string)
{
	enum States state = start;
	int current = 0;
	while (true)
	{
		char token = string[current];
		switch (state)
		{
		case start:
			if (isdigit(token))
			{
				state = firstGroup;
				break;
			}
			return false;
		case firstGroup:
			if (isdigit(token))
			{
				break;
			}
			if (token == '.')
			{
				state = atSign;
				break;
			}
			else if (token == 'E')
			{
				state = point;
				break;
			}
			else if (token == '\0' || token == '\n')
			{
				return true;
			}
			return false;
		case atSign:
			if (isdigit(token))
			{
				state = secondGroup;
				break;
			}
			return false;
		case secondGroup:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '\0' || token == '\n')
			{
				return true;
			}
			if (token == 'E')
			{
				state = point;
				break;
			}
			return false;
		case point:
			if (isdigit(token))
			{
				state = thirdDigit;
				break;
			}
			if (token == '-' || token == '+')
			{
				state = sign;
				break;
			}
			return false;
		case sign:
			if (isdigit(token))
			{
				state = thirdDigit;
				break;
			}
			return false;
		case thirdDigit:
			if (isdigit(token))
			{
				break;
			}
			else if (token == '\0' || token == '\n')
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