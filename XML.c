#include "XML.h"
//XmlParserState xmlParserState = STATE_START_BLOCK;
//int FindBlock()
//{
//    switch (xmlParserState)
//    {
//    case STATE_START_BLOCK :
//        if(ch == '<')
//            xmlParserState  = STATE_SEARCH_ELEMENT;
//        else
//            xmlParserState  = STATE_START_BLOCK;
//        elementIndex=0;
//        break;
//
//    case STATE_SEARCH_ELEMENT :
//        if(ch == element[elementIndex++] )
//        {
//            xmlParserState  = STATE_SEARCH_ELEMENT;
//            if(element[elementIndex] == '\0')
//            {
//                xmlParserState  = STATE_SEARCH_SPACE;
//            }
//        }
//        else
//            xmlParserState  = STATE_START_BLOCK;
//        break;
//
//    case STATE_SEARCH_SPACE:
//        if(ch == ' ')
//        {
//            elementIndex = 0;
//            xmlParserState  = STATE_SEARCH_ATTRIBUTES;
//        }
//        else
//            xmlParserState  = STATE_START_BLOCK;
//        break;
//
//    case STATE_SEARCH_ATTRIBUTES :
//        if(ch != '>')
//        {
//            if(elementIndex < STORE_ELEMENT_SIZE)
//                storeElement [elementIndex++] = ch ;
//            xmlParserState  = STATE_SEARCH_ATTRIBUTES;
//        }
//        else if(ch == '>')
//        {
//            storeElement [elementIndex]='\0';
//            elementIndex=0;
//            if (strstr( storeElement, att ) != NULL )
//            {
//                xmlParserState  = STATE_STORE_BLK;
//            }
//            else
//            {
//                xmlParserState  = STATE_START_BLOCK;
//            }
//        }
//
//        break;
//
//    case STATE_STORE_BLK :
//        if(elementIndex < STORE_ELEMENT_SIZE)
//            storeElement [elementIndex++] = ch;
//        if(ch != '>')
//        {
//            xmlParserState  = STATE_STORE_BLK;
//        }
//        else
//        {
//            storeElement [elementIndex] = '\0';
//            if (strstr( storeElement, endatt ) != NULL )
//            {
//                elementIndex=0;
//                return 1;
//            }
//            else
//            {
//                xmlParserState  = STATE_STORE_BLK;
//            }
//        }
//        break;
//    }
//    return 0;
//}
//
//
//
//void GetElement(char *element , char *search, char *result, U16 maxLen)
//{
//	char *strptr;
//	char *endptr;
//	U8 reslen=0;
//	U8 i;
//	strptr = strstr( element, search );
//	endptr = strstr( element, endstr );
//	if(strptr != NULL)
//	{
//		strptr += strlen(search);
//		reslen =  strlen(strptr) - strlen(endptr);
//	}
//	for(i=0 ;( i<reslen && i < (maxLen-1)); i++)
//		result[i]=strptr[i];
//	result[i] = '\0';
//}
#include <stdio.h>
#include <string.h>
#include "XML.h"
char  endBlock[MAX_STORE_ELEMENT_SIZE]={0};
//char* GetEndTag(char* block)
//{
//    strcpy(endBlock,"</");
//    return strcat(endBlock,block);
//}

char* GetEndTag(char* block)
{
    strcpy(endBlock,"</");
    strcat(endBlock,block);
    strcat(endBlock,">");
    return endBlock;
}

