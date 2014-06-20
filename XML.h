#define MAX_STORE_ELEMENT_SIZE 50
#define MAX_SEARCH_ELEMENT 5000

#define true 1
#define false 0

typedef int bool;
typedef unsigned int U8;
typedef int S8;

/**
    xmlTag : String at the start of tag.
    attribute
    key word : Result to be searched.
    noOfKeyWord :
*/
//struct XmlParserStruct
//{
//    char* xmlTag;
//    char* attribute;
//    char* keyWord;
//    U8 noOfKeyWord;
//    bool keyType;
//    bool resultType;
//    U8 resultItemNumber;
//};
typedef enum {
	STATE_START_BLOCK =0, // Search for '<'
	STATE_SEARCH_ELEMENT, // compare to block element
	STATE_SEARCH_ATTRIBUTES,   // compare for "TYPE" untill '>' is found.
	STATE_SEARCH_KEY, // Search for key untill'>' is found.
	STATE_STORE_BLOCK // Wait for < and then start storing
} XmlParserState;

typedef enum {
    DATASTORGAE_STATUS_NONE=0,
    DATASTORGAE_STATUS_START,
    DATASTORGAE_STATUS_STOP,
//    DATASTORGAE_STATUS_TAGsTARTED,
    DATASTORGAE_STATUS_TAGENDED
} DataStorageState;
//


//void GetElement(char *element , char *search, char *result, U16 maxLen);
char* GetEndTag(char* block);
int ReadBlockWithAttribute(char ch,attributeParam* attParam,int attNo,char* result);
int ReadBlock(char ch,char* block,char* result);
//U8 ParseXMLData(char*ch, XmlParserStruct& parserStruct, char* result);
//void ReadProbeXMLData();


typedef enum
{
    PARSE_STATE_START=0,
    PARSE_STATE_READ,
    PARSE_STATE_START_ANALYSE,
    PARSE_STATE_STOP_ANALYSE,
    PARSE_STATE_STORE
}XmlState ;
typedef enum
{
    XMLDATA_TAG =0,
    XMLDATA_BODY,
    XMLDATA_TAG_BODY
}XMLResultType;

typedef struct
{
    char *tag; // block
    char *attribute;
    char *key;
} _searchParameters;

typedef struct
{
    int noOfSearchParam; // No of attributes to search.
    int dataOfSearchParam; // Index of the attribute who's data is fetched.
    XMLResultType resultType; // Type of data (only tag, body and both)
}_searchProperty;

int ExtractXMLData(char ch,searchParameters* searchParam,searchProperty *searchProperty, char* result);
void InitParser(void);
