#include "KBWPoint.hh"
#include <iostream>
#include <iomanip>
using namespace std;

ClassImp(KBWPoint)

KBWPoint::KBWPoint()
{
  Clear();
}

KBWPoint::KBWPoint(Double_t x, Double_t y, Double_t z, Double_t w)
{
  Set(x,y,z,w);
}

void KBWPoint::Set(Double_t x, Double_t y, Double_t z, Double_t w)
{
  fX = x;
  fY = y;
  fZ = z;
  fW = w;
}

void KBWPoint::Print(Option_t *) const
{
  cout << "XYZ|W: "
       << setw(12) << fX 
       << setw(12) << fY
       << setw(12) << fZ << " |"
       << setw(12) << fW << endl;
}

void KBWPoint::Clear(Option_t *)
{
  fX = 0;
  fY = 0;
  fZ = 0;
  fW = 0;
}

void KBWPoint::Copy(TObject &obj) const
{
  KBContainer::Copy(obj);
  auto wp = (KBWPoint &) obj;

  wp.Set(fX, fY, fZ, fW);
}

void KBWPoint::SetW(Double_t w) { fW = w; }

void KBWPoint::SetPosition(Double_t x, Double_t y, Double_t z)
{
  fX = x;
  fY = y;
  fZ = z;
}

void KBWPoint::SetPosition(TVector3 pos)
{
  fX = pos.X();
  fY = pos.Y();
  fZ = pos.Z();
}

#ifdef ACTIVATE_EVE
bool KBWPoint::DrawByDefault() { return true; }
bool KBWPoint::IsEveSet() { return true; }

TEveElement *KBWPoint::CreateEveElement()
{
  auto pointSet = new TEvePointSet("WPoint");
  pointSet -> SetMarkerColor(kBlack);
  pointSet -> SetMarkerSize(0.5);
  pointSet -> SetMarkerStyle(20);

  return pointSet;
}

void KBWPoint::SetEveElement(TEveElement *)
{
}

void KBWPoint::AddToEveSet(TEveElement *eveSet)
{
  auto pointSet = (TEvePointSet *) eveSet;
  pointSet -> SetNextPoint(fX, fY, fZ);
}
#endif
