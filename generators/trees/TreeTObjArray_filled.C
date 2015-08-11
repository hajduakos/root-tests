#include "TreeTObjArray.h"
#include "TreeTObjArray.C"
#include <TH2.h>
#include <TStyle.h>

class TreeTObjArray_filled : public TreeTObjArray{
public:
   TreeTObjArray_filled(TTree * /*tree*/ =0) : TreeTObjArray(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeTObjArray_filled, 0);
};

void TreeTObjArray_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeTObjArray_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeTObjArray_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < arr->GetSize(); i++) {
      ClassC *c = (ClassC*)((*arr)[i]);
      fprintf(stderr, "%.1f %d ", c->GetPx(), c->GetEv());
   }
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeTObjArray_filled::SlaveTerminate() { }

void TreeTObjArray_filled::Terminate() { }
