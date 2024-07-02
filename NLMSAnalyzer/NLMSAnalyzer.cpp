// NLMSAnalyzer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NLMS.h"
#include <math.h>

#define Q 256

int main()
{
	int		i;
	char	buffer[64];
	double	array[Q];
	double  dtemp;

	CNLMS* m_pNLMS= new CNLMS();

	for (i = 0; i < Q; i++)
	{
		 dtemp		= sin((2 * M_PI *i) / Q)+1;
		 array[i]	= m_pNLMS->Tick(dtemp);
	}

	m_pNLMS->Predict(N);
	double* result = m_pNLMS->GetResult();
	///////////////////////////////////////
	FILE* f = fopen("Result.log","w");
	int idx = 1;
	for (i = 0; i < Q; i++)
	{
		sprintf(buffer, "%d,%2.7lf\n", idx++,array[i]);
		fputs(buffer, f);
	}

	for (i = 0; i < N; i++)
	{
		sprintf(buffer, "%d,%2.7lf\n",idx++, result[i]);
		fputs(buffer, f);
	}
	fclose(f);
	///////////////////////////////////////
	delete m_pNLMS;
    return 0;
}

