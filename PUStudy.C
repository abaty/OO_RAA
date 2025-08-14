#include "TH1D.h"
#include "TGraphErrors.h"
#include "TFile.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TGraphErrors.h"
#include <utility>


std::pair<double, double> PUStudy(double ptStudied = 3.0){
  const int n = 8;
  const int m = 13;
  //const int m = 26;
  const int o = 11;
  const int p = 12;
  const int p668 = 7;
  const int p669 = 4;
  const int p670 = 7;
  const int p711 = 7;
  const int p590 = 7;
  const int p695 = 7;
  const int p716 = 6;
  int hlow[n] = {8,108,208,308,408,508,608,708};
  int hhigh[n] = {108,208,308,408,508,608,708,908};
  int h2low[m] = {15,215,415,615,815,1015,1215,1415,1615,1815,2015,2215,2415};
  int h2high[m] = {215,415,615,815,1015,1215,1415,1615,1815,2015,2215,2415,2615};
  //int h2low[m] = {1,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500};
  //int h2high[m] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600};
  int h3low[o] =  {1,  200,400,600,800, 1000,1200,1400,1800,2000,2200};
  int h3high[o] = {200,400,600,800,1000,1200,1400,1800,2000,2200,2400};
  int h4low[p] = {1,200,400,600,800,1000,1200,1400,1800,2000,2200,2400};
  int h4high[p] = {200,400,600,800,1000,1200,1400,1800,2000,2200,2400,2600};
  int h668low[p668] = {1,100,200,300,400,500,600};
  int h668high[p668] = {100,200,300,400,500,600,700};
  int h669low[p669] = {1,100,200,300};
  int h669high[p669] = {100,200,300,400};
  int h670low[p670] = {1,100,200,300,400,500,600};
  int h670high[p670] = {100,200,300,400,500,600,700};
  int h711low[p711] = {1,100,200,300,400,500,600};
  int h711high[p711] = {100,200,300,400,500,600,700};
  int h590low[p590] = {1,100,200,300,400,500,600};
  int h590high[p590] = {100,200,300,400,500,600,700};
  int h695low[p695] = {1,100,200,300,400,500,600};
  int h695high[p695] = {100,200,300,400,500,600,700};
  int h716low[p716] = {1,100,200,300,400,500};
  int h716high[p716] = {100,200,300,400,500,600};
  //do run 387721 folowed by 387640
  double PU[n] = {7.439,6.749,6.215,5.785,5.410,5.081,4.792,4.439};
  double PU2[m] = {7.243,6.158,5.395,4.819,4.366,3.967,3.618,3.318,3.053,2.814,2.610,2.459,2.340};
  //double PU2[m] = {7.623,6.98,6.43,5.99,5.65,5.27,4.98,4.73,4.48,4.25,4.05,3.87,3.71,3.56,3.42,3.29,3.15,3.03,2.95,2.8,2.7,2.6,2.50,2.4,2.30,2.21};
  double PU3[o] = {6.389, 5.516, 4.913, 4.426, 4.026, 3.686, 3.387, (3.132+2.904)/2.0, 2.706, 2.531, 2.383};
  double PU4[p] = {4.253, 3.851, 3.512, 3.208, 2.953, 2.768, 2.575, (2.409+2.273)/2.0, 2.159, 2.065, 1.989, 1.916};
  double PU668[p668] = {7.374,6.689,6.149,5.697,5.326,4.995,4.699};
  double PU669[p669] = {4.299,4.075, 3.869, 3.683};
  double PU670[p670] = {3.413, 3.269, 3.13, 3, 2.885, 2.776, 2.675};
  double PU711[p711] = {6.2,5.74,5.359,5.061,4.777,4.509,4.272};
  double PU590[p590] = {7.241, 6.474, 5.91, 5.462, 5.094, 4.781, 4.51};
  double PU695[p695] = {7.419, 6.739, 6.192, 5.747, 5.375, 5.05, 4.767};
  double PU716[p716] = {2.848, 2.744, 2.645, 2.55, 2.465, 2.389};

  TFile * f = TFile::Open("pp_PU_histograms_387721.root");
  TH1D * h[n];
  for(int i = 0; i<n; i++){
    h[i] = (TH1D*) f->Get(Form("hratio_LS_%d_%d",hlow[i],hhigh[i]));
  }

  TFile * f2 = TFile::Open("pp_PU_histograms_387640.root");
  TH1D * h2[m];
  for(int i = 0; i<m; i++){
    h2[i] = (TH1D*) f2->Get(Form("hratio_LS_%d_%d",h2low[i],h2high[i]));
    h2[i]->Print("All");
  }

  TFile * f3 = TFile::Open("pp_PU_histograms_387607.root");
  TH1D * h3[o];
  for(int i = 0; i<o; i++){
    h3[i] = (TH1D*) f3->Get(Form("hratio_LS_%d_%d",h3low[i],h3high[i]));
  }

  TFile * f4 = TFile::Open("pp_PU_histograms_387696.root");
  TH1D * h4[p];
  for(int i = 0; i<p; i++){
    h4[i] = (TH1D*) f4->Get(Form("hratio_LS_%d_%d",h4low[i],h4high[i]));
  }

  TFile * f668 = TFile::Open("pp_PU_histograms_387668.root");
  TH1D * h668[p668];
  for(int i = 0; i<p668; i++){
    h668[i] = (TH1D*) f668->Get(Form("hratio_LS_%d_%d",h668low[i],h668high[i]));
  }
  TFile * f669 = TFile::Open("pp_PU_histograms_387669.root");
  TH1D * h669[p669];
  for(int i = 0; i<p669; i++){
    h669[i] = (TH1D*) f669->Get(Form("hratio_LS_%d_%d",h669low[i],h669high[i]));
  }
  TFile * f670 = TFile::Open("pp_PU_histograms_387670.root");
  TH1D * h670[p670];
  for(int i = 0; i<p670; i++){
    h670[i] = (TH1D*) f670->Get(Form("hratio_LS_%d_%d",h670low[i],h670high[i]));
  }
  TFile * f711 = TFile::Open("pp_PU_histograms_387711.root");
  TH1D * h711[p711];
  for(int i = 0; i<p711; i++){
    h711[i] = (TH1D*) f711->Get(Form("hratio_LS_%d_%d",h711low[i],h711high[i]));
  }
  TFile * f590 = TFile::Open("pp_PU_histograms_387590.root");
  TH1D * h590[p590];
  for(int i = 0; i<p590; i++){
    h590[i] = (TH1D*) f590->Get(Form("hratio_LS_%d_%d",h590low[i],h590high[i]));
  }

  TFile * f695 = TFile::Open("pp_PU_histograms_387695.root");
  TH1D * h695[p695];
  for(int i = 0; i<p695; i++){
    h695[i] = (TH1D*) f695->Get(Form("hratio_LS_%d_%d",h695low[i],h695high[i]));
  }

  TFile * f716 = TFile::Open("pp_PU_histograms_387716.root");
  TH1D * h716[p716];
  for(int i = 0; i<p716; i++){
    h716[i] = (TH1D*) f716->Get(Form("hratio_LS_%d_%d",h716low[i],h716high[i]));
  }

  TFile * lowPUF = TFile::Open("LowPU_pp.root");
  TH1D * lowPU = (TH1D*) lowPUF->Get("hinvyieldlowPUpp");

  TFile * lowPU2F = TFile::Open("pp_PU_histograms_387522.root");
  TH1D * lowPU2 = (TH1D*) lowPU2F->Get("hratio_LS_1_700");

  int b = h[0]->FindBin(ptStudied);

  TGraphErrors *gr = new TGraphErrors(n+m+o+p+p668+p669+p670+p711+p590+p695+p716+2);
  //do first run
  for (int i = 0; i < n; i++) {
      gr->SetPoint(i, PU[i], h[i]->GetBinContent(b));
      gr->SetPointError(i, 0, h[i]->GetBinError(b));
  }
  //do second run
  for (int i = 0; i < m-2; i++) {
      gr->SetPoint(n+i, PU2[i], h2[i]->GetBinContent(b));
      gr->SetPointError(n+i, 0, h2[i]->GetBinError(b));
  }

  //do third run
  for (int i = 0; i < o; i++) {
      gr->SetPoint(n+m+i, PU3[i], h3[i]->GetBinContent(b));
      gr->SetPointError(n+m+i, 0, h3[i]->GetBinError(b));
  }

  //do third run
  for (int i = 0; i < p; i++) {
      gr->SetPoint(n+m+o+i, PU4[i], h4[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+i, 0, h4[i]->GetBinError(b));
  }

  for (int i = 0; i < p668; i++) {
      gr->SetPoint(n+m+o+p+i, PU668[i], h668[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i, 0, h668[i]->GetBinError(b));
  }
  for (int i = 0; i < p669; i++) {
      gr->SetPoint(n+m+o+p+i+p668, PU669[i], h669[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i, 0, h669[i]->GetBinError(b));
  }
  for (int i = 0; i < p670; i++) {
      gr->SetPoint(n+m+o+p+i+p668+p669, PU670[i], h670[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i+p668+p669, 0, h670[i]->GetBinError(b));
  }  
  for (int i = 0; i < p711; i++) {
      gr->SetPoint(n+m+o+p+i+p668+p669+p670, PU711[i], h711[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i+p668+p669+p670, 0, h711[i]->GetBinError(b));
  }
  for (int i = 0; i < p590; i++) {
      gr->SetPoint(n+m+o+p+i+p668+p669+p670+p711, PU590[i], h590[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i+p668+p669+p670+p711, 0, h590[i]->GetBinError(b));
  }
  for (int i = 0; i < p695; i++) {
      gr->SetPoint(n+m+o+p+i+p668+p669+p670+p711+p590, PU695[i], h695[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i+p668+p669+p670+p711+p590, 0, h695[i]->GetBinError(b));
  }

  for (int i = 0; i < p716; i++) {
      gr->SetPoint(n+m+o+p+i+p668+p669+p670+p711+p590+p695, PU716[i], h716[i]->GetBinContent(b));
      gr->SetPointError(n+m+o+p+i+p668+p669+p670+p711+p590+p695, 0, h716[i]->GetBinError(b));
  }

  //add low PU point
  gr->SetPoint(n+m+o+p+p668+p669+p670+p711+p590+p695+p716, 1.0, lowPU->GetBinContent(lowPU->FindBin(ptStudied)));
  gr->SetPointError(n+m+o+p+p668+p669+p670+p711+p590+p695+p716, 0, lowPU->GetBinError(lowPU->FindBin(ptStudied)));
  //6.39 scale factor calculated as lumi ratio for 1-700 vs 1-100 (fixing lumi error when calculating normalization)
  gr->SetPoint(n+m+o+p+p668+p669+p670+p711+p590+p695+p716+1, 1.5, lowPU2->GetBinContent(lowPU2->FindBin(ptStudied)));
  gr->SetPointError(n+m+o+p+p668+p669+p670+p711+p590+p695+p716+1, 0, lowPU2->GetBinError(lowPU2->FindBin(ptStudied)));


  //just second run (just for cosmetics)
  TGraphErrors *gr2 = new TGraphErrors(m);
  for (int i = 0; i < m-2; i++) {
      gr2->SetPoint(n+i, PU2[i], h2[i]->GetBinContent(b));
      gr2->SetPointError(n+i, 0, h2[i]->GetBinError(b));
  }
  gr2->SetMarkerColor(kGray);
  gr2->SetLineColor(kGray);
  gr2->SetMarkerStyle(20);

  //just third run (just for cosmetics)
  TGraphErrors *gr3 = new TGraphErrors(o);
  for (int i = 0; i < o; i++) {
      gr3->SetPoint(i, PU3[i], h3[i]->GetBinContent(b));
      gr3->SetPointError(i, 0, h3[i]->GetBinError(b));
  }
  gr3->SetMarkerColor(kGreen+1);
  gr3->SetLineColor(kGreen+1);
  gr3->SetMarkerStyle(20);
  
  //just third run (just for cosmetics)
  TGraphErrors *gr4 = new TGraphErrors(p+p695);
  for (int i = 0; i < p; i++) {
      gr4->SetPoint(i, PU4[i], h4[i]->GetBinContent(b));
      gr4->SetPointError(i, 0, h4[i]->GetBinError(b));
  }
  for (int i = 0; i < p; i++) {
      gr4->SetPoint(p+i, PU695[i], h695[i]->GetBinContent(b));
      gr4->SetPointError(p+i, 0, h695[i]->GetBinError(b));
  }
  gr4->SetMarkerColor(kViolet);
  gr4->SetLineColor(kViolet+1);
  gr4->SetMarkerStyle(20);

  //just fourth run (just for cosmetics)
  TGraphErrors *gr5 = new TGraphErrors(p668+p669+p670);
  for (int i = 0; i < p668; i++) {
      gr5->SetPoint(i, PU668[i], h668[i]->GetBinContent(b));
      gr5->SetPointError(i, 0, h668[i]->GetBinError(b));
  }
  for (int i = 0; i < p669; i++) {
      gr5->SetPoint(i+p668, PU669[i], h669[i]->GetBinContent(b));
      gr5->SetPointError(i+p668, 0, h669[i]->GetBinError(b));
  }
  for (int i = 0; i < p670; i++) {
      gr5->SetPoint(i+p668+p669, PU670[i], h670[i]->GetBinContent(b));
      gr5->SetPointError(i+p668+p669, 0, h670[i]->GetBinError(b));
  }
  gr5->SetMarkerColor(kBlue);
  gr5->SetLineColor(kBlue);
  gr5->SetMarkerStyle(20);

  TGraphErrors *gr6 = new TGraphErrors(p711);
  for (int i = 0; i < p711; i++) {
      gr6->SetPoint(i, PU711[i], h711[i]->GetBinContent(b));
      gr6->SetPointError(i, 0, h711[i]->GetBinError(b));
  }
  gr6->SetMarkerColor(kPink-5);
  gr6->SetLineColor(kPink-5);
  gr6->SetMarkerStyle(20);

  TGraphErrors *gr7 = new TGraphErrors(p590);
  for (int i = 0; i < p590; i++) {
      gr7->SetPoint(i, PU590[i], h590[i]->GetBinContent(b));
      gr7->SetPointError(i, 0, h590[i]->GetBinError(b));
  }
  gr7->SetMarkerColor(kOrange);
  gr7->SetLineColor(kOrange);
  gr7->SetMarkerStyle(20);

  TGraphErrors *gr8 = new TGraphErrors(p716);
  for (int i = 0; i < p716; i++) {
      gr8->SetPoint(i, PU716[i], h716[i]->GetBinContent(b));
      gr8->SetPointError(i, 0, h716[i]->GetBinError(b));
  }
  gr8->SetMarkerColor(kYellow+2);
  gr8->SetLineColor(kYellow+2);
  gr8->SetMarkerStyle(20);

  //low-pu point graph
  TGraphErrors *grLow = new TGraphErrors(1);
  grLow->SetPoint(0, 1.0, lowPU->GetBinContent(lowPU->FindBin(ptStudied)));
  grLow->SetPointError(0, 0, lowPU->GetBinError(lowPU->FindBin(ptStudied)));
  grLow->SetMarkerColor(kAzure+10);
  grLow->SetLineColor(kAzure+10);
  grLow->SetMarkerStyle(20);

  TGraphErrors *grLow2 = new TGraphErrors(1);
  grLow2->SetPoint(0, 1.5, lowPU2->GetBinContent(lowPU2->FindBin(ptStudied)));
  grLow2->SetPointError(0, 0, lowPU2->GetBinError(lowPU2->FindBin(ptStudied)));
  grLow2->SetMarkerColor(kOrange+1);
  grLow2->SetLineColor(kOrange+1);
  grLow2->SetMarkerStyle(20);
  grLow2->Print("All");

  //inclusive point
  TGraphErrors *grInc = new TGraphErrors(1);
  grInc->SetPoint(n, 4.694, 1);
  grInc->SetPointError(n, 0, 0);
  grInc->SetMarkerColor(kRed);
  grInc->SetLineColor(kRed);
  grInc->SetMarkerStyle(47);

  gr->SetTitle(";average #mu ;Ratio To Nominal");
  gr->SetMarkerStyle(20);
  gr->GetXaxis()->SetRangeUser(0,8);

  TCanvas * c1 = new TCanvas("c1","c1",600,600);
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
  c1->SetTopMargin(0.05);
  c1->SetBottomMargin(0.15);

  TH1D * dummy = new TH1D("d",";#LT #mu #GT;Ratio to Nominal",2,0,8);
  dummy->Draw();
  dummy->SetStats(0);
  //dummy->GetYaxis()->SetRangeUser(0.97,1.03);
  //dummy->GetYaxis()->SetRangeUser(0.9,1.25);
  dummy->GetYaxis()->SetRangeUser(0.9,1.2);
  dummy->GetYaxis()->CenterTitle();
  dummy->GetXaxis()->CenterTitle();

  TF1 *fitFcn = new TF1("fitFcn", "[0]+[1]*x", 0, 8); // range can be adjusted

  // Fit
  TFitResultPtr r = gr->Fit(fitFcn, "RS"); // "R" = restrict to TF1 range
  //Band
  // Band points
    const int nPoints = 500;
    double xv[nPoints];
    double ci[nPoints]; // confidence intervals (errors)
    double ymin[nPoints], ymax[nPoints];
    double xmin = 0, xmax = 8;
    for (int i = 0; i < nPoints; i++) {
        xv[i] = xmin + (xmax - xmin) * i / (nPoints - 1);
    }
    // ROOT 6.30 API: needs n, strides, x-array, ci-array
    r->GetConfidenceIntervals(nPoints, 1, 1, xv, ci, 0.68);
    // Build band graph
    TGraphErrors *band = new TGraphErrors(nPoints);
    for (int i = 0; i < nPoints; i++) {
        double yfit = fitFcn->Eval(xv[i]);
        band->SetPoint(i, xv[i], yfit);
        band->SetPointError(i, 0, ci[i]);
    }
    band->SetFillColorAlpha(kRed, 0.3);
    band->SetLineColor(kRed);

  // Print results
  double slope = fitFcn->GetParameter(1);
  double intercept = fitFcn->GetParameter(0);
  printf("Intercept = %f\n", intercept);
  printf("Slope     = %f\n", slope);
  printf("Chi2/ndf  = %f\n", r->Chi2() / r->Ndf());

  std::cout << fitFcn->Eval(4.7) << std::endl;


  band->Draw("3 same");
  gr->Draw("P same");
  grLow->Draw("P same");
  gr3->Draw("P same");
  gr4->Draw("P same");
  gr5->Draw("P same");
  gr6->Draw("P same");
  gr7->Draw("P same");
  gr8->Draw("P same");
  grLow2->Draw("P same");
  grInc->Draw("P same");
  gr2->Draw("P same");

  TLegend * l = new TLegend(0.15,0.7,0.95,0.95);
  l->AddEntry((TObject*)0,Form("p_{T} = %.1f GeV",ptStudied),"");
  l->SetNColumns(2);
  l->AddEntry(grLow2,"Run 387522","pl");
  l->AddEntry(grLow,"Run 387570 (leveled)","pl");
  l->AddEntry(gr7,"Run 387590","pl");
  l->AddEntry(gr3,"Run 387607","pl");
  l->AddEntry(gr2,"Run 387640","pl");
  l->AddEntry(gr5,"Fill 10309","pl");
  l->AddEntry(gr4,"Fill 10310","pl");
  l->AddEntry(gr6,"Run 387711","pl");
  l->AddEntry(gr8,"Run 387716","pl");
  l->AddEntry(gr,"Run 387721","pl");

  l->AddEntry(grInc,"Nominal Result","pl");
  l->Draw("same");

  c1->SaveAs(Form("plots/pileupDependence%.0f.png",ptStudied*100));
  c1->SaveAs(Form("plots/pileupDependence%.0f.pdf",ptStudied*100));

  gr->Print("All");

  const double* errors = r->GetErrors();
  return  std::pair(intercept, errors[0]);

}

void scanPU(){

  double xvals[] = {
    2.9, 3.1, 3.3, 3.5, 3.7, 3.9, 4.2, 4.6, 5.0, 5.4,
    5.8, 6.2, 6.6, 7.0, 7.4, 7.8, 8.25, 8.75, 9.25, 9.75,
    10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5,
    20.5,21.8, 23.6, 25.6, 27.6, 30.6, 34.6, 39.6,};

  TGraphErrors *summary = new TGraphErrors(35);

  for(int i = 0; i<38; i++){
    std::pair<double, double> out = PUStudy((xvals[i]+xvals[i+1])/2.0);
    std::cout << out.first << " " << out.second << std::endl;
    summary->SetPoint(i,xvals[i],out.first);
    summary->SetPointError(i,0,out.second);
  }
  summary->Print("All");
  TCanvas * c2 = new TCanvas("c2","c2",600,600);
  c2->SetLeftMargin(0.15);
  c2->SetRightMargin(0.05);
  c2->SetTopMargin(0.05);
  c2->SetBottomMargin(0.15);
  c2->SetLogx();
  summary->SetTitle("");
  summary->GetYaxis()->SetRangeUser(0.9,1.1);
  summary->SetMarkerStyle(20);
  summary->GetXaxis()->SetTitle("p_{T}");
  summary->GetXaxis()->CenterTitle();
  summary->GetXaxis()->SetTitleOffset(1.15);
  summary->GetYaxis()->SetTitle("Intercept at #mu=0");
  summary->GetYaxis()->CenterTitle();
  summary->Draw("AP");
}


