#include "include/ZBTagEff.h"
#include "SFrameTools/include/EventCalc.h"
#include <iostream>

using namespace std;

ZBTagEff::ZBTagEff(const char* name) : BaseHists(name)
{
    // named default constructor
}

ZBTagEff::~ZBTagEff()
{
    // default destructor, does nothing
}

void ZBTagEff::Init()
{
    // book all histograms here
    double jetpt_bbins[] = {
        20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
    };

    double jetpt_cbins[] = {
        20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 1600
    };

    double jetpt_lbins[] = {
        20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 1600
    };

    // basic jet kinematics
    Book( TH1F( "pt_bJet"," p_{T} b-jets", 17, jetpt_bbins));

    Book( TH1F( "pt_cJet"," p_{T} c-jets", 14, jetpt_cbins));

    Book( TH1F( "pt_lJet_e1L"," p_{T} l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e2L"," p_{T} l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e3L"," p_{T} l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e4L"," p_{T} l-jets", 16, jetpt_lbins));

    Book( TH1F( "pt_lJet_e1M"," p_{T} l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e2M"," p_{T} l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e3M"," p_{T} l-jets", 16, jetpt_lbins));

    Book( TH1F( "pt_lJet_e1T"," p_{T} l-jets", 16, jetpt_lbins));

    Book( TH1F( "pt_bJet_bTagL"," p_{T} tagged b-jets", 17, jetpt_bbins));
    Book( TH1F( "pt_bJet_bTagM"," p_{T} tagged b-jets", 17, jetpt_bbins));
    Book( TH1F( "pt_bJet_bTagT"," p_{T} tagged b-jets", 17, jetpt_bbins));

    Book( TH1F( "pt_cJet_bTagL"," p_{T} tagged c-jets", 14, jetpt_cbins));
    Book( TH1F( "pt_cJet_bTagM"," p_{T} tagged c-jets", 14, jetpt_cbins));
    Book( TH1F( "pt_cJet_bTagT"," p_{T} tagged c-jets", 14, jetpt_cbins));

    Book( TH1F( "pt_lJet_e1_bTagL"," p_{T} tagged l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e2_bTagL"," p_{T} tagged l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e3_bTagL"," p_{T} tagged l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e4_bTagL"," p_{T} tagged l-jets", 16, jetpt_lbins));

    Book( TH1F( "pt_lJet_e1_bTagM"," p_{T} tagged l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e2_bTagM"," p_{T} tagged l-jets", 16, jetpt_lbins));
    Book( TH1F( "pt_lJet_e3_bTagM"," p_{T} tagged l-jets", 16, jetpt_lbins));

    Book( TH1F( "pt_lJet_e1_bTagT"," p_{T} tagged l-jets", 16, jetpt_lbins));

}

