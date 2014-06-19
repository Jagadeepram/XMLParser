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

printf( "\nStatus %d",  XmlReadBlockWithAttributes("<MQ ","Type=","\"O1\"","IDS_2.xml",result));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

printf( "\nStatus %d", XmlReadBlock("<MAM","MQInt.xml", result));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");



    free(result);
    return 0;
}

