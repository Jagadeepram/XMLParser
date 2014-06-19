//#include "XML.h"
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
int ReadBlockWithAttribute(char ch,attributeParam* attParam,int attNo,char* result)
{
    static XmlParserState parserState = STATE_START_BLOCK;
    static elementIndex;
    static bool elementStored;
    char *posOfEndTag;
    static attIndex=0;
    static char lastChar = 0;
    static DataStorageState storeContents = DATASTORGAE_STATUS_NONE;

    switch (parserState)
    {
        case STATE_START_BLOCK :
            if(ch == '<')
                parserState  = STATE_SEARCH_ELEMENT;
            else
                parserState  = STATE_START_BLOCK;
            if(ch == '?')
                attIndex =0;
            elementIndex=0;
            elementStored= false;
            break;

         case STATE_SEARCH_ELEMENT :

            if(ch != ' ' && ch!= '>' && elementStored == false )
            {
                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
                {
                    parserState  = STATE_SEARCH_ELEMENT;
                    result[elementIndex++] = ch;
                }
            }
            else
            {
                elementStored=true;
            }
            if((ch == ' ' || ch == '>')&& elementStored==true)
            { //check ! strcmp is not working.
                result[elementIndex] ='\0';
//                 printf("block 1: %s\n",attParam[attIndex].block);
////                 printf("block 2: %s\n",attParam[attIndex+1].block);
//                 printf("attribute Index: %d\n",attIndex);
                if(strcmp(result,attParam[attIndex].block) == NULL)
                {
                    parserState = STATE_SEARCH_ATTRIBUTES;
                    elementStored =false;
                }
                else
                    parserState = STATE_START_BLOCK;
                elementIndex = 0;

//                printf("Strlen of result: %d\n",strlen(result));
//                printf("result: %s\n", result);
//                printf("block: %s\n",block);
//                printf("Result of strcmp: %d\n",strcmp(result,block));
            }
            break;
        case STATE_SEARCH_ATTRIBUTES :
            if(ch != '=' && elementStored == false )
            {
                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
                {
                    parserState  = STATE_SEARCH_ATTRIBUTES;
                    result[elementIndex++] = ch;
                }
            }
            else
            {
                elementStored=true;
            }
            if(ch == '=' && elementStored==true)
            { //check ! strcmp is not working.
                result[elementIndex] ='\0';
                if(strcmp(result,attParam[attIndex].attribute) == NULL)
                {
                    parserState = STATE_SEARCH_KEY;
                    elementStored = false;
                }
                else
                    parserState = STATE_START_BLOCK;
                elementIndex = 0;

//                printf("Strlen of result: %d\n",strlen(result));
//                printf("result: %s\n", result);
//                printf("attribute: %s\n",attribute);
//                printf("Result of strcmp: %d\n",strcmp(result,attribute));
            }
            break;
        case STATE_SEARCH_KEY :

            if( ch!= '>' && elementStored == false )
            {
                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
                {
                    parserState  = STATE_SEARCH_KEY;
                    result[elementIndex++] = ch;
                }
            }
            else
            {
                elementStored = true;
            }
            if(( ch == '>') && elementStored == true)
            { //check ! strcmp is not working.
                result[elementIndex] ='\0';
                elementIndex = 0;
                elementStored = false;
//
//                printf("Strlen of result: %d\n",strlen(result));
//                printf("result: %s\n",result);
//                printf("key: %s\n",attParam[attIndex].key);
//                printf("Result of strstr: %d\n",strstr(result,attParam[attIndex].key));
                if(strstr(result,attParam[attIndex].key) != NULL)
                {
                    attIndex++;
                    if(attIndex < attNo)
                        parserState = STATE_START_BLOCK;
                    else
                        parserState = STATE_STORE_BLOCK;
                }
                else
                    parserState = STATE_START_BLOCK;
            }
            break;
        case STATE_STORE_BLOCK :
            if(elementIndex < MAX_SEARCH_ELEMENT )
            {
                // STOP when "<!" found (avoid storing comment tags)
                if(lastChar == '<' && ch == '!')
                {
                  storeContents = DATASTORGAE_STATUS_STOP;
                  elementIndex --;
                }
                // TAGEND when "</" found (avoid storing space after end tag)
                else if(lastChar == '<' && ch == '/')
                   storeContents = DATASTORGAE_STATUS_TAGENDED;
                // TAGEND when "</ .... >" found (avoid storing space after end tag)
                else if(lastChar == '>' && storeContents == DATASTORGAE_STATUS_TAGENDED)
                    storeContents = DATASTORGAE_STATUS_STOP;
                // TAGEND when "<" found after "<!--><"
                // or "</....><" (avoid storing space before start tag.)
                if(ch == '<' && storeContents == DATASTORGAE_STATUS_STOP)
                    storeContents = DATASTORGAE_STATUS_NONE;

                if((storeContents !=DATASTORGAE_STATUS_STOP))
                    result[elementIndex++] = ch;
                lastChar = ch;
            }
            else
            {
                 parserState  = STATE_START_BLOCK;
                 result [elementIndex-1]='\0';
                 attIndex = 0;
                 return -1; // Memory Error. Block size is larger than allocated memory
            }
            if(ch != '>')
            {
                parserState  = STATE_STORE_BLOCK;
            }
            else if(ch == '>')
            {
                char* check;
                result [elementIndex] = '\0';
//                printf ("\n  :   %s   ;\n",result);
                if(strstr( result ,GetEndTag(attParam[attIndex-1].block))!= NULL)
                {
                    check = &result[(strlen(result)-strlen(GetEndTag(attParam[attIndex-1].block)))];
//                    printf ("\n  :   %s   ;\n",check);
                    if( strcmp(check,GetEndTag(attParam[attIndex-1].block)) == NULL)
                    {
                        *check ='\0';
                        elementIndex =0;
                        lastChar = 0;
                        parserState  = STATE_START_BLOCK;
                        storeContents = DATASTORGAE_STATUS_NONE;
                        attIndex =0;
                        return 1;
                    }
                }
            }
    }
    return 0;
}

