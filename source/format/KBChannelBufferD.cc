#include "KBChannelBufferD.hh"

ClassImp(KBChannelBufferD)

void KBChannelBufferD::Clear(Option_t *)
{
  fID = -1;
  fPos1 = TVector3(-999,-999,-999);
  fPos2 = TVector3(-999,-999,-999);

  for (auto iTb = 0; iTb < fN; ++iTb)
    fArray[iTb] = 0;
}

void KBChannelBufferD::Copy(TObject &obj) const
{
  TObject::Copy(obj);
  auto channel = (KBChannelBufferD &) obj;

  channel.SetID(fID);
  channel.SetPos1(fPos1);
  channel.SetPos2(fPos2);

  channel.Set(fN);
  for (auto iTb = 0; iTb < fN; ++iTb)
    channel.SetAt(iTb, fArray[iTb]);
}

TH1 *KBChannelBufferD::GetHist(TString name)
{
  if (name.IsNull())
    name = Form("Channel%d",fID);

  auto hist = new TH1D(name,Form("Channel%d;Time-bucket;ADC",fID),fN,0,fN);
  for (auto iTb = 0; iTb < fN; ++iTb)
    hist -> SetBinContent(iTb+1,fArray[iTb]);

  return hist;
}
