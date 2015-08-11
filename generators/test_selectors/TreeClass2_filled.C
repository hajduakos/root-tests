#include "../generated_selectors/TreeClass2.h"
#include "../generated_selectors/TreeClass2.C"
#include <TH2.h>
#include <TStyle.h>

class TreeClass2_filled : public TreeClass2{
public:
   TreeClass2_filled(TTree * /*tree*/ =0) : TreeClass2(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeClass2_filled, 0);
};

void TreeClass2_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeClass2_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeClass2_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f\n", *fEv, *fPx);

   return kTRUE;
}

void TreeClass2_filled::SlaveTerminate() { }

void TreeClass2_filled::Terminate() { }
