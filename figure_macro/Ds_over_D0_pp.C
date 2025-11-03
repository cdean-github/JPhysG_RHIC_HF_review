#include "style.C"
#include "util.C"

//=====================
void Ds_over_D0_pp(bool save_plot = true)
{
  string plotName = "Ds_over_D0_pp";

  string axisTitles = ";p_{T} (GeV/c);D_{s}^{#pm}/D^{0}";

  // ===== Set the style =====
  //gROOT->ProcessLine("set_style()");

  // ===== Graph configuration =====
  vector<plot_info> plot_infos;

  //ALICE JHEP 12 (2023) 086, 2023. 
  vector<data_point> alice_data;
  alice_data.push_back({1.5, 1, 2, 0.15, 0.033, 0.0205, 0.0205});
  alice_data.push_back({2.5, 2, 3, 0.1668, 0.0142, 0.0102, 0.0103});
  alice_data.push_back({3.5, 3, 4, 0.1842, 0.0111, 0.0094, 0.0093});
  alice_data.push_back({4.5, 4, 5, 0.1981, 0.0103, 0.0102, 0.01});
  alice_data.push_back({5.5, 5, 6, 0.2083, 0.0112, 0.011, 0.0108});
  alice_data.push_back({7.0, 6, 8, 0.237, 0.0101, 0.0125, 0.0124});
  plot_infos.push_back(plot_info("ALICE, 13 TeV #it{p+p}", red_color, 8, alice_data));

  // ===== Draw histograms =====
   
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  canvas->cd();
  //canvas->SetLogy();

  auto multigraph = new TMultiGraph();

  TLegend *legend = new TLegend(0.55, 0.20, 0.9, 0.35);
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

  //multigraph->GetYaxis()->SetRangeUser(0.2, 0.7);
  multigraph->SetTitle(axisTitles.c_str());
  multigraph->Draw("APE1S ; E1 ; 5 s=0.1");

  legend->Draw();

  TPaveText *pt;
  pt = new TPaveText(0.25,0.75,0.55,0.92, "NDC");
  pt->SetTextSize(text_size);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetTextFont(42);
  TText *pt_LaTex;
  pt_LaTex = pt->AddText("#bf{#it{sPHENIX}} Projection");
  //pt_LaTex = pt->AddText("#sqrt{s} = 200 GeV");
  pt->SetBorderSize(0);
  pt->Draw();
  gPad->Modified();

  if(save_plot)
  {
    string extensions[] = {".png", ".pdf", ".C"};
    for (auto extension : extensions)
    {
      string output = "plots/" + plotName + extension;
      canvas->SaveAs(output.c_str());
    }
  }
}