//int ReadBlockWithAttribute(char ch,attributeParam* attParam,int attNo,char* result)
//{
//    static XmlParserState parserState = STATE_START_BLOCK;
//    static elementIndex;
//    static bool elementStored;
//    char *posOfEndTag;
//    static attIndex=0;
//    static char lastChar = 0;
//    static DataStorageState storeContents = DATASTORGAE_STATUS_NONE;
//
//    switch (parserState)
//    {
//        case STATE_START_BLOCK :
//            if(ch == '<')
//                parserState  = STATE_SEARCH_ELEMENT;
//            else
//                parserState  = STATE_START_BLOCK;
//            if(ch == '?')
//                attIndex =0;
//            elementIndex=0;
//            elementStored= false;
//            break;
//
//         case STATE_SEARCH_ELEMENT :
//
//            if(ch != ' ' && ch!= '>' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_ELEMENT;
//                    result[elementIndex++] = ch;
//                }
//            }
//            else
//            {
//                elementStored=true;
//            }
//            if((ch == ' ' || ch == '>')&& elementStored==true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
////                 printf("block 1: %s\n",attParam[attIndex].block);
//////                 printf("block 2: %s\n",attParam[attIndex+1].block);
////                 printf("attribute Index: %d\n",attIndex);
//                if(strcmp(result,attParam[attIndex].block) == NULL)
//                {
//                    parserState = STATE_SEARCH_ATTRIBUTES;
//                    elementStored =false;
//                }
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("block: %s\n",block);
////                printf("Result of strcmp: %d\n",strcmp(result,block));
//            }
//            break;
//        case STATE_SEARCH_ATTRIBUTES :
//            if(ch != '=' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_ATTRIBUTES;
//                    result[elementIndex++] = ch;
//                }
//            }
//            else
//            {
//                elementStored=true;
//            }
//            if(ch == '=' && elementStored==true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                if(strcmp(result,attParam[attIndex].attribute) == NULL)
//                {
//                    parserState = STATE_SEARCH_KEY;
//                    elementStored = false;
//                }
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("attribute: %s\n",attribute);
////                printf("Result of strcmp: %d\n",strcmp(result,attribute));
//            }
//            break;
//        case STATE_SEARCH_KEY :
//
//            if( ch!= '>' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_KEY;
//                    result[elementIndex++] = ch;
//                }
//            }
//            else
//            {
//                elementStored = true;
//            }
//            if(( ch == '>') && elementStored == true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                elementIndex = 0;
//                elementStored = false;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n",result);
////                printf("key: %s\n",attParam[attIndex].key);
////                printf("Result of strstr: %d\n",strstr(result,attParam[attIndex].key));
//                if(strstr(result,attParam[attIndex].key) != NULL)
//                {
//                    attIndex++;
//                    if(attIndex < attNo)
//                        parserState = STATE_START_BLOCK;
//                    else
//                        parserState = STATE_STORE_BLOCK;
//                }
//                else
//                    parserState = STATE_START_BLOCK;
//            }
//            break;
//        case STATE_STORE_BLOCK :
//            if(elementIndex < MAX_SEARCH_ELEMENT )
//            {
//                // STOP when "<!" found (avoid storing comment tags)
//                if(lastChar == '<' && ch == '!')
//                {
//                  storeContents = DATASTORGAE_STATUS_STOP;
//                  elementIndex --;
//                }
//                // TAGEND when "</" found (avoid storing space after end tag)
//                else if(lastChar == '<' && ch == '/')
//                   storeContents = DATASTORGAE_STATUS_TAGENDED;
//                // TAGEND when "</ .... >" found (avoid storing space after end tag)
//                else if(lastChar == '>' && storeContents == DATASTORGAE_STATUS_TAGENDED)
//                    storeContents = DATASTORGAE_STATUS_STOP;
//                // TAGEND when "<" found after "<!--><"
//                // or "</....><" (avoid storing space before start tag.)
//                if(ch == '<' && storeContents == DATASTORGAE_STATUS_STOP)
//                    storeContents = DATASTORGAE_STATUS_NONE;
//
//                if((storeContents !=DATASTORGAE_STATUS_STOP))
//                    result[elementIndex++] = ch;
//                lastChar = ch;
//            }
//            else
//            {
//                 parserState  = STATE_START_BLOCK;
//                 result [elementIndex-1]='\0';
//                 attIndex = 0;
//                 return -1; // Memory Error. Block size is larger than allocated memory
//            }
//            if(ch != '>')
//            {
//                parserState  = STATE_STORE_BLOCK;
//            }
//            else if(ch == '>')
//            {
//                char* check;
//                result [elementIndex] = '\0';
////                printf ("\n  :   %s   ;\n",result);
//                if(strstr( result ,GetEndTag(attParam[attIndex-1].block))!= NULL)
//                {
//                    check = &result[(strlen(result)-strlen(GetEndTag(attParam[attIndex-1].block)))];
////                    printf ("\n  :   %s   ;\n",check);
//                    if( strcmp(check,GetEndTag(attParam[attIndex-1].block)) == NULL)
//                    {
//                        *check ='\0';
//                        elementIndex =0;
//                        lastChar = 0;
//                        parserState  = STATE_START_BLOCK;
//                        storeContents = DATASTORGAE_STATUS_NONE;
//                        attIndex =0;
//                        return 1;
//                    }
//                }
//            }
//    }
//    return 0;
//}
/**
Tag can be "<tag " or "<tag>"
convert to "</tag>"
*/
char *EndTag (char* tag)
{
    char *strPtr = NULL;
    char *endPtr = NULL;
    strcpy(endBlock,"</");
    strPtr=strstr(tag,"<");
    strcat(endBlock,strPtr+1);
    endPtr=strstr(endBlock," ");
    if(endPtr)
        strcpy(endPtr,">");
    else
        strcat(endBlock,">");
//printf("%s",endBlock);
    return endBlock;
}

