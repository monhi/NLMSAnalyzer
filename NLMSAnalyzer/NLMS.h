#pragma once

#include <windows.h>

#define		N		64					//order of filter
#define		I		1000				//number of samples

class CNLMS
{
private:
	double			X[N];
	double			W[N];
	double			m_res;
private:
	double			PX[N];
	double			PW[N];
	double			PR[N];
public:
				 CNLMS();
				~CNLMS();
	double		 Tick(double s);
	double		 PredictedTick(double s);
	bool		 Predict(int num);
	double*		 GetResult() { return &PR[0]; }
};