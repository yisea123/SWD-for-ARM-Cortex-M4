#ifndef Token_H
#define Token_H

typedef enum
{
	UNKNOWN,
	NUMBER_TOKEN,
	OPERATOR_TOKEN,
	IDENTIFIER_TOKEN,
	FILE_TOKEN,
}TokenTypeDef;

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "StringObject.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "IdentifierToken.h"
#include "FileToken.h"
#include "ErrorCode.h"
#include "CException.h"

typedef struct
{
	TokenTypeDef type;
}Token;

Token *getToken(String *expression);
#endif // Token_H
