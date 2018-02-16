typedef struct {
	long long int cardno;
	char bankcode[6];
	char firstname[20];
	char lastname[20];
	char expiry[8];
	
} info;
typedef info* Info;

Info readfn(char s[10]);
Info insertInOrder(Info arr, int size, info c);
unsigned int insertion(Info arr, int size);
int getSize(Info arr);
