#include "TreeTClonesArray0.h"
#include "TreeTClonesArray0.C"
#include <TH2.h>
#include <TStyle.h>

class TreeTClonesArray0_filled : public TreeTClonesArray0{
public:
   TreeTClonesArray0_filled(TTree * /*tree*/ =0) : TreeTClonesArray0(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeTClonesArray0_filled, 0);
};

void TreeTClonesArray0_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeTClonesArray0_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeTClonesArray0_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < arr.GetSize(); i++) {
      ClassC c = arr[i];
      fprintf(stderr, "%.1f %d ", c.GetPx(), c.GetEv());
   }
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeTClonesArray0_filled::SlaveTerminate() { }

void TreeTClonesArray0_filled::Terminate(){ }
