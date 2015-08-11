#include "TreeEventTreeSimple0.h"
#include "TreeEventTreeSimple0.C"
#include <TH2.h>
#include <TStyle.h>

class TreeEventTreeSimple0_filled : public TreeEventTreeSimple0{
public:
   TreeEventTreeSimple0_filled(TTree * /*tree*/ =0) : TreeEventTreeSimple0(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeEventTreeSimple0_filled, 0);
};

void TreeEventTreeSimple0_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeEventTreeSimple0_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeEventTreeSimple0_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "EventSize: %d\n", Event_branch->fEventSize);
   
   fprintf(stderr, "Px:");
   for(Int_t i = 0; i < Event_branch->fParticles.size(); ++i)
      fprintf(stderr, " %.1lf", Event_branch->fParticles[i].fPosX);
   fprintf(stderr, "\n");

   fprintf(stderr, "Py:");
   for(Int_t i = 0; i < Event_branch->fParticles.size(); ++i)
      fprintf(stderr, " %.1lf", Event_branch->fParticles[i].fPosY);
   fprintf(stderr, "\n");

   fprintf(stderr, "Pz:");
   for(Int_t i = 0; i < Event_branch->fParticles.size(); ++i)
      fprintf(stderr, " %.1lf", Event_branch->fParticles[i].fPosZ);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeEventTreeSimple0_filled::SlaveTerminate() { }

void TreeEventTreeSimple0_filled::Terminate() { }
