#ifndef Sample_classes
#define Sample_classes

#include "TObject.h"

class ClassC : public TObject {
private:
   Float_t fPx;
   Int_t   fEv;
public:
   ClassC(Float_t fPx_, Int_t fEv_) : fPx(fPx_), fEv(fEv_) { }
   ClassC() : ClassC(0, 0) { }
   virtual ~ClassC() { }
   
   Float_t GetPx() const { return fPx; }
   Int_t   GetEv() const { return fEv; }
   void Set(Float_t fPx_, Int_t fEv_) { fPx = fPx_; fEv = fEv_; }
   
   ClassDef(ClassC, 1);
};

#endif
