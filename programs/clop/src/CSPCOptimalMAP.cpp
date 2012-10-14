/////////////////////////////////////////////////////////////////////////////
//
// CSPCOptimalMAP.cpp
//
// Rémi Coulom
//
// July, 2009
//
/////////////////////////////////////////////////////////////////////////////
#include "CSPCOptimalMAP.h"
#include "CRegression.h"
#include "CSPCOptimal.h"

/////////////////////////////////////////////////////////////////////////////
// Constructor
/////////////////////////////////////////////////////////////////////////////
CSPCOptimalMAP::CSPCOptimalMAP(CRegression &reg):
 reg(reg),
 v(1)
{
}

/////////////////////////////////////////////////////////////////////////////
// Get Sample
/////////////////////////////////////////////////////////////////////////////
const double *CSPCOptimalMAP::NextSample(int i)
{
 CSPCOptimal copt(reg.MAP());

 if (reg.GetSamples() & 1)
  v[0] = copt.GetMin();
 else
  v[0] = copt.GetMax();

 if (v[0] < -1.0)
  v[0] = -1.0;
 else if (v[0] > 1.0)
  v[0] = 1.0;

 return &v[0];
}