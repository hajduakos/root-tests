#include "TreeContainers.h"
#include "TreeContainers.C"
#include <TH2.h>
#include <TStyle.h>

class TreeContainers_filled : public TreeContainers{
public:
   TreeContainers_filled(TTree * /*tree*/ =0) : TreeContainers(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeContainers_filled, 0);
};

void TreeContainers_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeContainers_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeContainers_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   for (Int_t i = 0; i < vectorBranch.GetSize(); ++i) fprintf(stderr, "%d ", vectorBranch[i]);
   fprintf(stderr, "\n");

   for (Int_t i = 0; i < setBranch.GetSize(); ++i) fprintf(stderr, "%d ", setBranch[i]);
   fprintf(stderr, "\n");

   for (Int_t i = 0; i < listBranch.GetSize(); ++i) fprintf(stderr, "%d ", listBranch[i]);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeContainers_filled::SlaveTerminate() { }

void TreeContainers_filled::Terminate() { }
