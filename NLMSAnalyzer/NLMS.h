#pragma once

#include <windows.h>

#define		N		64					//order of filter
#define		I		1000				//number of samples


class CNLMS
{
private:
	double			X[N];
	double			W[N];
public:
				 CNLMS();
				~CNLMS();
	void		Tick(double s);
};