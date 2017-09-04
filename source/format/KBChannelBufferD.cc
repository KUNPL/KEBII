#include "KBChannelBufferD.hh"

ClassImp(KBChannelBufferD)

void KBChannelBufferD::Clear(Option_t *)
{
  fID = -1;

  for (auto iTb = 0; iTb < fN; ++iTb)
    fArray[iTb] = 0;
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