void ZBTagEff::Fill()
{
    EventCalc* calc = EventCalc::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
    double weight = calc -> GetWeight();

    //Only the efficiency matters, no lumi normalization is of interest here
    weight=1.;

    std::vector<Particle> subjets_top;
    std::vector<float> btagsub_combinedSecondaryVertex_top;
    std::vector<int> flavorsub_top;

    bool checkbtagL=0;
    bool checkbtagM=0;
    bool checkbtagT=0;

    for (unsigned int i =0; i<bcc->toptagjets->size(); ++i) {
      //Hard-coded pt cut
      //qui pt >200
      if(bcc->toptagjets->at(i).pt()<200.) continue;
      if(!HepTopTag(bcc->toptagjets->at(i))) continue;
      //int jettagged=1;
      //via questa riga
      //if(!(bcc->muons->size()>0)) continue;

      //double deltaphi=bcc->toptagjets->at(i).deltaPhi(bcc->muons->at(0));
    //via questa riga
      //chiedere che il jet passi HTT
      //if(!(jettagged&&(deltaphi>(2*PI/3))&&(bcc->toptagjets->at(i).pt()>150.)&&(fabs(bcc->toptagjets->at(i).eta())<2.5))) continue;

      TopJet topjet=bcc->toptagjets->at(i);
      
      subjets_top=topjet.subjets();
      btagsub_combinedSecondaryVertex_top=topjet.btagsub_combinedSecondaryVertex();
      flavorsub_top=topjet.flavorsub();

      //Looping over subjets and checking if they are b-tagged
      for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
	
	float test=btagsub_combinedSecondaryVertex_top[j];
	
	Particle subjet=subjets_top[j];
	
	checkbtagL=0;
	
	if(test>0.244){
	  checkbtagL=1;
	}

	checkbtagM=0;
	
	if(test>0.679){
	  checkbtagM=1;
	}

	checkbtagT=0;
	
	if(test>0.898){
	  checkbtagT=1;
	}
	
        unsigned int flavor = abs(flavorsub_top[j]);
 	
        switch(flavor) {
        case 5: // b-jets
	  Hist("pt_bJet") -> Fill(subjet.pt(),weight);
	  if (checkbtagL) {
	    Hist("pt_bJet_bTagL") -> Fill(subjet.pt(),weight);
	  }
	  if (checkbtagM) {
	    Hist("pt_bJet_bTagM") -> Fill(subjet.pt(),weight);
	  }
	  if (checkbtagT) {
	    Hist("pt_bJet_bTagT") -> Fill(subjet.pt(),weight);
	  }
	  break;
        case 4: // c-jets
	  Hist("pt_cJet") -> Fill(subjet.pt(),weight);
	  if (checkbtagL) {
	    Hist("pt_cJet_bTagL") -> Fill(subjet.pt(),weight);
	  }
	  if (checkbtagM) {
	    Hist("pt_cJet_bTagM") -> Fill(subjet.pt(),weight);
	  }
	  if (checkbtagT) {
	    Hist("pt_cJet_bTagT") -> Fill(subjet.pt(),weight);
	  }
	  break;
        case 3: // s-quark
        case 2: // d-quark
        case 1: // u-quark
        case 21: // gluon
	  if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=0.5){
	    Hist("pt_lJet_e1L") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=0.5&&fabs(subjet.eta())<=1.0){
	    Hist("pt_lJet_e2L") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=1.0&&fabs(subjet.eta())<=1.5){
	    Hist("pt_lJet_e3L") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=1.5&&fabs(subjet.eta())<=2.4){
	    Hist("pt_lJet_e4L") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=0.8){
	    Hist("pt_lJet_e1M") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=0.8&&fabs(subjet.eta())<=1.6){
	    Hist("pt_lJet_e2M") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=1.6&&fabs(subjet.eta())<=2.4){
	    Hist("pt_lJet_e3M") -> Fill(subjet.pt(),weight);
	  }
	  if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=2.4){
	    Hist("pt_lJet_e1T") -> Fill(subjet.pt(),weight);
	  }
	  if (checkbtagL) {
	    if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=0.5){
	      Hist("pt_lJet_e1_bTagL") -> Fill(subjet.pt(),weight);
	    }
	    if(fabs(subjet.eta())>=0.5&&fabs(subjet.eta())<=1.0){
	      Hist("pt_lJet_e2_bTagL") -> Fill(subjet.pt(),weight);
	    }
	    if(fabs(subjet.eta())>=1.0&&fabs(subjet.eta())<=1.5){
	      Hist("pt_lJet_e3_bTagL") -> Fill(subjet.pt(),weight);
	    }
	    if(fabs(subjet.eta())>=1.5&&fabs(subjet.eta())<=2.4){
	      Hist("pt_lJet_e4_bTagL") -> Fill(subjet.pt(),weight);
	    }
	  }
	  if (checkbtagM) {
	    if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=0.8){
	      Hist("pt_lJet_e1_bTagM") -> Fill(subjet.pt(),weight);
	    }
	    if(fabs(subjet.eta())>=0.8&&fabs(subjet.eta())<=1.6){
	      Hist("pt_lJet_e2_bTagM") -> Fill(subjet.pt(),weight);
	    }
	    if(fabs(subjet.eta())>=1.6&&fabs(subjet.eta())<=2.4){
	      Hist("pt_lJet_e3_bTagM") -> Fill(subjet.pt(),weight);
	    }
	  }
	  if (checkbtagT) {
	    if(fabs(subjet.eta())>=0&&fabs(subjet.eta())<=2.4){
	      Hist("pt_lJet_e1_bTagT") -> Fill(subjet.pt(),weight);
	    }
	  }
	  break;
        default:
	  break;
        }
      }
    }
}


void ZBTagEff::Finish()
{
  // final calculations, like division and addition of certain histograms
}

