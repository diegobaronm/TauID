// Analysis.py
// Skeleton code in python provided for you
// In place of this comment you should write [your name] -- [the date] and update it as you go!
// Make sure to make backups and comment as you go along :)

// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>

const int run2015Begin = 276262;
const int run2015End   = 284484;

const int run2016Begin = 297730;
const int run2016End   = 311481;

const int run2017Begin = 323427;
const int run2017End   = 341649;

const int run2018Begin = 341649;
const int run2018End   = 364292;


double del_phi(double phi_1, double phi_2){
    double pi=TMath::Pi();
    double phi_1_norm, phi_2_norm;
    if (phi_1<0.0){
        phi_1_norm=phi_1+2*pi;
    }else {
        phi_1_norm=phi_1;
    }

    if (phi_2<0.0){
        phi_2_norm=phi_2+2*pi;
    }else {
        phi_2_norm=phi_2;
    }
    double delta=std::abs(phi_1_norm-phi_2_norm);
    if (delta>pi){
        delta=2*pi-delta;
        delta=std::abs(delta);
    }

    return delta;
}


void CLoop::Book(double lumFactor) {
    double pi=TMath::Pi();
    if (lumFactor!=1)
    {
      h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco = new TH1F("tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt = new TH1F("tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt","Tau truth matched 1 prong",2,0,2);

      h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco = new TH1F("tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt = new TH1F("tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt","Tau truth matched 3 prong",2,0,2);

      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);


      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);


      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);

      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium = new TH1F("tau_matched_3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium","Systematic related yield",2,0,2);

      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco = new TH1F("tau_matched_1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection = new TH1F("tau_matched_1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection","Systematic related yield",2,0,2);
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco = new TH1F("tau_matched_1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection = new TH1F("tau_matched_1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection","Systematic related yield",2,0,2);

      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco = new TH1F("tau_matched_1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection = new TH1F("tau_matched_1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco = new TH1F("tau_matched_1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection = new TH1F("tau_matched_1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection","Systematic related yield",2,0,2);

      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco = new TH1F("tau_matched_3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection = new TH1F("tau_matched_3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection","Systematic related yield",2,0,2);
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco = new TH1F("tau_matched_3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection = new TH1F("tau_matched_3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection","Systematic related yield",2,0,2);

      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85 = new TH1F("tau_matched_3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT = new TH1F("tau_matched_3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco = new TH1F("tau_matched_3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection = new TH1F("tau_matched_3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco = new TH1F("tau_matched_3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco","Systematic related yield",2,0,2);
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection = new TH1F("tau_matched_3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection","Systematic related yield",2,0,2);
    }

    // Angular variable
    h_omega_topo = new TH1F("omega_topo","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi = new TH1F("omega_topo_dphi","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag = new TH1F("omega_topo_dphi_btag","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso = new TH1F("omega_topo_dphi_btag_iso","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn = new TH1F("omega_topo_dphi_btag_iso_rnn","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn_ptmu = new TH1F("omega_topo_dphi_btag_iso_rnn_ptmu","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega = new TH1F("omega_topo_dphi_btag_iso_rnn_ptmu_omega","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco = new TH1F("omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt = new TH1F("omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_btag_iso_rnn_ptmu_mreco_tpt = new TH1F("omega_topo_dphi_btag_iso_rnn_ptmu_mreco_tpt","omega variable",60,-3.0,3.0);

}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();
    if (n_muons==1 && n_taus_rnn_loose>=1 && weight > -190 && useEvent==1){
      //angles
      double angle_l_MET=del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(tau_0_p4->Phi(),muon_0_p4->Phi());

      bool trigger_decision= false;
      bool trigger_match= false;
      if (run_number>= 276262 && run_number<=284484) {
        trigger_decision= bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
        trigger_match=bool(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50);
      } else {
        trigger_decision= bool(HLT_mu26_ivarmedium | HLT_mu50);
        trigger_match=bool(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50);
      }
      bool lepton_id=muon_0_id_medium;

      float ql=muon_0_q;
      float qtau=tau_0_q;

      if (ql!=qtau && angle<13*pi/18 && trigger_decision && lepton_id && trigger_match ) {
        //topology
        bool inside= abs(angle-(angle_l_MET+angle_tau_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
        bool outside_lep= angle_l_MET<angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_l_MET)>0;
        bool outside_tau= angle_l_MET>angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_tau_MET)>0;
        bool signal_events = inside || outside_lep || outside_tau;

        if (signal_events){
          // RECO mass
          double cot_lep=1.0/tan(muon_0_p4->Phi());
          double cot_tau=1.0/tan(tau_0_p4->Phi());
          double pt_tau_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_lep)/(cos(tau_0_p4->Phi())-sin(tau_0_p4->Phi())*cot_lep);
          double pt_lep_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_tau)/(cos(muon_0_p4->Phi())-sin(muon_0_p4->Phi())*cot_tau);

          double reco_mass{};
          if(inside){
             reco_mass=sqrt(2*muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+2*muon_0_p4->Pt()*pt_tau_nu*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+2*tau_0_p4->Pt()*pt_lep_nu*(cosh(tau_0_p4->Eta()-muon_0_p4->Eta())-cos(tau_0_p4->Phi()-muon_0_p4->Phi()))+2*pt_lep_nu*pt_tau_nu*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi())));
          }

          double neutrino_pt=0;
          double reco_mass_outside=0;
          if (outside_lep) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
            reco_mass_outside=5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
          }
          if (outside_tau) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
            reco_mass_outside=5+sqrt(2*(muon_0_p4->Pt()*tau_0_p4->Pt()*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))+muon_0_p4->Pt()*neutrino_pt*(cosh(muon_0_p4->Eta()-tau_0_p4->Eta())-cos(muon_0_p4->Phi()-tau_0_p4->Phi()))));
          }

          double Z_pt_x=0;
          double Z_pt_y=0;
          double Z_pt=0;
          double r_jpt_zpt=0;
          double r_lpt_tpt=muon_0_p4->Pt()/tau_0_p4->Pt();
          double truth_z_pt=0.0;

          // truth ZpT definition
          if (z_sample==1 || z_sample==2)
          {
            truth_z_pt=truth_Z_p4->Pt()/1000;
          }

          if (inside) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+pt_tau_nu*cos(tau_0_p4->Phi())+pt_lep_nu*cos(muon_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+pt_tau_nu*sin(tau_0_p4->Phi())+pt_lep_nu*sin(muon_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
          }
          if (outside_tau) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+neutrino_pt*cos(tau_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+neutrino_pt*sin(tau_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
          }
          if (outside_lep) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi())+neutrino_pt*cos(muon_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi())+neutrino_pt*sin(muon_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
          }

          // ANGULAR VARIABLE DEFINITION
          double omega=0.0;
          if (inside && (angle_l_MET<angle_tau_MET)) {
            omega=1.0-(angle_l_MET)/(angle);
          }
          if (inside && (angle_l_MET>angle_tau_MET)) {
            omega=(angle_tau_MET)/(angle);
          }
          if (outside_lep) {
            omega=1.0+(angle_l_MET)/(angle);
          }
          if (outside_tau) {
            omega=-1.0*(angle_tau_MET)/(angle);
          }

          // Cuts bits
          vector<int> cuts={0,0,0,0,0,0,0,0};
          if (angle<=1.0){
            cuts[0]=1;
          }
          if (n_bjets_MV2c10_FixedCutBEff_85==0){
            cuts[1]=1;
          }
          if (muon_0_iso_TightTrackOnly_FixedRad==1) {
            cuts[2]=1;
          }
          if (tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans>0.4) {
            cuts[3]=1;
          }
          if (tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans>0.55) {
            cuts[3]=1;
          }
          if (muon_0_p4->Pt()>=27) {
            cuts[4]=1;
          }
          if (omega> -0.2 && omega <1.6) {
            cuts[5]=1;
          }
          if (inside) {
            if (reco_mass<120 && reco_mass>60) {
              cuts[6]=1;
            }
          }
          if (outside_lep) {
            if (reco_mass_outside<120 && reco_mass_outside>60) {
              cuts[6]=1;
            }
          }
          if (outside_tau) {
            if (reco_mass_outside<120 && reco_mass_outside>60) {
              cuts[6]=1;
          }
          }
          if (tau_0_p4->Pt()>=45){
            cuts[7]=1;
          }

          vector<int> c_all={1,1,1,1,1,1,1,1};
          vector<int> c_omega={1,1,1,1,1,0,1,1};

          if (cuts==c_omega||cuts==c_all) {
            h_omega_topo_dphi_btag_iso_rnn_ptmu_mreco_tpt->Fill(omega,weight);
          }

          h_omega_topo->Fill(omega,weight);
          // ANGLE CUT
          if (cuts[0]==1){
            h_omega_topo_dphi->Fill(omega,weight);

            // B TAGGING CUT
            if (cuts[1]==1 || n_jets==0) {

              h_omega_topo_dphi_btag->Fill(omega,weight);

              // ISOLATION CUT
              if (cuts[2]==1) {
                h_omega_topo_dphi_btag_iso->Fill(omega,weight);
                // RNN SCORE
                if (cuts[3]==1) {
                  h_omega_topo_dphi_btag_iso_rnn->Fill(omega,weight);
                  // TRANSVERSE MASS LEPTON CUT
                  if (cuts[4]==1) {
                    h_omega_topo_dphi_btag_iso_rnn_ptmu->Fill(omega,weight);
                      // OMEGA CUT
                    if (cuts[5]==1) {
                      h_omega_topo_dphi_btag_iso_rnn_ptmu_omega->Fill(omega,weight);
                        // RECO MASS CUT
                      if (cuts[6]==1) {

                        h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Fill(omega,weight);

                        if (weight!=1){
                          if (tau_0_n_charged_tracks==1){
                            h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Fill(tau_0_truth_isHadTau,weight);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                            h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                            h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                            h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                            h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                            h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                            h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                            h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                            h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                            h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                          }
                          if (tau_0_n_charged_tracks==3){
                            h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Fill(tau_0_truth_isHadTau,weight);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                            h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                            h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                            h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                            h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                            h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                            h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                            h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                            h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                            h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                            h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                          }
                        }
                        //TAU PT CUT
                        if (cuts[7]==1){
                          h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Fill(omega,weight);

                          if (weight!=1){
                            if (tau_0_n_charged_tracks==1){
                              h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                              h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                              h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                              h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                            }
                            if (tau_0_n_charged_tracks==3){
                              h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad/muon_0_NOMINAL_MuEffSF_IsoLoose_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad/muon_0_NOMINAL_MuEffSF_IsoTightTrackOnly_FixedRad);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium/muon_0_NOMINAL_MuEffSF_Reco_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA/muon_0_NOMINAL_MuEffSF_TTVA);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Fill(tau_0_truth_isHadTau,weight*muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium/muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_effSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Fill(tau_0_truth_isHadTau,weight*jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85/jet_NOMINAL_global_ineffSF_MV2c10_FixedCutBEff_85);
                              h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT/jet_NOMINAL_central_jets_global_effSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT/jet_NOMINAL_central_jets_global_ineffSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT/jet_NOMINAL_forward_jets_global_effSF_JVT);
                              h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Fill(tau_0_truth_isHadTau,weight*jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT/jet_NOMINAL_forward_jets_global_ineffSF_JVT);
                              h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                              h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Fill(tau_0_truth_isHadTau,weight*tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco/tau_0_NOMINAL_TauEffSF_reco);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

void CLoop::Style(double lumFactor) {


    if (lumFactor!=1){
      h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Write();
      h_tau_matched_1p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Write();

      h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Write();
      h_tau_matched_3p_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Write();

      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Write();
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection->Write();
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Write();
      h_tm1p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection->Write();

      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Write();
      h_tm1p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Write();
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Write();
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection->Write();
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Write();
      h_tm1p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection->Write();

      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Write();
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection->Write();
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Write();
      h_tm3p_cuts_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection->Write();

      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_STAT_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1down_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoLoose_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_ISO_SYS_1up_MuEffSF_IsoTightTrackOnly_FixedRad->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_STAT_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1down_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_RECO_SYS_LOWPT_1up_MuEffSF_Reco_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1down_MuEffSF_TTVA->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_STAT_1up_MuEffSF_TTVA->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1down_MuEffSF_TTVA->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TTVA_SYS_1up_MuEffSF_TTVA->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigStatUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1down_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_muon_0_MUON_EFF_TrigSystUncertainty_1up_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_B_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_C_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_0_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_1_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_2_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_Eigen_Light_3_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1down_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_effSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_FT_EFF_extrapolation_from_charm_1up_global_ineffSF_MV2c10_FixedCutBEff_85->Write();
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1down_central_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_JvtEfficiency_1up_central_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1down_forward_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_effSF_JVT->Write();
      h_tm3p_cuts_tpt_jet_JET_fJvtEfficiency_1up_forward_jets_global_ineffSF_JVT->Write();
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_reco->Write();
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1down_TauEffSF_selection->Write();
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_reco->Write();
      h_tm3p_cuts_tpt_tau_0_TAUS_TRUEHADTAU_EFF_RECO_TOTAL_1up_TauEffSF_selection->Write();
    }

    h_omega_topo->Write();
    h_omega_topo_dphi->Write();
    h_omega_topo_dphi_btag->Write();
    h_omega_topo_dphi_btag_iso->Write();
    h_omega_topo_dphi_btag_iso_rnn->Write();
    h_omega_topo_dphi_btag_iso_rnn_ptmu->Write();
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega->Write();
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco->Write();
    h_omega_topo_dphi_btag_iso_rnn_ptmu_omega_mreco_tpt->Write();
    h_omega_topo_dphi_btag_iso_rnn_ptmu_mreco_tpt->Write();

}

#endif // End header guard