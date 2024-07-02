// NLMSAnalyzer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NLMS.h"
#include <math.h>

#define Q 256

int main()
{
	int i;
	double array[Q];

	CNLMS* m_pNLMS= new CNLMS();

	for (i = 0; i < Q; i++)
	{
		array[i] = sin((2 * M_PI *i) / Q)+1;
		m_pNLMS->Tick(array[i]);
	}
	delete m_pNLMS;
    return 0;
}

