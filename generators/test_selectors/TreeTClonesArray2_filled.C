#include "../generated_selectors/TreeTClonesArray2.h"
#include "../generated_selectors/TreeTClonesArray2.C"
#include <TH2.h>
#include <TStyle.h>

class TreeTClonesArray2_filled : public TreeTClonesArray2{
public:
   TreeTClonesArray2_filled(TTree * /*tree*/ =0) : TreeTClonesArray2(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeTClonesArray2_filled, 0);
};

void TreeTClonesArray2_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeTClonesArray2_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeTClonesArray2_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "fEv:");
   for (Int_t i = 0; i < arr_fEv.GetSize(); ++i) fprintf(stderr, " %d", arr_fEv[i]);
   fprintf(stderr, "\n");

   fprintf(stderr, "fPx:");
   for (Int_t i = 0; i < arr_fPx.GetSize(); ++i) fprintf(stderr, "% .1f", arr_fPx[i]);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeTClonesArray2_filled::SlaveTerminate() { }

void TreeTClonesArray2_filled::Terminate() { }