#define PARSER_BUFFER_LENGTH 500
static XmlState xmlState = PARSE_STATE_START;
static char *pBuff = NULL; // store the tag
static int buffIndex=0;
static int resultIndex = 0;
static int activeAtt= 0;
static int dataFound= 0; // Boolean
static int activateStore = 0; // Boolean

void InitParser(void)
{
    buffIndex=0;
    resultIndex = 0;
    activeAtt= 0;
    activateStore = 0;
    dataFound= 0; // Boolean
    xmlState = PARSE_STATE_START;
    pBuff = malloc(sizeof(char)*PARSER_BUFFER_LENGTH);
}

void EndParser(void)
{
    // Delete the memory allocated during InitParser()
    if(pBuff);
        free(pBuff);
}
bool IsAlphaNum(char ch)
{
    bool ret =false;
    if( ( ch>='0'&& ch <='9' ) ||
        (ch >= 'a' && ch <= 'z') ||
       (ch >= 'A' && ch <= 'Z')
       || ch == '<' )
       ret = true;
    return ret;
}
//PARSE_STATE_NONE = 0,
//PARSE_STATE_START,
//PARSE_STATE_READ,
//PARSE_STATE_ANALYSE,
//PARSE_STATE_STORE
// Block should start with "<" and end with space (" ") if it has attributes
// "<tag " or "<tag>"
// Attributes starts with "attributes="

//int ExtractXMLData(char ch,_searchParameters* searchParam,_searchProperty *searchProperty, char* result);
int ExtractXMLData(char ch,_searchParameters* searchParam,_searchProperty *searchProperty, char* result, U8 resLen)
{
    switch(xmlState)
    {
    case PARSE_STATE_START:
        buffIndex = 0;
        if(ch == '<')
        {
            if(buffIndex < PARSER_BUFFER_LENGTH)
                pBuff[buffIndex++] = ch;
            xmlState = PARSE_STATE_READ;
        }
        if(activateStore)
        {
            if(IsAlphaNum(ch)||( result[resultIndex-1] != ' ' && ch == ' '))
            {
                if(resultIndex < resLen)
                    result[resultIndex++]=ch;
                else
                    return -1;
            }
        }
        break;
    case PARSE_STATE_READ:
        if(buffIndex < PARSER_BUFFER_LENGTH)
            pBuff[buffIndex++] = ch;
        if(activateStore)
            if(resultIndex < resLen)
                result[resultIndex++]=ch;
            else
                return -1;
         if(ch == '>')
         {
             if(buffIndex < PARSER_BUFFER_LENGTH)
                pBuff[buffIndex]= '\0';
            // Analyse the string starting from "<" to ">"
            int i,attFound;
            char attAndKey[200];
            // search for a stop block
            for(i=0; i< activeAtt ; i ++)
            {
                attFound = 0;
                if(searchParam[i].tag != NULL)
                     attFound |= (strstr(pBuff,EndTag(searchParam[i].tag))? 1:0);
                if(attFound)
                {
                    xmlState = PARSE_STATE_STOP_ANALYSE;
                    activeAtt = i;
                    break;
                }
            }
            // Search for a start block with right attributes
            for (i=0; (i< (activeAtt+1) && i<(searchProperty->noOfSearchParam)) ; i ++)
            {
                attFound = 1;
                if(searchParam[i].tag != NULL)
                    attFound &= (strstr(pBuff,searchParam[i].tag)? 1:0);
                // Concatenate attribute and key and search in pBuff.
                if(searchParam[i].attribute != NULL && searchParam[i].key != NULL)
                {
                    strcpy(attAndKey, searchParam[i].attribute);
                    strcat(attAndKey, searchParam[i].key );
                     attFound &= (strstr(pBuff,attAndKey)? 1:0);
                }
                if((attFound == 1) &&
                   ((searchParam[i].tag != NULL) ||
                   ((searchParam[i].attribute!= NULL) &&
                   (searchParam[i].key != NULL))))
                {
                     xmlState = PARSE_STATE_START_ANALYSE;
                     activeAtt = i+1;
                     if(activeAtt == searchProperty->noOfSearchParam)
                     {
                        dataFound = 1;
                     }
                     break;
                }
            }
            if(xmlState == PARSE_STATE_READ)
                xmlState = PARSE_STATE_START;
         }
        break;
    case PARSE_STATE_START_ANALYSE:
        if(activeAtt == searchProperty->dataOfSearchParam)
        {
            resultIndex = 0;
            if((resultIndex + strlen(pBuff))< resLen)
                strcpy(result, pBuff);
            else
                return -1;
            resultIndex = strlen(result);
            activateStore = 1;
        }
        if(activateStore)
        {
            if(resultIndex< resLen)
                result[resultIndex++] = ch;
            else
                return -1;
        }
        xmlState = PARSE_STATE_START;
        break;
    case PARSE_STATE_STOP_ANALYSE:
         if(activeAtt+1 == searchProperty->dataOfSearchParam)
         {
             activateStore = 0;
             if(dataFound)
             {
                result[resultIndex] = '\0';
                return 1;
             }
         }
        xmlState = PARSE_STATE_START;
        break;
    }
    return 0;
}


