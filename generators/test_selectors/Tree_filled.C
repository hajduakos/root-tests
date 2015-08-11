#include "../generated_selectors/Tree.h"
#include "../generated_selectors/Tree.C"
#include <TH2.h>
#include <TStyle.h>

class Tree_filled : public Tree{
public:
   Tree_filled(TTree * /*tree*/ =0) : Tree(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Tree_filled, 0);
};

void Tree_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void Tree_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t Tree_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "%.1f %.1f %.1f %.1lf %d\n", *px, *py, *py, *random, *ev);

   return kTRUE;
}

void Tree_filled::SlaveTerminate() { }

void Tree_filled::Terminate() { }
