#include "../generated_selectors/TreeArray.h"
#include "../generated_selectors/TreeArray.C"
#include <TH2.h>
#include <TStyle.h>

class TreeArray_filled : public TreeArray{
public:
   TreeArray_filled(TTree * /*tree*/ =0) : TreeArray(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeArray_filled, 0);
};

void TreeArray_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeArray_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeArray_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < arr.GetSize(); ++i) fprintf(stderr, "%.1f ", arr[i]);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeArray_filled::SlaveTerminate() { }

void TreeArray_filled::Terminate() { }
