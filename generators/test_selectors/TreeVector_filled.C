#include "../generated_selectors/TreeVector.h"
#include "../generated_selectors/TreeVector.C"
#include <TH2.h>
#include <TStyle.h>

class TreeVector_filled : public TreeVector{
public:
   TreeVector_filled(TTree * /*tree*/ =0) : TreeVector(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeVector_filled, 0);
};

void TreeVector_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeVector_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeVector_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < vpx.GetSize(); ++i) fprintf(stderr, "%.1f ", vpx[i]);
   fprintf(stderr, "\n");
   
   for (Int_t i = 0; i < vb->size(); ++i) fprintf(stderr, "%d ", static_cast<int>((*vb)[i]));
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeVector_filled::SlaveTerminate() { }

void TreeVector_filled::Terminate() { }
