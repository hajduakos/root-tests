#include "TreeStruct.h"
#include "TreeStruct.C"
#include <TH2.h>
#include <TStyle.h>

class TreeStruct_filled : public TreeStruct{
public:
   TreeStruct_filled(TTree * /*tree*/ =0) : TreeStruct(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeStruct_filled, 0);
};

void TreeStruct_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeStruct_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeStruct_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "%.1f %.1f %.1f %d\n", *px, *py, *py, *ev);

   return kTRUE;
}

void TreeStruct_filled::SlaveTerminate() { }

void TreeStruct_filled::Terminate() { }
