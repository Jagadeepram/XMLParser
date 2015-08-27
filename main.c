#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadXMLFile.h"
#include "XML.h"
/// Test for Git update
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

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=3;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDS_2.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<Crc";
searchParam[0].attribute =NULL;
searchParam[0].key =NULL;

//searchParam[1].tag ="<MQ ";
//searchParam[1].attribute = "Type=";
//searchParam[1].key = "\"O1\"";
//
//searchParam[2].tag = NULL;
//searchParam[2].attribute = "Unit=";
//searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"CRCSysInfo.XML",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<Det ";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"PiranhaMAS-2\"";

searchParam[1].tag ="<MQ ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"O1\"";

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=3;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDS_2.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<Det ";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"PiranhaMAS-2\"";

searchParam[1].tag ="<MQ ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"O1\"";

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=3;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_BODY; // Extract tag only.
printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDS_2.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");


searchParam[0].tag ="<Probe ";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"Magna3cc (PBCA)\"";

searchParam[1].tag ="<DisplayCaption";
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=2;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"CobiaProbes.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<Probe";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"IonCh. 0.2-3cc (PBCA)\"";

searchParam[1].tag ="<DisplayCaption";
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=2;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"CobiaProbes.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<MenuMain";
searchParam[0].attribute = NULL;
searchParam[0].key = NULL;

searchParam[1].tag = NULL;
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"cobiatexts.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<DecimalSeparator";
searchParam[0].attribute = NULL;
searchParam[0].key = NULL;

searchParam[1].tag = NULL;
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"cobiatexts.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");


searchParam[0].tag ="<Det";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"DCT10 (PBCA)\"";

searchParam[1].tag ="<MQ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"R3\"";

searchParam[2].tag = NULL;//"<ChCu";
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"Gy\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=3;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"DCT_INC.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");


searchParam[0].tag ="<IDG+";
searchParam[0].attribute =NULL;
searchParam[0].key ="\"DCT10 (PBCA)\"";

searchParam[1].tag ="<MQ";
searchParam[1].attribute = NULL;
searchParam[1].key = "\"R3\"";

searchParam[2].tag = NULL;//"<ChCu";
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"Gy\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDG2.txt",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<Unit-R%s";
searchParam[0].attribute = NULL;
searchParam[0].key = NULL;

searchParam[1].tag = NULL;
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDG2.txt",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");
searchParam[0].tag ="<Unit-Gy%s";
searchParam[0].attribute = NULL;
searchParam[0].key = NULL;

searchParam[1].tag = NULL;
searchParam[1].attribute = NULL;
searchParam[1].key = NULL;

searchParam[2].tag = NULL;
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"A\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"IDG2.txt",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");


searchParam[0].tag ="<Det";
searchParam[0].attribute ="Type=";
searchParam[0].key ="\"PiranhaDose\"";

searchParam[1].tag ="<MQ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"M3\"";

searchParam[2].tag = NULL;//"<ChCu";
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"Gy\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=3;
searchProperty.dataOfSearchParam=2;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"mam1.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<MAM";
searchParam[0].attribute =NULL;
searchParam[0].key =NULL;

searchParam[1].tag ="<MQ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"M3\"";

searchParam[2].tag = NULL;//"<ChCu";
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"Gy\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"MQInt.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");

searchParam[0].tag ="<MAM";
searchParam[0].attribute =NULL;
searchParam[0].key =NULL;

searchParam[1].tag ="<MQ";
searchParam[1].attribute = "Type=";
searchParam[1].key = "\"M3\"";

searchParam[2].tag = NULL;//"<ChCu";
searchParam[2].attribute = "Unit=";
searchParam[2].key ="\"Gy\"";

// Data search parameter should not point to the tag which is NULL
searchProperty.noOfSearchParam=1;
searchProperty.dataOfSearchParam=1;
searchProperty.resultType = XMLDATA_TAG_BODY; // Extract tag only.

printf("\nStatus %d",  XmlReadBlockWithAttributes((char*)"MQInt.xml",searchParam,&searchProperty,result,MAX_SEARCH_ELEMENT));
printf("\nResult length %d\n",strlen(result));
printf("Result:\n%s",result);
printf("\n-----------------------------------------------------------");


free(result);
return 0;
}
