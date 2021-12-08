// Header guard to ensure file is imported properly
#ifndef Analysis
#define Analysis

// Include the file that lets the program know about the data
#include "backend/CLoop.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#include <utility>


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

    // inv histos
    h_inv_mass_topo = new TH1F("inv_mass_topo","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi = new TH1F("inv_mass_topo_dphi","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag = new TH1F("h_inv_mass_topo_dphi_btag","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso = new TH1F("h_inv_mass_topo_dphi_btag_iso","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1 = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2 = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl","Invariant mass",300,0,300);
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl = new TH1F("h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl","Invariant mass",300,0,300);

    h_ratio_lpt_tpt_cuts = new TH1F("ratio_lpt_tpt_cuts","ratio_lpt_tpt",40,0,4);
    h_ratio_lpt_tpt_cuts_ptl = new TH1F("ratio_lpt_tpt_cuts_ptl","ratio_lpt_tpt",40,0,4);
}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();
    if (n_muons==2 && useEvent==1){
      //angles
      double angle_l_MET=del_phi(muon_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(muon_1_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(muon_1_p4->Phi(),muon_0_p4->Phi());

      bool trigger_decision = false;
      bool trigger_match = false;
      bool trigger_match_1 = false;
      bool trigger_match_2 = false;
      bool trigger_match_12 = false;
      if (run_number>= 276262 && run_number<=284484) {
        trigger_decision = bool(HLT_mu20_iloose_L1MU15 | HLT_mu50);
        trigger_match_1 = bool((muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && !(muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        trigger_match_2 = bool(!(muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        trigger_match_12 = bool((muTrigMatch_0_HLT_mu20_iloose_L1MU15 | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu20_iloose_L1MU15 | muTrigMatch_1_HLT_mu50));
        if(weight!=1){
          if (trigger_match_1){weight=weight*muon_0_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}
          if (trigger_match_2){weight=weight*muon_1_NOMINAL_MuEffSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_QualMedium;}
        }
        trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
      } else {
        trigger_decision = bool(HLT_mu26_ivarmedium | HLT_mu50);
        trigger_match_1 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && !(muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        trigger_match_2 = bool(!(muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        trigger_match_12 = bool((muTrigMatch_0_HLT_mu26_ivarmedium | muTrigMatch_0_HLT_mu50) && (muTrigMatch_1_HLT_mu26_ivarmedium | muTrigMatch_1_HLT_mu50));
        if(weight!=1){
          if (trigger_match_1){weight=weight*muon_0_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}
          if (trigger_match_2){weight=weight*muon_1_NOMINAL_MuEffSF_HLT_mu26_ivarmedium_OR_HLT_mu50_QualMedium;}
        }
        trigger_match= trigger_match_1 | trigger_match_2 | trigger_match_12;
      }

      bool muon_id=muon_0_id_medium && muon_1_id_medium;

      float q_mu0=muon_0_q;
      float q_mu1=muon_1_q;

      if (q_mu0!=q_mu1 && angle<3*pi/4 && trigger_decision && muon_id && trigger_match ) {

        double inv_mass{};
        inv_mass=sqrt(2*muon_0_p4->Pt()*muon_1_p4->Pt()*(cosh(muon_0_p4->Eta()-muon_1_p4->Eta())-cos(muon_0_p4->Phi()-muon_1_p4->Phi())));

        double Z_pt_x=0;
        double Z_pt_y=0;
        double Z_pt=0;
        double r_jpt_zpt=0;
        double r_lpt_tpt=muon_0_p4->Pt()/muon_1_p4->Pt();
        double truth_z_pt=0.0;

        if (z_sample==1 || z_sample==2)
        {
          truth_z_pt=truth_Z_p4->Pt()/1000;
        }

        Z_pt_x=muon_1_p4->Pt()*cos(muon_1_p4->Phi())+muon_0_p4->Pt()*cos(muon_0_p4->Phi());
        Z_pt_y=muon_1_p4->Pt()*sin(muon_1_p4->Phi())+muon_0_p4->Pt()*sin(muon_0_p4->Phi());
        Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
        if (z_sample==0){
            truth_z_pt=Z_pt;
        }
        r_jpt_zpt=ljet_0_p4->Pt()/Z_pt;

        // Cuts bits
        vector<int> cuts={0,0,0,0,0,0,0};

        double a{50},b{47};

        if (angle<=1.0){
          cuts[0]=1;
        }
        if (n_bjets_MV2c10_FixedCutBEff_85==0){
          cuts[1]=1;
        }
        if (muon_0_iso_TightTrackOnly_FixedRad==1 && muon_1_iso_TightTrackOnly_FixedRad==1) {
          cuts[2]=1;
        }
        if (muon_0_p4->Pt()>=a) {
          cuts[3]=1;
        }
        if (muon_1_p4->Pt()>=b) {
          cuts[4]=1;
        }
        if (inv_mass<110 && inv_mass>70) {
          cuts[5]=1;
        }
        if(event_number%2==0){
          if(muon_1_p4->Pt()>=(b+30)){
            cuts[6]=1;
          }
        } else{
          if(muon_0_p4->Pt()>=(a+30)){
            cuts[6]=1;
          }
        }

        h_inv_mass_topo->Fill(inv_mass,weight);

        // ANGLE CUT
        if (cuts[0]==1){
          h_inv_mass_topo_dphi->Fill(inv_mass,weight);

          // B TAGGING CUT
          if (cuts[1]==1 || n_jets==0) {
            h_inv_mass_topo_dphi_btag->Fill(inv_mass,weight);

            // ISOLATION CUT
            if (cuts[2]==1) {
              h_inv_mass_topo_dphi_btag_iso->Fill(inv_mass,weight);

              // pT 1 CUT
              if (cuts[3]==1) {
                h_inv_mass_topo_dphi_btag_iso_pt1->Fill(inv_mass,weight);

                // pT 2 CUT
                if (cuts[4]==1) {
                  h_inv_mass_topo_dphi_btag_iso_pt1_pt2->Fill(inv_mass,weight);

                    // INV MASS CUT
                  if (cuts[5]==1) {
                    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass->Fill(inv_mass,weight);

                    h_ratio_lpt_tpt_cuts->Fill(r_lpt_tpt,weight);

                    if(cuts[6]==1){
                      h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Fill(inv_mass,weight);

                      h_ratio_lpt_tpt_cuts_ptl->Fill(r_lpt_tpt,weight);
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
    // inv histos
    h_inv_mass_topo->Write();
    h_inv_mass_topo_dphi->Write();
    h_inv_mass_topo_dphi_btag->Write();
    h_inv_mass_topo_dphi_btag_iso->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_mass_ptl->Write();
    h_inv_mass_topo_dphi_btag_iso_pt1_pt2_ptl->Write();

    h_ratio_lpt_tpt_cuts->Write();
    h_ratio_lpt_tpt_cuts_ptl->Write();
}

#endif // End header guard
