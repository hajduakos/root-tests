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

class ClassB : public TObject {
private:
   ClassC  fC;
   Float_t fPy;
public:
   ClassB(Float_t fPx_, Int_t fEv_, Float_t fPy_) : fC(fPx_, fEv_), fPy(fPy_) { }
   ClassB() : ClassB(0, 0, 0) { }
   virtual ~ClassB() { }
   
   ClassC  GetC() const { return fC; }
   Float_t GetPy() const { return fPy; }
   void Set(Float_t fPx_, Int_t fEv_, Float_t fPy_) {
      fC.Set(fPx_, fEv_);
      fPy = fPy_;
   }
   
   ClassDef(ClassB, 1);
};

#endif