//int ExtractXMLData(char ch,attributeParam* attParam,int attNo,int attResult, char* result)
//{
//    static XmlState xmlState = PARSE_STATE_START;
//    static char buff[500]; // store the tag
//    static int buffIndex=0;
//    static int resultIndex = 0;
//    static int activeAtt= 0;
//    static int dataFound= 0; // Boolean
//    static int activateStore = 0; // Boolean
//
//    switch(xmlState)
//    {
//    case PARSE_STATE_START:
//        buffIndex = 0;
//        if(ch == '<')
//        {
//            buff[buffIndex++] = ch;
//            xmlState = PARSE_STATE_READ;
//        }
//        break;
//    case PARSE_STATE_READ:
//        if(buffIndex < 500)
//            buff[buffIndex++] = ch;
////        printf("%c",ch);
//         if(ch == '>')
//         {
//
//             buff[buffIndex]= '\0';
////               printf("%s",buff);
//            // Analyse the string starting from "<" to ">"
//            int i,attFound;
//            char attAndKey[200];
//            // search for a stop block
//            for(i=0; i< activeAtt ; i ++)
//            {
//                attFound = 0;
//                if(attParam[i].block != NULL)
//                     attFound |= (strstr(buff,EndTag(attParam[i].block))? 1:0);
//                if(attFound)
//                {
//                    xmlState = PARSE_STATE_STOP_ANALYSE;
//                    activeAtt = i;
//                    printf("DELETED %s",buff);
//                }
//            }
//
//            // Search for a start block with right attributes
//            for (i=0; (i< (activeAtt+1) && i<(attNo)) ; i ++)
//            {
//                attFound = 1;
//                if(attParam[i].block != NULL)
//                    attFound &= (strstr(buff,attParam[i].block)? 1:0);
//                // Concatenate attribute and key and search in buff.
//                if(attParam[i].attribute != NULL && attParam[i].key != NULL)
//                {
//                    strcpy(attAndKey, attParam[i].attribute);
//                    strcat(attAndKey, attParam[i].key );
//                     attFound &= (strstr(buff,attAndKey)? 1:0);
//                }
//                if((attFound == 1) &&
//                   ((attParam[i].block != NULL) ||
//                   ((attParam[i].attribute!= NULL) &&
//                   (attParam[i].key != NULL))))
//                {
//                    xmlState = PARSE_STATE_START_ANALYSE;
//                     activeAtt = i+1;
//                     printf("FOUND: %s", buff);
//
//                }
////                printf("activeAtt %d",i );
//            }
//            if(xmlState == PARSE_STATE_READ)
//                xmlState = PARSE_STATE_START;
//         }
//        break;
//    case PARSE_STATE_START_ANALYSE:
//        if(activeAtt == attResult)
//        {
//            strcpy(result, buff);
//            resultIndex = strlen(result);
//            activateStore = 1;
//            result[resultIndex++] = ch;
//        }
//        xmlState = PARSE_STATE_START;
//        break;
//    case PARSE_STATE_STOP_ANALYSE:
//         if(activeAtt == attResult)
//            activateStore = 0;
//        xmlState = PARSE_STATE_START;
//        break;
//    case PARSE_STATE_STORE:
//        xmlState = PARSE_STATE_START;
//        break;
//    }
//    return 0;
//}

