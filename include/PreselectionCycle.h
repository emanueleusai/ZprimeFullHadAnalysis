// Dear emacs, this is -*- c++ -*-
// $Id: PreselectionCycle.h,v 1.4 2013/06/12 12:40:14 peiffer Exp $
#ifndef PreselectionCycle_H
#define PreselectionCycle_H

#include "SFrameAnalysis/include/AnalysisCycle.h"
#include "ZprimeFullHadTools.h"

/**
 *   @short ZprimeFullHad of an analysis cycle
 *
 *          This is an example of an analysis cycle. It can be used
 *          as a template for writing your own analysis. Also should
 *          be used for quick cross checks of the system setup.
 *
 *  @author Roman Kogler
 *  @version $Revision: 1.4 $
 */

class PreselectionCycle : public AnalysisCycle {

public:
  /// Default constructor
  PreselectionCycle();
  /// Default destructor
  ~PreselectionCycle();

  /// Function called at the beginning of the cycle
  void BeginCycle() throw( SError );
  /// Function called at the end of the cycle
  void EndCycle() throw( SError );

  /// Function called at the beginning of a new input data
  void BeginInputData( const SInputData& ) throw( SError );
  /// Function called after finishing to process an input data
  void EndInputData  ( const SInputData& ) throw( SError );

  /// Function called after opening each new input file
  void BeginInputFile( const SInputData& ) throw( SError );

  /// Function called for every event
  void ExecuteEvent( const SInputData&, Double_t ) throw( SError );

private:
  //
  // Put all your private variables here
  //
  
   Selection *TriggerHT,*TriggerQuad;//* BSel, * NoBSel, *TopSel, *chi2_selection;

  // Macro adding the functions for dictionary generation
  ClassDef( PreselectionCycle, 0 );

}; // class PreselectionCycle

#endif // PreselectionCycle_H

