//#include "StdAfx.h"
#include "MuPDFConvert.h"

int main(void)
{
	CMuPDFConvert pdfConvert;
	int nNum = 1;
	pdfConvert.Pdf2Png(L"HousePlan.pdf", "test", nNum);
	return 0;
}