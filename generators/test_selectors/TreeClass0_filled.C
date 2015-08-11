#include "../generated_selectors/TreeClass0.h"
#include "../generated_selectors/TreeClass0.C"
#include <TH2.h>
#include <TStyle.h>

class TreeClass0_filled : public TreeClass0{
public:
   TreeClass0_filled(TTree * /*tree*/ =0) : TreeClass0(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeClass0_filled, 0);
};

void TreeClass0_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeClass0_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeClass0_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f\n", ClassC_branch->GetEv(), ClassC_branch->GetPx());

   return kTRUE;
}

void TreeClass0_filled::SlaveTerminate() { }

void TreeClass0_filled::Terminate() { }
