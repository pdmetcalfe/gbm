//------------------------------------------------------------------------------
//
//  File:       varsplitter.h
//
//  Description: header for class that splits a node on a particular variable.
//
//------------------------------------------------------------------------------

#ifndef __varsplitter_h__
#define __varsplitter_h__

//------------------------------
// Includes
//------------------------------
#include "node.h"
#include "nodeParameters.h"
#include <Rcpp.h>

//------------------------------
// Class Definition
//------------------------------
class VarSplitter
{
public:
	//----------------------
	// Public Constructors
	//----------------------
	VarSplitter(unsigned long minNumObs);

	//---------------------
	// Public destructor
	//---------------------
	~VarSplitter();

	//---------------------
	// Public Functions
	//---------------------
	void SetForNode(CNode& nodeToSet);
	void SetForVariable(unsigned long iWhichVar, long cVarClasses);

	inline double GetBestImprovement() { return bestSplit.GetImprovement(); };
	void IncorporateObs(double dX,
			double dZ,
			double dW,
			long lMonotone);
	void EvaluateCategoricalSplit();
	inline NodeParams GetBestSplit() { return bestSplit;};
	void Reset();

private:
	//---------------------
	// Private Functions
	//---------------------
	void WrapUpSplit();
	
	//---------------------
	// Private Variables
	//---------------------
	double InitTotalWeight, InitWeightResiduals, dLastXValue;
	unsigned long InitNumObs;
	unsigned long minObsInNode;
	NodeParams bestSplit, proposedSplit;



};
#endif // __varplitter_h__