int ReadBlock(char ch,char* block,char* result)
{
    static XmlParserState parserState = STATE_START_BLOCK;
    static elementIndex;
    static bool elementStored;
    char *posOfEndTag;
    static char lastChar;
    static DataStorageState storeContents = DATASTORGAE_STATUS_NONE;

    switch (parserState)
    {

        case STATE_START_BLOCK :
            if(ch == '<')
                parserState  = STATE_SEARCH_ELEMENT;
            else
                parserState  = STATE_START_BLOCK;

            elementIndex=0;
            elementStored= false;
            break;

        case STATE_SEARCH_ELEMENT :

            if(ch != ' ' && ch!= '>' && elementStored == false )
            {
                if(elementIndex < MAX_STORE_ELEMENT_SIZE )
                {
                    parserState  = STATE_SEARCH_ELEMENT;
                    result[elementIndex++] = ch;
                }

            }
            else
            {
                elementStored=true;
            }
            if(ch == '>' && elementStored==true)
            { //check ! strcmp is not working.
                result[elementIndex] ='\0';
                if(strcmp(result,block) == NULL)
                    parserState = STATE_STORE_BLOCK;
                else
                    parserState = STATE_START_BLOCK;
                elementIndex = 0;
//
//                printf("Strlen of result: %d\n",strlen(result));
//                printf("result: %s\n", result);
//                printf("block: %s\n",block);
//                printf("Result of strcmp: %d\n",strcmp(result,block));
            }
            break;

        case STATE_STORE_BLOCK :
            if(elementIndex < MAX_SEARCH_ELEMENT )
            {
                // STOP when "<!" found (avoid storing comment tags)
                if(lastChar == '<' && ch == '!')
                {
                  storeContents = DATASTORGAE_STATUS_STOP;
                  elementIndex --;
                }
                // TAGEND when "</" found (avoid storing space after end tag)
                else if(lastChar == '<' && ch == '/')
                  storeContents = DATASTORGAE_STATUS_TAGENDED;


                else if(lastChar == '>' && storeContents == DATASTORGAE_STATUS_TAGENDED)
                    storeContents = DATASTORGAE_STATUS_STOP;

                // TAGEND when "<" found after "<!--><"
                // or "</....><" (avoid storing space before start tag.)
                if(ch == '<' && storeContents == DATASTORGAE_STATUS_STOP)
                   storeContents = DATASTORGAE_STATUS_NONE;

                if((storeContents !=DATASTORGAE_STATUS_STOP))
//                        && ch >= 32 && ch <= 126)
                    result[elementIndex++] = ch;

                lastChar = ch;
            }
            else
            {
                 parserState  = STATE_START_BLOCK;
                 result [elementIndex-1]='\0';
                 return -1; // Memory Error. Block size is larger than allocated memory
            }
            if(ch != '>')
            {
                parserState  = STATE_STORE_BLOCK;
            }
            else
            {
//                result [elementIndex] = '\0';
//                if( (posOfEndTag=strstr( result ,GetEndTag(block)))!= NULL )
//                {
//                    *posOfEndTag ='\0';
//                    elementIndex =0;
//                    lastChar = 0;
//                    parserState  = STATE_START_BLOCK;
//                    storeContents = DATASTORGAE_STATUS_NONE;
//                    return 1;
//                }


                char* check;
                result [elementIndex] = '\0';
//                printf ("\n  :   %s   ;\n",result);
                if( (posOfEndTag=strstr( result ,GetEndTag(block)))!= NULL )
                {
                    check = &result[(strlen(result)-strlen(GetEndTag(block)))];
//                    printf ("\n  :   %s   ;\n",check);
                    if( strcmp(check,GetEndTag(block)) == NULL)
                    {
                        *check ='\0';
                        elementIndex =0;
                        lastChar = 0;
                        parserState  = STATE_START_BLOCK;
                        storeContents = DATASTORGAE_STATUS_NONE;
                        return 1;
                    }
                }
            }
            break;
    }
    return 0;
}

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
