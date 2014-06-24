#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadXMLFile.h"
#include "XML.h"
int main()
{
    char *result = malloc(MAX_SEARCH_ELEMENT);
    if(result == NULL)
    {
         printf("Error: memory allocation failed\n");
         return 0;
    }

        char *result2 = malloc(MAX_SEARCH_ELEMENT);
    if(result2 == NULL)
    {
         printf("Error: memory allocation failed\n");
         return 0;
    }

// Test for CobiaProbes.xml
//<Probe Type="Magna3cc (PBCA)"> <DisplayCaption>Chamber Adapter</DisplayCaption> </Probe>
_searchParameters searchParam[3];
_searchProperty searchProperty;

searchParam[0].tag ="<Det ";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"PiranhaMAS-2\"";

searchParam[1].tag ="<MQ ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"O1\"";

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

searchProperty.noOfSearchParam=3;
// Data search parameter should not point to the tag
// which is NULL
searchProperty.dataOfSearchParam=3;

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDS_2.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

//printf( "\nStatus %d", XmlReadBlock("<MAM","MQInt.xml", result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n-----------------------------------------------------------");



    free(result);
    return 0;
}

