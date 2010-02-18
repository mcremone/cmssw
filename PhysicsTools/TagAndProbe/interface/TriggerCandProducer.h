#ifndef PhysicsTools_TagAndProbe_TriggerCandProducer_h
#define PhysicsTools_TagAndProbe_TriggerCandProducer_h

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/ShallowCloneCandidate.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "PhysicsTools/TagAndProbe/interface/TriggerCandProducer.h"

#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "FWCore/Framework/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"

// forward declarations
template<class object>
class TriggerCandProducer : public edm::EDProducer 
{
 public:
  explicit TriggerCandProducer(const edm::ParameterSet&);
  ~TriggerCandProducer();

 private:
  virtual void beginJob() ;
  virtual void produce(edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data --------------------------
    
  edm::InputTag _inputProducer;
  edm::InputTag triggerEventTag_;
  edm::InputTag hltTag_;
  double delRMatchingCut_;
  std::string filterName_;
  bool storeRefCollection_;
  bool isFilter_;
  bool printIndex_;
  HLTConfigProvider hltConfig_;
};
#include "PhysicsTools/TagAndProbe//src/TriggerCandProducer.icc"
#endif
