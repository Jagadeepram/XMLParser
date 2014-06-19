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
//printf( "\nStatus %d",  XmlReadBlockWithAttributes("Det","Type","\"PiranhaDose\"","IDS.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);

//printf( "\nStatus %d",  XmlReadBlockWithAttributes("MQ","Type","\"C2\"","IDS.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n-----------------------------------------------------------");
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("MQ","Type","\"M11\"","IDS.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n----------------------------------------------------------");
//printf( "\nStatus %d",  XmlReadBlockWithAttributes("MQ","Type","\"R1\"","IDS.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n----------------------------------------------------------");


printf( "\nStatus %d",  XmlReadBlockWithAttributes("MQ","Type","\"O2\"","IDS_2.xml",result));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("MQ","Type","\"M11\"","IDS_2.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n----------------------------------------------------------");
//printf( "\nStatus %d",  XmlReadBlockWithAttributes("MQ","Type","\"O1\"","IDS_2.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//printf("\n----------------------------------------------------------");



//
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("MQ","Type","\"M1\"","MQInt.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);

//printf( "\nStatus %d", XmlReadBlock("RF","MQInt.xml", result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);
//
//printf( "\nStatus %d", XmlReadBlock("RF","MQInt.xml", result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);

//printf( "\nStatus %d",  XmlReadBlockWithAttribute_array("MQ","Type","\"R1\"",result,result2));
//printf("\nResult length %d\n",strlen(result2));
//printf("Result:\n%s",result2);

//printf( "\nStatus %d",  XmlReadBlockWithAttribute("Probe","Type","\"PiranhaT20\"","CobiaProbes.xml",result));
//
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("Probe","Type","\"DCT10 (PBCA)\"","CobiaProbes.xml",result));

//printf( "\nStatus %d",  XmlReadBlockWithAttribute("MQ","Type","\"C3\"","MQExt.xml",result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);

//printf( "\nStatus %d",  XmlReadBlockWithAttribute("Probe","Type","\"IonCh. 15-300cc (PBCA)\"","CobiaProbes.xml",result));
//
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("Probe","Type","\"PiranhaMAS-2\"","CobiaProbes.xml",result));
//
//printf( "\nStatus %d",  XmlReadBlockWithAttribute("Probe","Type","\"PiranhaLight\"","CobiaProbes.xml",result));
//





//    printf( "\nStatus %d", XmlReadBlock("DisplayMenuText","cobiatexts.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);
//
//    printf( "\nStatus %d", XmlReadBlock("Version","cobiatexts.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);
//
//    printf( "\nStatus %d", XmlReadBlock("MenuPreviousDel","cobiatexts.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);
////
//    printf( "\nStatus %d", XmlReadBlock("VersionProd","cobiatexts.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);
//
//    printf( "\nStatus %d", XmlReadBlock("PiranhaDose","CobiaProbes.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);
//
//    printf( "\nStatus %d", XmlReadBlock("PiranhaT20","CobiaProbes.xml", result));
//    printf("\nResult length %d\n",strlen(result));
//    printf("Result:\n%s",result);

//printf( "\nStatus %d", XmlReadBlock("Unit-R%s","IDG2.txt", result));
//printf("\nResult length %d\n",strlen(result));
//printf("Result:\n%s",result);


    free(result);
    return 0;
}

