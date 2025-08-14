#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TAxis.h>
#include <TString.h>

void LumiPlot() {
    // Create canvas
    TCanvas* c = new TCanvas("c", "Custom X-axis Labels", 600, 600);

    gPad->SetTickx(1);
    gPad->SetTicky(1);

    // X values (can be 0, 1, 2 if you just want indices)
    double x[] = {0, 1, 2};
    double y[] = {8.24, 8.24*0.884*1.02, 8.21};
    double ex[] = {0.0, 0.0, 0.0};  // No x errors
    double ey[] = {8.24*0.05, 8.24*0.884*0.0623*1.02, 0.42}; // y errors

    // Create graph with errors
    TGraphErrors* graph = new TGraphErrors(3, x, y, ex, ey);
    graph->GetYaxis()->CenterTitle();
    graph->SetMarkerStyle(20);
    graph->SetTitle("; ;OO Luminosity (nb^{-1})");

    graph->GetYaxis()->SetRangeUser(6,9);

    graph->Draw("AP");

    // Set custom labels
    TAxis* xAxis = graph->GetXaxis();
    xAxis->SetLimits(-0.5, 2.5); // Range around x = 0,1,2
    xAxis->SetNdivisions(3, false); // Number of labels

    // Set bin labels
    xAxis->Set(3, -0.5, 2.5);
    xAxis->SetBinLabel(1, "BRIL");
    xAxis->SetBinLabel(2, "Evt. Counting");
    xAxis->SetBinLabel(3, "Z Counting");

    c->Update();

    TF1* constantFit = new TF1("constantFit", "[0]", 0, 2);
    graph->Fit(constantFit, "Q");
    constantFit->Draw("same");

    double chi2 = constantFit->GetChisquare();  // total chi-squared
    int ndf     = constantFit->GetNDF();   
    std::cout << chi2 << " " << ndf << " " << chi2/ndf << " " << TMath::Prob(chi2, ndf) << std::endl;

    TLatex latex;
    latex.DrawLatex(0.3, 6.5, Form("#chi^{2}/ndf = %.2f;  p=%.2f",chi2/ndf,TMath::Prob(chi2, ndf)));
    latex.DrawLatex(0.3, 6.2, "5.36 TeV OO");

}

