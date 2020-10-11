#include <string>
#include <iostream>
using namespace std;

unsigned int alphabetB256U[256] =
{
'0','1','2','3','4','5','6','7','8','9',								 // ASCII digits
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', // ASCIII upper
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', // ASCII lower
'!','\'','#','$','%','&','\'','(',')','*','+',',','-','.','/','<','=','>','?','@','[','\\',']','^','_',	 // ASCII misc
'`','{','|','}','~',											
161,162,163,164,165,166,167,169,170,171,172,174,175,176,177,178,179,180,181,182,187,191,		 // Latin 1
192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,
256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,
272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,
288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,
304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,
320,321,322,323,324,325,326,327,328,329,330,331,332,333,
};

string encodeInB256U(uint8_t *dataPtr, size_t dataSize)
{
	string result = {};
	for (size_t i = 0; i < dataSize; i++)
	{	
		auto unicode = alphabetB256U[dataPtr[i]];
		if (unicode < 128)
			result.push_back(unicode);
		else
		{
			result.push_back(192 + (unicode >> 6));
			result.push_back(128 + (unicode & 63));
		}
	}
	return result;
}

void randomize(uint8_t *dataPtr, size_t dataSize)
{
	srand(time(nullptr));
	for (int i = 0; i < dataSize; i++)
		dataPtr[i] = rand();
}

int main(int argc, char *argv[])
{
	uint8_t binaryData[128 / 8] = {};
	randomize(binaryData, sizeof(binaryData));

	cout << "random 128 bit encoded in B256U: " << encodeInB256U(binaryData, sizeof(binaryData)) << endl;

	return 0;
}
