#include "NLMS.h"

CNLMS::CNLMS()
{
	memset(X,0,N*sizeof(double));
	memset(W,0,N*sizeof(double));
}

CNLMS::~CNLMS()
{
}

double CNLMS::Tick(double s)
{
	int	   i;
	double E;
	double Y		= 0;
	double stepSize = 0;

	for (i=0; i < N; i++)
	{
		Y += (W[i] * X[i]);
	}

	E = s - Y;

	for (i=0; i < N; i++)
	{
		stepSize += (X[i] * X[i]);
	}

	if ( stepSize > 0 )
	{
		stepSize = 1 / stepSize;
		for (i=0; i < N; i++)
		{
			W[i] = W[i] + (stepSize * E * X[i]);
		}
	}

	for ( i = N-1; i > 0; i--)
	{
		X[i] = X[i-1];
	}

	X[0]	= s;
	m_res	= Y;
	return	  Y;
}

bool CNLMS::Predict(int num)
{
	double res;
	int i;

	if (num > N)
	{
		return false;
	}

	memcpy(PX,X,N*sizeof(double));
	memcpy(PW,W,N*sizeof(double));
	memset(PR,0,N*sizeof(double));
	res = m_res;
	for (i = 0; i < num; i++)
	{
		res		= Tick(res);
		PR[i]	= res;
	}
	memcpy(X, PX, N * sizeof(double));
	memcpy(W, PW, N * sizeof(double));
	return true;
}