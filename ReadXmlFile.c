//
//
//
//
//static char *element = NULL;
//static char *att = NULL;
//static char *endatt = NULL;
//static char *storeElement = NULL;
//static char *endstr = NULL ;
//static int elementIndex=0;
//static char *searchElement = NULL ;
//static char *sFileName = NULL ;
//
//#define STORE_ELEMENT_SIZE 200 // This must be increased when XML element size is increased.
//
//U8 ReadMqXml(const char* sName_in, char* sName_out)
//{
//
//   U8 i=0;
//   while (!xSemaphoreTake(xshSdDisplaySPIBusUsage, portMAX_DELAY));
//   MountSdCard();
//   vTaskSuspendAll();
//   malloc_trim(0);
//   xTaskResumeAll();
//
//   element = (char*)pvPortMalloc(sizeof(char)*20);
//   att = (char*)pvPortMalloc(sizeof(char)*20);
//   endatt = (char*)pvPortMalloc(sizeof(char)*20);
//   storeElement = (char*)pvPortMalloc(sizeof(char)* STORE_ELEMENT_SIZE);
//   endstr = (char*)pvPortMalloc(sizeof(char)*60);
//   searchElement = (char*)pvPortMalloc(sizeof(char)*60);
//   sFileName= (char*)pvPortMalloc(sizeof(char)*60);
//
//   if( element == NULL  ||
//		   att  == NULL   ||
//	   endatt == NULL  ||
//	   storeElement == NULL   ||
//	   endstr == NULL  ||
//	   searchElement == NULL  ||
//	   sFileName == NULL )
//   {
//
//	   return 1;
//   }
//
//   strcpy(element, "MQ");
//   strcpy(endatt, "/MQ>");
//   strcpy(searchElement,  "<SelectCaption>");
//   strcpy(endstr, "</SelectCaption>");
//   strcpy(sFileName, "./res/idg/MQExt.xml");
//
//	if (!nav_setcwd((FS_STRING)sFileName, TRUE, FALSE))
//	{
//		Adbg_STR(" ResourceContainer: Could not find IDG file %s", sFileName);
//		return 0;
//	}
//	sName_out[0]= '\0';
//	storeElement[0] = '\0';
//
//	elementIndex=0;
//	file_open(FOPEN_MODE_R);
//
//	strcpy(att,sName_in);
//	parserState=STATE_START_BLOCK;
//	do{
//		ch = file_getc();
//		i= FindBlock();
//	} while (!file_eof()  && i== 0);
//
//	GetElement(storeElement , searchElement, sName_out, MAX_SIZE_OF_STRING);
//
//	file_close();
//    // SD/Display bus free to use
//    xSemaphoreGive(xshSdDisplaySPIBusUsage);
//
//    if(element != NULL)
//		vPortFree(element);
//    if(att != NULL)
//		vPortFree(att);
//    if(endatt != NULL)
//		vPortFree(endatt);
//    if(storeElement != NULL)
//		vPortFree(storeElement);
//    if(endstr != NULL)
//		vPortFree(endstr);
//    if(searchElement != NULL)
//		vPortFree(searchElement);
//    if(sFileName != NULL)
//		vPortFree(sFileName);
//
//    element = NULL;
//    att = NULL;
//    endatt = NULL;
//    storeElement = NULL;
//    endstr = NULL ;
//    elementIndex = 0;
//    searchElement = NULL ;
//    sFileName = NULL ;
//	vTaskSuspendAll(); // Be sure no task switch
//	malloc_trim(0);
//	xTaskResumeAll();  // Enable task switch again
//    return 1;
//}

#include <stdio.h>
#include "ReadXmlFile.h"
#include "XML.h"

