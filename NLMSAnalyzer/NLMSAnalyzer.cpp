//////////////////////////////////////////////////////////////////////////
// NLMSAnalyzer.cpp : Defines the entry point for the console application.
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NLMS.h"
#include <math.h>

#define Q 128

int main()
{
	int		i;
	char	buffer[64];
	double  input[Q];
	double	array[Q];
	double  dtemp;
	///////////////////////////////////////
	CNLMS* m_pNLMS = new CNLMS();
	for (i = 0; i < Q; i++)
	{
		dtemp		= 8 + 4*sin((2 * M_PI *i) /(Q/2));
		input[i]	= dtemp;
		array[i]	= m_pNLMS->Tick(input[i]);
	}
	m_pNLMS->Predict(N);
	double* result = m_pNLMS->GetResult();
	///////////////////////////////////////
	FILE* f = fopen("Result.log","w");
	FILE* fi = fopen("input.log", "w");
	int idx = 1;
	for (i = 0; i < Q; i++)
	{
		sprintf(buffer, "%3.7lf,", array[i]);
		fputs(buffer, f);
		sprintf(buffer, "%3.7lf,", input[i]);
		fputs(buffer, fi);

	}
	///////////////////////////////////////
	for (i = 0; i < N; i++)
	{
		sprintf(buffer, "%3.7lf,", result[i]);
		fputs(buffer, f);
	}
	fclose(f);
	fclose(fi);
	///////////////////////////////////////
	delete m_pNLMS;
    return 0;
}