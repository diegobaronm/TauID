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



    if (lumFactor!=1)
    {
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Tau truth matched 1 prong",2,0,2);
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("tau_matched_1p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Tau truth matched 1 prong",2,0,2);

      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","Tau truth matched 3 prong",2,0,2);
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("tau_matched_3p_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","Tau truth matched 3 prong",2,0,2);

    }
    // Angular variable
    h_omega_topo = new TH1F("omega_topo","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi = new TH1F("omega_topo_dphi","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte = new TH1F("omega_topo_dphi_bdte","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag = new TH1F("omega_topo_dphi_bdte_btag","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso = new TH1F("omega_topo_dphi_bdte_btag_iso","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt","omega variable",60,-3.0,3.0);
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt = new TH1F("omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt","omega variable",60,-3.0,3.0);

}

void CLoop::Fill(double weight, int z_sample) {
    double pi=TMath::Pi();

    if (n_electrons==1 && n_taus_rnn_loose>=1 && useEvent==1){
      //angles
      double angle_l_MET=del_phi(elec_0_p4->Phi(),met_reco_p4->Phi());
      double angle_tau_MET=del_phi(tau_0_p4->Phi(),met_reco_p4->Phi());
      double angle=del_phi(tau_0_p4->Phi(),elec_0_p4->Phi());

      bool trigger_decision= false;
      bool trigger_match= false;
      if (run_number>= 276262 && run_number<=284484){
          trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e24_lhmedium_L1EM20VH | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
          trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e24_lhmedium_L1EM20VH | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
      } else {
          trigger_decision=bool(HLT_e120_lhloose | HLT_e140_lhloose_nod0 | HLT_e26_lhtight_nod0_ivarloose | HLT_e60_lhmedium | HLT_e60_lhmedium_nod0);
          trigger_match=bool(eleTrigMatch_0_HLT_e120_lhloose | eleTrigMatch_0_HLT_e140_lhloose_nod0 | eleTrigMatch_0_HLT_e26_lhtight_nod0_ivarloose | eleTrigMatch_0_HLT_e60_lhmedium | eleTrigMatch_0_HLT_e60_lhmedium_nod0);
      }
      bool lepton_id=elec_0_id_tight;

      float ql=elec_0_q;
      float qtau=tau_0_q;

      if (ql!=qtau && angle<3*pi/4 && trigger_decision && lepton_id && trigger_match) {

        //topology
        bool inside= abs(angle-(angle_l_MET+angle_tau_MET))< 0.00001; //ANGLE BEING USED pi/2 AND 2.0943
        bool outside_lep= angle_l_MET<angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_l_MET)>0;
        bool outside_tau= angle_l_MET>angle_tau_MET && abs(angle-(angle_l_MET+angle_tau_MET)) > 0.00001 && cos(angle_tau_MET)>0;
        bool signal_events = inside || outside_lep || outside_tau;

        if (signal_events){
          // RECO mass
          double cot_lep=1.0/tan(elec_0_p4->Phi());
          double cot_tau=1.0/tan(tau_0_p4->Phi());
          double pt_tau_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_lep)/(cos(tau_0_p4->Phi())-sin(tau_0_p4->Phi())*cot_lep);
          double pt_lep_nu=(met_reco_p4->Pt()*cos(met_reco_p4->Phi())-met_reco_p4->Pt()*sin(met_reco_p4->Phi())*cot_tau)/(cos(elec_0_p4->Phi())-sin(elec_0_p4->Phi())*cot_tau);

          double reco_mass{};
          if(inside){
            reco_mass=sqrt(2*elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+2*elec_0_p4->Pt()*pt_tau_nu*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+2*tau_0_p4->Pt()*pt_lep_nu*(cosh(tau_0_p4->Eta()-elec_0_p4->Eta())-cos(tau_0_p4->Phi()-elec_0_p4->Phi()))+2*pt_lep_nu*pt_tau_nu*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi())));
          }

          double neutrino_pt=0;
          double reco_mass_outside=0;
          if (outside_lep) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_l_MET);
            reco_mass_outside=5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+tau_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
          }
          if (outside_tau) {
            neutrino_pt=met_reco_p4->Pt()*cos(angle_tau_MET);
            reco_mass_outside=5+sqrt(2*(elec_0_p4->Pt()*tau_0_p4->Pt()*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))+elec_0_p4->Pt()*neutrino_pt*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi()))));
          }

          double inv_taulep=sqrt((2*elec_0_p4->Pt()*tau_0_p4->Pt())*(cosh(elec_0_p4->Eta()-tau_0_p4->Eta())-cos(elec_0_p4->Phi()-tau_0_p4->Phi())));

          double Z_pt_x=0;
          double Z_pt_y=0;
          double Z_pt=0;
          double r_jpt_zpt=0;
          double r_lpt_tpt=elec_0_p4->Pt()/tau_0_p4->Pt();
          double truth_z_pt=0.0;
          if (z_sample==1 || z_sample==2)
          {
            truth_z_pt=truth_Z_p4->Pt()/1000;
          }
          if (inside) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+pt_tau_nu*cos(tau_0_p4->Phi())+pt_lep_nu*cos(elec_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+pt_tau_nu*sin(tau_0_p4->Phi())+pt_lep_nu*sin(elec_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
          }
          if (outside_tau) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(tau_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(tau_0_p4->Phi());
            Z_pt=sqrt(Z_pt_x*Z_pt_x+Z_pt_y*Z_pt_y);
            if (z_sample==0){
              truth_z_pt=Z_pt;
            }
          }
          if (outside_lep) {
            Z_pt_x=tau_0_p4->Pt()*cos(tau_0_p4->Phi())+elec_0_p4->Pt()*cos(elec_0_p4->Phi())+neutrino_pt*cos(elec_0_p4->Phi());
            Z_pt_y=tau_0_p4->Pt()*sin(tau_0_p4->Phi())+elec_0_p4->Pt()*sin(elec_0_p4->Phi())+neutrino_pt*sin(elec_0_p4->Phi());
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
          vector<int> cuts={0,0,0,0,0,0,0,0,0,0};
          if (angle<=1.0){
            cuts[0]=1;
          }
          if (tau_0_ele_bdt_score_trans_retuned>=0.05) {
            cuts[1]=1;
          }
          if (n_bjets_MV2c10_FixedCutBEff_85==0){
            cuts[2]=1;
          }
          if (elec_0_iso_FCTight==1) {
            cuts[3]=1;
          }
          if (tau_0_n_charged_tracks==1 && tau_0_jet_rnn_score_trans>0.4) {
            cuts[4]=1;
          }
          if (tau_0_n_charged_tracks==3 && tau_0_jet_rnn_score_trans>0.55) {
            cuts[4]=1;
          }
          if (elec_0_p4->Pt()>=27) {
            cuts[5]=1;
          }
          if (omega>-0.2 && omega <1.6) {
            cuts[6]=1;
          }
          if (inv_taulep < 80) {
            cuts[7]=1;
          }
          if (inside) {
            if (reco_mass<120 && reco_mass>60) {
              cuts[8]=1;
            }
          }
          if (outside_lep) {
            if (reco_mass_outside<120 && reco_mass_outside>60) {
              cuts[8]=1;
            }
          }
          if (outside_tau) {
            if (reco_mass_outside<120 && reco_mass_outside>60) {
              cuts[8]=1;
            }
          }
          if (tau_0_p4->Pt()>=45){
              cuts[9]=1;
          }

          vector<int> c_omega={1,1,1,1,1,1,0,1,1,1};
          vector<int> c_all={1,1,1,1,1,1,1,1,1,1};

          if (cuts==c_omega||cuts==c_all) {
            h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt->Fill(omega,weight);
          }

          h_omega_topo->Fill(omega,weight);

          // ANGLE CUT
          if (cuts[0]==1){
            h_omega_topo_dphi->Fill(omega,weight);

          // TAU ELECTRON BDT SCORE
          if (cuts[1]==1) {
            h_omega_topo_dphi_bdte->Fill(omega,weight);

            // B TAGGING CUT
            if (cuts[2]==1 || n_jets==0) {;
              h_omega_topo_dphi_bdte_btag->Fill(omega,weight);

              // ISOLATION CUT
              if (cuts[3]==1) {
                h_omega_topo_dphi_bdte_btag_iso->Fill(omega,weight);

                // RNN SCORE
                if (cuts[4]==1) {
                  h_omega_topo_dphi_bdte_btag_iso_rnn->Fill(omega,weight);

                  // TRANSVERSE MASS LEPTON CUT
                  if (cuts[5]==1) {
                    h_omega_topo_dphi_bdte_btag_iso_rnn_pte->Fill(omega,weight);


                      // OMEGA CUT
                    if (cuts[6]==1) {
                      h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega->Fill(omega,weight);

                        // INVA MASS LEPTON TAU CUT
                      if (cuts[7]==1) {
                        h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Fill(omega,weight);

                        // RECO MASS CUT
                        if (cuts[8]==1) {
                          h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(omega,weight);

                          if (weight!=1){
                            if (tau_0_n_charged_tracks==1){
                              h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_truth_isHadTau,weight);
                            }
                            if (tau_0_n_charged_tracks==3){
                              h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Fill(tau_0_truth_isHadTau,weight);
                            }
                          }

                          //TAU PT CUT
                          if (cuts[9]==1) {
                            h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(omega,weight);

                            if (weight!=1){
                              if (tau_0_n_charged_tracks==1){
                                h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
                              }
                              if (tau_0_n_charged_tracks==3){
                                h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Fill(tau_0_truth_isHadTau,weight);
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
  }
}

void CLoop::Style(double lumFactor) {

    if (lumFactor!=1){
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
      h_tau_matched_1p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();

      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
      h_tau_matched_3p_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    }

    h_omega_topo->Write();
    h_omega_topo_dphi->Write();
    h_omega_topo_dphi_bdte->Write();
    h_omega_topo_dphi_bdte_btag->Write();
    h_omega_topo_dphi_bdte_btag_iso->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_omega_mle_mreco_tpt->Write();
    h_omega_topo_dphi_bdte_btag_iso_rnn_pte_mle_mreco_tpt->Write();

}


#endif // End header guard
