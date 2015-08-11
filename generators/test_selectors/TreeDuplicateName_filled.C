#include "../generated_selectors/TreeDuplicateName.h"
#include "../generated_selectors/TreeDuplicateName.C"
#include <TH2.h>
#include <TStyle.h>

class TreeDuplicateName_filled : public TreeDuplicateName{
public:
   TreeDuplicateName_filled(TTree * /*tree*/ =0) : TreeDuplicateName(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeDuplicateName_filled, 0);
};

void TreeDuplicateName_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeDuplicateName_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeDuplicateName_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "Ev: %d, Px: %.1f\n", *fEv, *fPx);

   return kTRUE;
}

void TreeDuplicateName_filled::SlaveTerminate() { }

void TreeDuplicateName_filled::Terminate() { }
