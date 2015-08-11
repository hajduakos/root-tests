#include "../generated_selectors/TreeClassNested2.h"
#include "../generated_selectors/TreeClassNested2.C"
#include <TH2.h>
#include <TStyle.h>

class TreeClassNested2_filled : public TreeClassNested2{
public:
   TreeClassNested2_filled(TTree * /*tree*/ =0) : TreeClassNested2(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeClassNested2_filled, 0);
};

void TreeClassNested2_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeClassNested2_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeClassNested2_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f, Py: %.1lf\n", *fC_fEv, *fC_fPx, *fPy);

   return kTRUE;
}

void TreeClassNested2_filled::SlaveTerminate() { }

void TreeClassNested2_filled::Terminate() { }
