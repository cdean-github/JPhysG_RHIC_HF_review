#include "style.C"


//=====================
void plots(bool save_plot = true)
{
  // ===== Set the style =====
  gROOT->ProcessLine("set_style()");

  // ===== Histogram configuration =====
  const int nBins = 40;
  const double xMin = 10;
  const double xMax = 150;

  TH1F* hist_data = new TH1F("hist_data", "", nBins, xMin, xMax);
  TH1F* hist_mc   = new TH1F("hist_mc",   "", nBins, xMin, xMax);

  // ===== Independent RNGs for statistical difference =====
  TRandom3 rand_data(0);         // Data
  TRandom3 rand_mc(12345);       // MC

  // ===== Fill histograms =====
  for (int i = 0; i < 1e5; ++i)
    {
      hist_data->Fill(rand_data.Landau(40, 10));
      hist_mc->Fill(rand_mc.Landau(41.0, 10)); // Slight shift
    }

  // ===== Draw histograms =====
   
   TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
   canvas -> SetTitle("Plot leading ejet");
   canvas -> cd();
   canvas -> SetLogy();

   hist_data -> Sumw2();
   hist_data -> SetTitle(";p_{T} (GeV/c);N_{evts}");
   hist_data -> SetLineColor(kBlack);
   hist_data -> SetMaximum(1.e5);
   hist_data -> SetMinimum(1.e2);
   hist_data -> Draw("");

   hist_mc -> SetLineColor(kRed);
   hist_mc -> Draw("hist same");
    
   TLegend *legend = new TLegend(0.65, 0.72, 0.9, 0.9);
   legend -> AddEntry(hist_data,"RHIC data", "P");
   legend -> AddEntry(hist_mc,"Simulation", "L");
   legend -> Draw();

   TLatex Text_com;
   Text_com.SetTextAlign(13);  //align at top
   Text_com.DrawLatexNDC(.15,.9,"p+p, #sqrt{s} = 200 GeV");

   if(save_plot)
     {
       canvas -> SaveAs("example_plot.pdf");
     }
}
