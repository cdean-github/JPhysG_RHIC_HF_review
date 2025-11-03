#include "style.C"
#include "util.C"

//=====================
void Upsilon_RAA(bool save_plot = true)
{
  string plotName = "Upsilon_RAA";

  string axisTitles = ";Centrality;R_{AA}";

  // ===== Set the style =====
  gROOT->ProcessLine("set_style()");

  // ===== Graph configuration =====
  vector<plot_info> plot_infos;

  //STAR Phys. Lett. B 735 (2014) 127 
  //dAu, min-bias covers what centrality?
  vector<data_point> star_dAu_2014;
  star_dAu_2014.push_back({50, 0, 100, 0.79, sqrt(pow(0.14, 2) + pow(0.10, 2)), sqrt(pow(0.03, 2) + pow(0.09, 2)), sqrt(pow(0.03, 2) + pow(0.09, 2))});
  plot_infos.push_back(plot_info("STAR #it{d}+Au, #Upsilon(1S), |y| < 1, min. bias", red_color, 8, star_dAu_2014));

  //PHENIX Phys. Rev. C 91, 024913 (2015)
  //AuAu
  vector<data_point> phenix_AuAu_2015;
  phenix_AuAu_2015.push_back({15,  0, 30, 0.50, 0.18, 0.11, 0.11});
  phenix_AuAu_2015.push_back({61, 30, 92, 0.84, 0.47, 0.18, 0.18});
  plot_infos.push_back(plot_info("PHENIX Au+Au, #Upsilon(1S+2S+3S), |y| < 0.35", orange_color, 21, phenix_AuAu_2015));

  //STAR Phys.Rev.Lett. 130 (2023) 112301, 2023 
  //AuAu 1S
  vector<data_point> star_AuAu_1S_2023;
  star_AuAu_1S_2023.push_back({ 5,  0, 10, 0.36, 0.06, 0.05, 0.05});
  star_AuAu_1S_2023.push_back({20, 10, 30, 0.36, 0.05, 0.03, 0.03});
  star_AuAu_1S_2023.push_back({45, 30, 60, 0.56, 0.07, 0.10, 0.10});
  plot_infos.push_back(plot_info("STAR Au+Au, #Upsilon(1S), |y| < 1", cyan_color, 29, star_AuAu_1S_2023));

  //STAR Phys.Rev.Lett. 130 (2023) 112301, 2023 
  //AuAu 2S
  vector<data_point> star_AuAu_2S_2023;
  star_AuAu_2S_2023.push_back({ 5,  0, 10, 0.09, 0.14, 0.02, 0.02});
  star_AuAu_2S_2023.push_back({20, 10, 30, 0.26, 0.11, 0.03, 0.03});
  star_AuAu_2S_2023.push_back({45, 30, 60, 0.48, 0.16, 0.09, 0.09});
  plot_infos.push_back(plot_info("STAR Au+Au, #Upsilon(2S), |y| < 1", blue_color, 33, star_AuAu_2S_2023));

  //STAR Phys.Rev.Lett. 130 (2023) 112301, 2023 
  //AuAu 3S
  vector<data_point> star_AuAu_3S_2023;
  star_AuAu_3S_2023.push_back({30,  0, 60, 0, 0.17, 0, 0});
  plot_infos.push_back(plot_info("STAR Au+Au, #Upsilon(3S), |y| < 1", indigo_color, 34, star_AuAu_3S_2023));

  //STAR Phys. Rev. C 94, 064904 (2016)
  //UU 1S
  vector<data_point> star_UU_1S_2016;
  star_UU_1S_2016.push_back({ 5,  0, 10, 0.49, 0.23, 0.10, 0.12});
  star_UU_1S_2016.push_back({20, 10, 30, 0.63, 0.24, 0.11, 0.17});
  star_UU_1S_2016.push_back({45, 30, 60, 2.76, 0.76, 0.95, 0.71});
  plot_infos.push_back(plot_info("STAR U+U, #Upsilon(1S), |y| < 1", yellow_color, 22, star_UU_1S_2016));

  //STAR Phys. Rev. C 94, 064904 (2016)
  //UU 2S + 3S
  vector<data_point> star_UU_2S_3S_2016;
  star_UU_2S_3S_2016.push_back({ 5,  0, 10, 0.56, 0.89, 0.12, 0.15});
  star_UU_2S_3S_2016.push_back({20, 10, 30, 0.41, 0.55, 0.07, 0.15});
  star_UU_2S_3S_2016.push_back({30,  0, 60, 0.48, 0.32, 0.11, 0.07});
  plot_infos.push_back(plot_info("STAR U+U, #Upsilon(2S+3S), |y| < 1", green_color, 23, star_UU_2S_3S_2016));

  // ===== Draw histograms =====
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  canvas->cd();

  auto multigraph = new TMultiGraph();

  TLegend *legend = new TLegend(0.15, 0.55, 0.9, 0.9);
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

  multigraph->SetTitle(axisTitles.c_str());
  multigraph->GetYaxis()->SetRangeUser(0, 3.2);
  multigraph->Draw("APE1S ; E1 ; 5 s=0.1");
  
  makeLine(0, 100);

  legend->Draw();

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