int XmlReadBlockWithAttributes(char* fileName,attributeParam* attParam,int attNo,int attResult,char *result)
{
    FILE *fp;
    char ch;
    int status;
//    typedef struct
//{
//    int noOfAttributes; // No of attributes to search.
//    int dataOfAttribute; // Index of the attribute who's data is fetched.
//    XMLResultType resultType; // Type of data (only tag, body and both)
//}attributeProperty;

    attributeProperty attProperty;
    attProperty.dataOfAttribute = 2; // Pull data from second search element.
    attProperty.noOfAttributes = 3; // Totally three search elements are used.
    attProperty.resultType =XMLDATA_TAG_BODY; // Get tag and body.
//    attributeParam attParam[3];
//
//    attParam[0].block = "<Det ";
//    attParam[0].attribute = "Type=";
//    attParam[0].key = "\"MAS-3B\"";
//
//    attParam[1].block = block;
//    attParam[1].attribute = attribute;
//    attParam[1].key = key;
//
//    attParam[2].block = ;
//    attParam[2].attribute = "Unit=";
//    attParam[2].key = ;

    // Open the file.
    if( (fp=(FILE *)fopen(fileName,"r")) == NULL)
        printf("File not found!\n");
    InitParser();
    do {
        ch = getc(fp);
       // status=ReadBlockWithAttribute(ch,attParam,3,result);
       status = ExtractXMLData(ch,attParam,attNo,attResult,result);
    } while(ch!=EOF && status == 0);

//    printf("\nBlock: %s\n",block);
//    printf("attribute: %s\n",attribute);
//    printf("key: %s\n",key);
//    printf("result: %s\n",result);
    fclose(fp);

    return status;
}


int XmlReadBlockWithAttribute(char* block, char* attribute, char* key,char* fileName, char *result)
{
    FILE *fp;
    char ch;
    int status;
    attributeParam attParam[1];

    attParam[0].attribute = attribute;
    attParam[0].block = block;//"MQ";//
    attParam[0].key = key;
//    attParam[1].attribute = attribute;
//    attParam[1].block = block;
//    attParam[1].key = key;

    // Open the file.
    if( (fp=(FILE *)fopen(fileName,"r")) == NULL)
        printf("File not found!\n");

    do {
        ch = getc(fp);
        status=ReadBlockWithAttribute(ch,attParam,1,result);
    } while(ch!=EOF && status == 0);

//    printf("\nBlock: %s\n",block);
//    printf("attribute: %s\n",attribute);
//    printf("key: %s\n",key);
//    printf("result: %s\n",result);
    fclose(fp);

    return status;
}
int XmlReadBlockWithAttribute_array(char* block, char* attribute, char* key,char* fileName, char *result)
{
    char ch;
    int status = 0;
    int i=0;
    // Open the file.
    if(fileName == NULL)
        return;
     attributeParam attParam[1];

    attParam[0].attribute = attribute;
    attParam[0].block = block;//"MQ";//
    attParam[0].key = key;

//printf("%s",fileName);
//printf(" Strlen of %d", strlen(fileName));
//fileName[strlen(fileName)] = '\0';
    do {
        ch = fileName[i++];
        status=ReadBlockWithAttribute(ch,attParam,1,result);
    } while(ch!='\0' && status == 0);

//    printf("\nBlock: %s\n",block);
//    printf("attribute: %s\n",attribute);
//    printf("key: %s\n",key);
//    printf("result: %s\n",result);


    return status;
}

int XmlReadBlock(char* block,char* fileName, char *result)
{
    FILE *fp;
    char ch;
    int status;
    result[0]='\0';

    attributeParam attParam[1];
    attParam[0].attribute = NULL;
    attParam[0].block = block;//"MQ";//
    attParam[0].key = NULL;
    InitParser();
    // Open the file.
    if( (fp=(FILE *)fopen(fileName,"r")) == NULL)
        printf("File not found!\n");

    do {
        ch = getc(fp);
       status = ExtractXMLData(ch,attParam,1,1,result);
//        status = ReadBlock(ch,block, result);
    } while(ch!=EOF && (status == 0));

    fclose(fp);
    return status;
}