//int ReadBlock(char ch,char* block,char* result)
//{
//    static XmlParserState parserState = STATE_START_BLOCK;
//    static elementIndex;
//    static bool elementStored;
//    char *posOfEndTag;
//    static char lastChar;
//    static DataStorageState storeContents = DATASTORGAE_STATUS_NONE;
//
//    switch (parserState)
//    {
//
//        case STATE_START_BLOCK :
//            if(ch == '<')
//                parserState  = STATE_SEARCH_ELEMENT;
//            else
//                parserState  = STATE_START_BLOCK;
//
//            elementIndex=0;
//            elementStored= false;
//            break;
//
//        case STATE_SEARCH_ELEMENT :
//
//            if(ch != ' ' && ch!= '>' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_ELEMENT;
//                    result[elementIndex++] = ch;
//                }
//
//            }
//            else
//            {
//                elementStored=true;
//            }
//            if(ch == '>' && elementStored==true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                if(strcmp(result,block) == NULL)
//                    parserState = STATE_STORE_BLOCK;
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
////
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("block: %s\n",block);
////                printf("Result of strcmp: %d\n",strcmp(result,block));
//            }
//            break;
//
//        case STATE_STORE_BLOCK :
//            if(elementIndex < MAX_SEARCH_ELEMENT )
//            {
//                // STOP when "<!" found (avoid storing comment tags)
//                if(lastChar == '<' && ch == '!')
//                {
//                  storeContents = DATASTORGAE_STATUS_STOP;
//                  elementIndex --;
//                }
//                // TAGEND when "</" found (avoid storing space after end tag)
//                else if(lastChar == '<' && ch == '/')
//                  storeContents = DATASTORGAE_STATUS_TAGENDED;
//
//
//                else if(lastChar == '>' && storeContents == DATASTORGAE_STATUS_TAGENDED)
//                    storeContents = DATASTORGAE_STATUS_STOP;
//
//                // TAGEND when "<" found after "<!--><"
//                // or "</....><" (avoid storing space before start tag.)
//                if(ch == '<' && storeContents == DATASTORGAE_STATUS_STOP)
//                   storeContents = DATASTORGAE_STATUS_NONE;
//
//                if((storeContents !=DATASTORGAE_STATUS_STOP))
////                        && ch >= 32 && ch <= 126)
//                    result[elementIndex++] = ch;
//
//                lastChar = ch;
//            }
//            else
//            {
//                 parserState  = STATE_START_BLOCK;
//                 result [elementIndex-1]='\0';
//                 return -1; // Memory Error. Block size is larger than allocated memory
//            }
//            if(ch != '>')
//            {
//                parserState  = STATE_STORE_BLOCK;
//            }
//            else
//            {
////                result [elementIndex] = '\0';
////                if( (posOfEndTag=strstr( result ,GetEndTag(block)))!= NULL )
////                {
////                    *posOfEndTag ='\0';
////                    elementIndex =0;
////                    lastChar = 0;
////                    parserState  = STATE_START_BLOCK;
////                    storeContents = DATASTORGAE_STATUS_NONE;
////                    return 1;
////                }
//
//
//                char* check;
//                result [elementIndex] = '\0';
////                printf ("\n  :   %s   ;\n",result);
//                if( (posOfEndTag=strstr( result ,GetEndTag(block)))!= NULL )
//                {
//                    check = &result[(strlen(result)-strlen(GetEndTag(block)))];
////                    printf ("\n  :   %s   ;\n",check);
//                    if( strcmp(check,GetEndTag(block)) == NULL)
//                    {
//                        *check ='\0';
//                        elementIndex =0;
//                        lastChar = 0;
//                        parserState  = STATE_START_BLOCK;
//                        storeContents = DATASTORGAE_STATUS_NONE;
//                        return 1;
//                    }
//                }
//            }
//            break;
//    }
//    return 0;
//}


