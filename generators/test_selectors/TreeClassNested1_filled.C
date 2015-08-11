#include "../generated_selectors/TreeClassNested1.h"
#include "../generated_selectors/TreeClassNested1.C"
#include <TH2.h>
#include <TStyle.h>

class TreeClassNested1_filled : public TreeClassNested1{
public:
   TreeClassNested1_filled(TTree * /*tree*/ =0) : TreeClassNested1(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeClassNested1_filled, 0);
};

void TreeClassNested1_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeClassNested1_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeClassNested1_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f, Py: %.1lf\n", fC->GetEv(), fC->GetPx(), *fPy);

   return kTRUE;
}

void TreeClassNested1_filled::SlaveTerminate() { }

void TreeClassNested1_filled::Terminate() { }
