#include "include/HEPTopTaggerReweight.h"
#include "SFrameTools/include/EventCalc.h"

double HEPTopTaggerReweight::GetScaleWeight1(int index)
{
  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  double scale_factor = 1.;
  if(!IsRealData)
  {
    double jetpt=bcc->toptagjets->at(index).pt();
    
    if(jetpt>200. && jetpt<=250.) scale_factor *= 0.924272951738;//0.92
    if(jetpt>250. && jetpt<=400.) scale_factor *= 0.946817294077;//0.95
    if(jetpt>400.) scale_factor *= 1.28199803289;//1.28
}
  return scale_factor;
}

double HEPTopTaggerReweight::GetScaleWeight(std::vector<int> Indices, string type)
{
    EventCalc* calc = EventCalc::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
    bool IsRealData = calc->IsRealData();
    double scale_factor = 1.;
    if(!IsRealData)
      {
	//mean
	if (type=="")
	{
	  
	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
	  
	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.924272951738;//0.92
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.946817294077;//0.95
	  if(jetpt>400.) scale_factor *= 1.28199803289;//1.28
	  
	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
	  
	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.924272951738;//0.92
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.946817294077;//0.95
	  if(jetpt>400.) scale_factor *= 1.28199803289;//1.28
	  
// 	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
// 	  double jeteta=fabs(bcc->toptagjets->at(Indices[0]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.92;
// 	    else scale_factor *= 0.93;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.95;
// 	    else scale_factor *= 0.95;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.36;
// 	    else scale_factor *= 0.95;
// 	  }
// 	  
// 	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
// 	  jeteta=fabs(bcc->toptagjets->at(Indices[1]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.92;
// 	    else scale_factor *= 0.93;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.95;
// 	    else scale_factor *= 0.95;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.36;
// 	    else scale_factor *= 0.95;
// 	  }
	  return scale_factor;
	}
	
	// 	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
	// 	  
	// 	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.959548632146;
	// 	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.980234133823;
	// 	  if(jetpt>400.) scale_factor *= 1.0461755891;
	// 	  
	// 	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
	// 	  
	// 	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.959548632146;
	// 	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.980234133823;
	// 	  if(jetpt>400.) scale_factor *= 1.0461755891;
	
	//down
	if (type=="down")
	{
	  
	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
	  
	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.8906064859;//0.89
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.9212657136;//0.92
	  if(jetpt>400.) scale_factor *= 1.2000252603;//1.2
	  
	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
	  
	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.8906064859;//0.89
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.9212657136;//0.92
	  if(jetpt>400.) scale_factor *= 1.2000252603;//1.2
	  

// 	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
// 	  double jeteta=fabs(bcc->toptagjets->at(Indices[0]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.88;
// 	    else scale_factor *= 0.87;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.92;
// 	    else scale_factor *= 0.90;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.29;
// 	    else scale_factor *= 0.80;
// 	  }
// 	  
// 	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
// 	  jeteta=fabs(bcc->toptagjets->at(Indices[1]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.88;
// 	    else scale_factor *= 0.87;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.92;
// 	    else scale_factor *= 0.90;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.29;
// 	    else scale_factor *= 0.80;
// 	  }
	  return scale_factor;
	}
	//up
	if (type=="up")
	{
	  
	  double jetpt=bcc->toptagjets->at(Indices[0]).pt();
	  
	  if(jetpt>200. && jetpt<=250.) scale_factor *= 0.9579394176;//0.95
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.9723688746;//0.98
	  if(jetpt>400.) scale_factor *= 1.3639708055;//1.36
	  
	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
      
      if(jetpt>200. && jetpt<=250.) scale_factor *= 0.9579394176;//0.95
	  if(jetpt>250. && jetpt<=400.) scale_factor *= 0.9723688746;//0.98
	  if(jetpt>400.) scale_factor *= 1.3639708055;//1.36
	  
// 	double jetpt=bcc->toptagjets->at(Indices[0]).pt();
// 	double jeteta=fabs(bcc->toptagjets->at(Indices[0]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.96;
// 	    else scale_factor *= 0.99;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.98;
// 	    else scale_factor *= 1.00;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.43;
// 	    else scale_factor *= 1.10;
// 	  }
// 	  
// 	  jetpt=bcc->toptagjets->at(Indices[1]).pt();
// 	  jeteta=fabs(bcc->toptagjets->at(Indices[1]).eta());
// 	  
// 	  if(jetpt>200. && jetpt<=250.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.96;
// 	    else scale_factor *= 0.99;
// 	  }
// 	  if(jetpt>250. && jetpt<=400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 0.98;
// 	    else scale_factor *= 1.00;
// 	  }
// 	  if(jetpt>400.)
// 	  {
// 	    if (jeteta<1.0) scale_factor *= 1.43;
// 	    else scale_factor *= 1.10;
// 	  }
	  return scale_factor;
	}
	
	
      }
    //std::cout<<"sf from HEPTopTaggerReweight: "<<scale_factor<<std::endl;
     return scale_factor;
}