//S8 ParseXMLData(char ch,XmlParserStruct& parserStruct, char* result)
//{
//    static XmlParserState parserState = STATE_START_BLOCK;
//    static elementIndex;
//    static bool elementStored;
//    char *posOfEndTag;
//    static char lastChar;
//    static DataStorageState storeContents = DATASTORGAE_STATUS_NONE;
//    char* block
//    if(parserStruct.keyType == true)
//    {
//        // Search for attributes.
//        block = parserStruct.xmlTag;
//    }
//    else
//    {
//        // Search for element.
//        block = parserStruct.keyWord;
//    }
////    printf("%c",ch);
//    switch (parserState)
//    {
//        case STATE_START_BLOCK :
//            if(ch == '<')
//                parserState  = STATE_SEARCH_ELEMENT;
//            else
//                parserState  = STATE_START_BLOCK;
//
//            elementIndex=0;
//            elementStored= false;
//            break;
//
//         case STATE_SEARCH_ELEMENT :
//
//            if(ch != ' ' && ch!= '>' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_ELEMENT;
//                    result[elementIndex++] = ch;
//                }
//
//            }
//            else
//            {
//                elementStored=true;
//            }
//            if((ch == ' ' || ch == '>')&& elementStored==true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                if(strcmp(result,block) == NULL)
//                {
//                    parserState = STATE_SEARCH_ATTRIBUTES;
//                    elementStored =false;
//                }
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("block: %s\n",block);
////                printf("Result of strcmp: %d\n",strcmp(result,block));
//            }
//            break;
//        case STATE_SEARCH_ATTRIBUTES :
//            if(ch != '=' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_ATTRIBUTES;
//                    result[elementIndex++] = ch;
//                }
//
//            }
//            else
//            {
//                elementStored=true;
//            }
//            if(ch == '=' && elementStored==true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                if(strcmp(result,parserStruct.attribute) == NULL)
//                {
//                    parserState = STATE_SEARCH_KEY;
//                    elementStored = false;
//                }
//
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("attribute: %s\n",attribute);
////                printf("Result of strcmp: %d\n",strcmp(result,attribute));
//            }
//            break;
//        case STATE_SEARCH_KEY :
//
//            if( ch!= '>' && elementStored == false )
//            {
//                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
//                {
//                    parserState  = STATE_SEARCH_KEY;
//                    result[elementIndex++] = ch;
//                }
//            }
//            else
//            {
//                elementStored = true;
//            }
//            if(( ch == '>') && elementStored == true)
//            { //check ! strcmp is not working.
//                result[elementIndex] ='\0';
//                if(strcmp(result,key) == NULL)
//                    parserState = STATE_STORE_BLOCK;
//                else
//                    parserState = STATE_START_BLOCK;
//                elementIndex = 0;
//                elementStored = false;
//
////                printf("Strlen of result: %d\n",strlen(result));
////                printf("result: %s\n", result);
////                printf("key: %s\n",key);
////                printf("Result of strcmp: %d\n",strcmp(result,key));
//            }
//            break;
//        case STATE_STORE_BLOCK :
//            if(elementIndex < MAX_SEARCH_ELEMENT )
//            {
//                // STOP when "<!" found (avoid storing comment tags)
//                if(lastChar == '<' && ch == '!')
//                {
//                  storeContents = DATASTORGAE_STATUS_STOP;
//                  elementIndex --;
//                }
//                // TAGEND when "</" found (avoid storing space after end tag)
//                else if(lastChar == '<' && ch == '/')
//                  storeContents = DATASTORGAE_STATUS_TAGENDED;
//                // TAGEND when "</ .... >" found (avoid storing space after end tag)
//                else if(lastChar == '>' && storeContents == DATASTORGAE_STATUS_TAGENDED)
//                    storeContents = DATASTORGAE_STATUS_STOP;
//                // TAGEND when "<" found after "<!--><"
//                // or "</....><" (avoid storing space before start tag.)
//                if(ch == '<' && storeContents == DATASTORGAE_STATUS_STOP)
//                   storeContents = DATASTORGAE_STATUS_NONE;
//
//                if((storeContents !=DATASTORGAE_STATUS_STOP))
////                        && ch >= 32 && ch <= 126)
//                    result[elementIndex++] = ch;
//
//                lastChar = ch;
//            }
//            else
//            {
//                 parserState  = STATE_START_BLOCK;
//                 result [elementIndex-1]='\0';
//                 return -1; // Memory Error. Block size is larger than allocated memory
//            }
//            if(ch != '>')
//            {
//                parserState  = STATE_STORE_BLOCK;
//            }
//            else if(ch == '>')
//            {
//                char* check;
//                result [elementIndex] = '\0';
////                printf ("\n  :   %s   ;\n",result);
//                if(strstr( result ,GetEndTag(block))!= NULL)
//                {
//                    check = &result[(strlen(result)-strlen(GetEndTag(block)))];
////                    printf ("\n  :   %s   ;\n",check);
//                    if( strcmp(check,GetEndTag(block)) == NULL)
//                    {
//                        *check ='\0';
//                        elementIndex =0;
//                        lastChar = 0;
//                        parserState  = STATE_START_BLOCK;
//                        storeContents = DATASTORGAE_STATUS_NONE;
//                        return 1;
//                    }
//                }
//            }
//    }
//    return 0;
//}
