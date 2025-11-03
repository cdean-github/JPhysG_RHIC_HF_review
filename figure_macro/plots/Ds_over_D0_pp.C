#ifdef __CLING__
#pragma cling optimize(0)
#endif
void Ds_over_D0_pp()
{
//=========Macro generated from canvas: canvas/
//=========  (Mon Nov  3 18:37:31 2025) by ROOT version 6.32.06
   TCanvas *canvas = new TCanvas("canvas", "",0,0,800,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvas->Range(-0.9094936,0.07889027,8.837342,0.2757011);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetTickx(1);
   canvas->SetTicky(1);
   canvas->SetLeftMargin(0.16);
   canvas->SetRightMargin(0.05);
   canvas->SetBottomMargin(0.16);
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle(";p_{T} (GeV/c);D_{s}^{#pm}/D^{0}");
   
   TGraphMultiErrors* tgme = new TGraphMultiErrors(6, 2);
   tgme->GetAttFill(0)->SetFillColor(19);
   tgme->GetAttLine(0)->SetLineColor(2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = 1179;
   color = new TColor(ci, 1, 0, 0, " ", 0.2);
   tgme->GetAttFill(1)->SetFillColor(ci);
   tgme->GetAttLine(1)->SetLineColor(2);
   tgme->SetPoint(0, 1.5, 0.15);
   tgme->SetPointEX(0, 0.5, 0.5);
   tgme->SetPointEY(0, 0, 0.033, 0.033);
   tgme->SetPointEY(0, 1, 0.0205, 0.0205);
   tgme->SetPoint(1, 2.5, 0.1668);
   tgme->SetPointEX(1, 0.5, 0.5);
   tgme->SetPointEY(1, 0, 0.0142, 0.0142);
   tgme->SetPointEY(1, 1, 0.0102, 0.0103);
   tgme->SetPoint(2, 3.5, 0.1842);
   tgme->SetPointEX(2, 0.5, 0.5);
   tgme->SetPointEY(2, 0, 0.0111, 0.0111);
   tgme->SetPointEY(2, 1, 0.0094, 0.0093);
   tgme->SetPoint(3, 4.5, 0.1981);
   tgme->SetPointEX(3, 0.5, 0.5);
   tgme->SetPointEY(3, 0, 0.0103, 0.0103);
   tgme->SetPointEY(3, 1, 0.0102, 0.01);
   tgme->SetPoint(4, 5.5, 0.2083);
   tgme->SetPointEX(4, 0.5, 0.5);
   tgme->SetPointEY(4, 0, 0.0112, 0.0112);
   tgme->SetPointEY(4, 1, 0.011, 0.0108);
   tgme->SetPoint(5, 7, 0.237);
   tgme->SetPointEX(5, 1, 1);
   tgme->SetPointEY(5, 0, 0.0101, 0.0101);
   tgme->SetPointEY(5, 1, 0.0125, 0.0124);
   tgme->SetName("");
   tgme->SetTitle("");
   tgme->SetFillStyle(1000);
   tgme->SetLineColor(2);
   tgme->SetMarkerColor(2);
   tgme->SetMarkerStyle(8);
   
   TH1F *Graph_Graph5001 = new TH1F("Graph_Graph5001","",100,0.3,8.7);
   Graph_Graph5001->SetMinimum(0.10376);
   Graph_Graph5001->SetMaximum(0.26264);
   Graph_Graph5001->SetDirectory(nullptr);
   Graph_Graph5001->SetStats(0);
   Graph_Graph5001->GetXaxis()->SetLabelFont(42);
   Graph_Graph5001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph5001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph5001->GetXaxis()->SetTitleOffset(1.4);
   Graph_Graph5001->GetXaxis()->SetTitleFont(42);
   Graph_Graph5001->GetYaxis()->SetLabelFont(42);
   Graph_Graph5001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph5001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph5001->GetYaxis()->SetTitleOffset(1.4);
   Graph_Graph5001->GetYaxis()->SetTitleFont(42);
   Graph_Graph5001->GetZaxis()->SetLabelFont(42);
   Graph_Graph5001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph5001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph5001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph5001->GetZaxis()->SetTitleFont(42);
   tgme->SetHistogram(Graph_Graph5001);
   
   multigraph->Add(tgme,"");
   multigraph->Draw("APE1S ; E1 ; 5 s=0.1");
   multigraph->GetXaxis()->SetLimits(0.65, 8.35);
   multigraph->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.05);
   multigraph->GetXaxis()->SetTitleSize(0.05);
   multigraph->GetXaxis()->SetTitleOffset(1.4);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("D_{s}^{#pm}/D^{0}");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.05);
   multigraph->GetYaxis()->SetTitleSize(0.05);
   multigraph->GetYaxis()->SetTitleOffset(1.4);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.55,0.2,0.9,0.35,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("","ALICE, 13 TeV #it{p+p}","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(8);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.25,0.75,0.55,0.92,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->SetTextSize(0.04);
   TText *pt_LaTex = pt->AddText("#bf{#it{sPHENIX}} Projection");
   pt->Draw();
   canvas->Modified();
   canvas->SetSelected(canvas);
}
