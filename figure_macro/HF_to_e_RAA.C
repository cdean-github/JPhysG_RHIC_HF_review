#include "style.C"
#include "util.C"

//=====================
void HF_to_e_RAA(bool save_plot = true)
{
  string plotName = "HF_to_e_RAA";

  string axisTitles = ";p_{T} (GeV/c);R_{AA}";

  // ===== Set the style =====
  gROOT->ProcessLine("set_style()");

  // ===== Graph configuration =====
  vector<plot_info> plot_infos;

  //STAR Eur.Phys.J.C 82 (2022) 1150, 2022.  
  //c -> e
  vector<data_point> star_c_to_e_data;
  star_c_to_e_data.push_back({3.0, 2.5, 3.5, 0.57, 0.05, 0.04, 0.04});
  star_c_to_e_data.push_back({4.0, 3.5, 4.5, 0.29, 0.04, 0.02, 0.03});
  star_c_to_e_data.push_back({5.0, 4.5, 5.5, 0.31, 0.06, 0.06, 0.07});
  star_c_to_e_data.push_back({7.0, 5.5, 8.5, 0.27, 0.07, 0.09, 0.08});
  plot_infos.push_back(plot_info("STAR #it{c}#rightarrow #it{e}", yellow_color, 8, star_c_to_e_data));
  //b -> e
  vector<data_point> star_b_to_e_data;
  star_b_to_e_data.push_back({3.0, 2.5, 3.5, 1.01, 0.19, 0.12, 0.11});
  star_b_to_e_data.push_back({4.0, 3.5, 4.5, 0.54, 0.09, 0.05, 0.08});
  star_b_to_e_data.push_back({5.0, 4.5, 5.5, 0.59, 0.12, 0.10, 0.13});
  star_b_to_e_data.push_back({7.0, 5.5, 8.5, 0.47, 0.07, 0.09, 0.07});
  plot_infos.push_back(plot_info("STAR #it{b}#rightarrow #it{e}", red_color, 21, star_b_to_e_data));

  //PHENIX points
  TFile *fRaa = new TFile("rootInputs/PHENIXcbe.root");
  TGraphAsymmErrors *gRaa_ce = (TGraphAsymmErrors*) fRaa->Get("Raa_ce_cent0");
  TGraphAsymmErrors *gRaa_be = (TGraphAsymmErrors*) fRaa->Get("Raa_be_cent0");

  gRaa_ce->SetLineWidth(2.0);
  gRaa_ce->SetLineColor(kGreen+3);
  gRaa_ce->SetFillColorAlpha(kGreen+3, 0.15);
  gRaa_ce->SetLineStyle(9);
  gRaa_be->SetLineColor(kAzure-3);
  gRaa_be->SetMarkerColor(kAzure-3);
  gRaa_be->SetFillColorAlpha(kAzure-3, 0.15);
  gRaa_be->SetLineWidth(3.0);

  // ===== Draw histograms =====
   
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  canvas->cd();
  //canvas->SetLogy();

  auto multigraph = new TMultiGraph();

  TLegend *legend = new TLegend(0.55, 0.75, 0.9, 0.9);
  legend->SetBorderSize(0);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->SetTextSize(text_size);

  for (unsigned int i = 0; i < plot_infos.size(); ++i)
  {
    TGraphMultiErrors* myGraph = makeGraph(plot_infos[i]);
    multigraph->Add(myGraph);
    legend->AddEntry(myGraph, plot_infos[i].legend_info.c_str(), "P");
  }

  legend->AddEntry(gRaa_ce, "PHENIX #it{c}#rightarrow #it{e}", "L");
  legend->AddEntry(gRaa_be, "PHENIX #it{b}#rightarrow #it{e}", "L");

  multigraph->SetTitle(axisTitles.c_str());
  multigraph->GetYaxis()->SetRangeUser(0, 2.2);
  multigraph->Draw("APE1S ; E1 ; 5 s=0.1");

  gRaa_ce->Draw("L3");
  gRaa_be->Draw("L3");

  //Add line at y = 1
  TF1 *line = new TF1("line", "pol1", 0, 10);
  line->SetParameters(1, 0);
  line->SetLineColor(1);
  line->SetLineStyle(2);
  line->SetLineWidth(2);
  line->Draw("SAME");

  legend->Draw();

  TPaveText *pt;
  pt = new TPaveText(0.35,0.75,0.55,0.9, "NDC");
  pt->SetTextSize(text_size);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetTextFont(42);
  TText *pt_LaTex;
  pt_LaTex = pt->AddText("Au+Au, min. bias");
  pt_LaTex = pt->AddText("#sqrt{S_{NN}} = 200 GeV");
  pt->SetBorderSize(0);
  pt->Draw();
  gPad->Modified();

  if(save_plot)
  {
    string extensions[] = {".png", ".pdf"};
    for (auto extension : extensions)
    {
      string output = "plots/" + plotName + extension;
      canvas->SaveAs(output.c_str());
    }
  }
}
