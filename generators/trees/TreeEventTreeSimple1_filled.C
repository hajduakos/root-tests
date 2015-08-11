#include "TreeEventTreeSimple1.h"
#include "TreeEventTreeSimple1.C"
#include <TH2.h>
#include <TStyle.h>

class TreeEventTreeSimple1_filled : public TreeEventTreeSimple1{
public:
   TreeEventTreeSimple1_filled(TTree * /*tree*/ =0) : TreeEventTreeSimple1(0) { }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TreeEventTreeSimple1_filled, 0);
};

void TreeEventTreeSimple1_filled::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TreeEventTreeSimple1_filled::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
}

Bool_t TreeEventTreeSimple1_filled::Process(Long64_t entry)
{
   fReader.SetEntry(entry);

   fprintf(stderr, "EventSize: %d\n", *fEventSize);
   
   fprintf(stderr, "Px:");
   for(Int_t i = 0; i < fParticles.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles[i].fPosX);
   fprintf(stderr, "\n");

   fprintf(stderr, "Py:");
   for(Int_t i = 0; i < fParticles.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles[i].fPosY);
   fprintf(stderr, "\n");

   fprintf(stderr, "Pz:");
   for(Int_t i = 0; i < fParticles.GetSize(); ++i)
      fprintf(stderr, " %.1lf", fParticles[i].fPosZ);
   fprintf(stderr, "\n");

   return kTRUE;
}

void TreeEventTreeSimple1_filled::SlaveTerminate() { }

void TreeEventTreeSimple1_filled::Terminate() { }
