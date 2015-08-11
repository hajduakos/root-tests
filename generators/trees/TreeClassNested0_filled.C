#include "TreeClassNested0.h"
#include "TreeClassNested0.C"
#include <TH2.h>
#include <TStyle.h>

class TreeClassNested0_filled : public TreeClassNested0{
public:
   TreeClassNested0_filled(TTree * /*tree*/ =0) : TreeClassNested0(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeClassNested0_filled, 0);
};

void TreeClassNested0_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeClassNested0_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeClassNested0_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f, Py: %.1lf\n", ClassB_branch->GetC().GetEv(), ClassB_branch->GetC().GetPx(), ClassB_branch->GetPy());

   return kTRUE;
}

void TreeClassNested0_filled::SlaveTerminate() { }

void TreeClassNested0_filled::Terminate() { }
