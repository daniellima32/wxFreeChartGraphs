/////////////////////////////////////////////////////////////////////////////
// Name:    combinedaxisdemos.cpp
// Purpose: This file contains source code, that demonstrates how to
//          combined axis charts.
// Author:    Moskvichev Andrey V.
// Created:    2009/04/03
// Copyright:    (c) 2009 Moskvichev Andrey V.
// Licence:    wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include "democollection.h"

#include <wx/xy/xyplot.h>
#include <wx/xy/xylinerenderer.h>
#include <wx/xy/xyhistorenderer.h>
#include <wx/xy/xysimpledataset.h>
#include <wx/axismultiplot.h>
#include <wx/multiplot.h>
#include <wx/category/categorysimpledataset.h>
#include <wx/bars/barplot.h>
#include <wx/axis/categoryaxis.h>

/**
 * Combined axis demo.
 */
class CombinedAxisDemo1 : public ChartDemo
{
public:
    CombinedAxisDemo1()
    : ChartDemo(wxT("Combined axis Demo 1 - left axis"))
    {
    }

    virtual Chart *Create()
    {
        // first plot data
        double data1[][2] = {
                { 10, 20, },
                { 13, 16, },
                { 7, 30, },
                { 15, 34, },
                { 25, 4, },
        };
        // second plot data
        double data2[][2] = {
                { 45, 40, },
                { 23, 16, },
                { 43, 60, },
                { 25, 7, },
                { 66, 4, },
        };

        MultiPlot *multiPlot = new MultiPlot(1, 0, 5, 5);

        // create left axis, that will be shared between two plots
        NumberAxis *sharedLeftAxis = new NumberAxis(AXIS_LEFT);

        // create first plot
        XYPlot *plot1 = new XYPlot();

        // create dataset
        XYSimpleDataset *dataset1 = new XYSimpleDataset();

        // and add serie to it
        dataset1->AddSerie((double *) data1, WXSIZEOF(data1));

        // set line renderer to dataset
        dataset1->SetRenderer(new XYLineRenderer());

        // add our dataset to plot
        plot1->AddDataset(dataset1);

        // create axis share for first plot to share leftAxis between plots
        AxisShare *leftAxis1 = new AxisShare(sharedLeftAxis);
        // and make it visible for first plot
        leftAxis1->SetShareVisible(true);

        // create bottom number axes
        NumberAxis *bottomAxis1 = new NumberAxis(AXIS_BOTTOM);
        bottomAxis1->SetVerticalLabelText(true);
        bottomAxis1->SetMargins(10, 15);

        // add axes to plot
        plot1->AddAxis(leftAxis1);
        plot1->AddAxis(bottomAxis1);

        // link axes and dataset
        plot1->LinkDataVerticalAxis(0, 0);
        plot1->LinkDataHorizontalAxis(0, 0);

        //
        // create second plot
        //
        XYPlot *plot2 = new XYPlot();

        // create dataset
        XYSimpleDataset *dataset2 = new XYSimpleDataset();

        // and add serie to it
        dataset2->AddSerie((double *) data2, WXSIZEOF(data2));

        // set line renderer to dataset
        dataset2->SetRenderer(new XYLineRenderer());

        // add our dataset to plot
        plot2->AddDataset(dataset2);

        // create axis share for second plot to share leftAxis between plots
        // by default it will be invisible
        AxisShare *leftAxis2 = new AxisShare(sharedLeftAxis);

        // create bottom number axes
        NumberAxis *bottomAxis2 = new NumberAxis(AXIS_BOTTOM);
        bottomAxis2->SetMargins(15, 10);
        bottomAxis2->SetVerticalLabelText(true);

        // add axes to plot
        plot2->AddAxis(leftAxis2);
        plot2->AddAxis(bottomAxis2);

        // link axes and dataset
        plot2->LinkDataVerticalAxis(0, 0);
        plot2->LinkDataHorizontalAxis(0, 0);

        // add first plot to multiplot
        multiPlot->AddPlot(plot1);

        // add second plot to multiplot
        multiPlot->AddPlot(plot2);

        // and finally create chart
        return new Chart(multiPlot, GetName());
    }
};

class CombinedAxisDemo2 : public ChartDemo
{
public:
    CombinedAxisDemo2()
    : ChartDemo(wxT("Combined axis Demo 2 - bottom axis"))
    {
    }

    virtual Chart *Create()
    {
        // first plot data
        double data1[][2] = {
                { 10, 20, },
                { 43, 16, },
                { 17, 30, },
                { 65, 34, },
                { 25, 4, },
        };
        // second plot data
        double data2[][2] = {
                { 45, 40, },
                { 23, 16, },
                { 35, 60, },
                { 15, 7, },
                { 5, 20 },
                { 66, 4, },
        };

		AxisMultiPlot *multiPlot = new AxisMultiPlot();

		

        // create left axis, that will be shared between two plots
        NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM);

        // create first plot
        XYPlot *plot1 = new XYPlot();

        // create dataset
        XYSimpleDataset *dataset1 = new XYSimpleDataset();

        // and add serie to it
        dataset1->AddSerie((double *) data1, WXSIZEOF(data1));

        // set line renderer to dataset
        dataset1->SetRenderer(new XYLineRenderer());

        // add our dataset to plot
        plot1->AddDataset(dataset1);

        // create left number axes
        NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT, true);
		//NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT);

		AxisShare *leftAxis1Shared = new AxisShare(leftAxis1);
		leftAxis1Shared->SetShareVisible(true);

        // create axis share for second plot to share leftAxis between plots
        // by default it will be invisible
        AxisShare *bottomAxis1 = new AxisShare(bottomAxis);

		//AxisShare *bottomAxis1Shared = new AxisShare(bottomAxis1);
		bottomAxis1->SetShareVisible(true);

        // add axes to plot
        plot1->AddAxis(leftAxis1);
        plot1->AddAxis(bottomAxis1);

        // link axes and dataset
        plot1->LinkDataVerticalAxis(0, 0);
        plot1->LinkDataHorizontalAxis(0, 0);

        //
        // create second plot
        //
        XYPlot *plot2 = new XYPlot();

        // create dataset
        XYSimpleDataset *dataset2 = new XYSimpleDataset();

        // and add serie to it
        dataset2->AddSerie((double *) data2, WXSIZEOF(data2));

        // set histogram renderer to dataset
        XYHistoRenderer *renderer2 = new XYHistoRenderer();
        renderer2->SetBarArea(0, new FillAreaDraw(*wxBLACK, *wxGREEN));

        dataset2->SetRenderer(renderer2);

        // add our dataset to plot
        plot2->AddDataset(dataset2);

        // create left number axes
        NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT, true); //fica invertido
		//NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT);

        // create axis share for second plot to share leftAxis between plots
        AxisShare *bottomAxis2 = new AxisShare(bottomAxis);
        // and make it visible for second plot
        bottomAxis2->SetShareVisible(true);

        // add axes to plot
        plot2->AddAxis(leftAxis2);
        plot2->AddAxis(bottomAxis2);

        // link axes and dataset
        plot2->LinkDataVerticalAxis(0, 0);
        plot2->LinkDataHorizontalAxis(0, 0);

        // add first plot to multiplot
        multiPlot->addPlot(plot1);

        // add second plot to multiplot
        multiPlot->addPlot(plot2);

		multiPlot->AddAxis(leftAxis1Shared);
		multiPlot->AddAxis(bottomAxis1);

		multiPlot->AddAxis(leftAxis2);  //this
		multiPlot->AddAxis(bottomAxis2); //this
		

        // and finally create chart
        return new Chart(multiPlot, GetName());
    }
};

//Exemplo apenas com barras invertidas
class CombinedAxisDemo3 : public ChartDemo
{
public:
	CombinedAxisDemo3()
		: ChartDemo(wxT("Combined axis Demo 2 - bottom axis"))
	{
	}

	virtual Chart *Create()
	{
		wxString names[] = { // category names
			wxT("Cat 1"),
			wxT("Cat 2"),
			wxT("Cat 3"),
			wxT("Cat 4"),
			wxT("Cat 5"),
		};

		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			14.0,
			12.0,
		};

		// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30); //Deve dizer se inverte ou não aqui
		barType->setOriented(true);

		// Set bar renderer for it
		BarRenderer *br1 = new BarRenderer(barType, true);

		dataset->SetRenderer(br1);
		//br1->SetSerieColour(0, &color1); //do not work with bar

		//BarRenderer *br2 = new BarRenderer(barType2);


		//dataset2->SetRenderer(br2);
		//br2->SetSerieColour(0, &color2); //do not work with bar

		// Why doesn't SetSerieColour work for bars?
		br1->SetBarDraw(0, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#007F7F"))));
		//br2->SetBarDraw(1, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#EA4B32"))));

		// Create bar plot
		BarPlot *plot = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		leftAxis->SetMargins(5, 0);
		plot->AddAxis(leftAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM, true);
		bottomAxis->SetMargins(20, 20);
		plot->AddAxis(bottomAxis);

		NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT);
		rightAxis->SetMargins(5, 0);
		plot->AddAxis(rightAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *topAxis = new CategoryAxis(AXIS_TOP);
		topAxis->SetMargins(20, 20);
		plot->AddAxis(topAxis);

		// Add dataset to plot
		plot->AddDataset(dataset);
		//plot->AddDataset(dataset2);

		plot->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		//novo
		//plot->LinkDataHorizontalAxis(1, 1);

		// Link first dataset with vertical axis
		plot->LinkDataVerticalAxis(0, 0);

		//novo
		//plot->LinkDataVerticalAxis(1, 1);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot->SetLegend(legend);

		// Create a custom title.
		TextElement title(GetName());

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		// add second plot to multiplot
		multiPlot->addPlot(plot);

		multiPlot->AddAxis(leftAxis);
		multiPlot->AddAxis(bottomAxis);

		// and finally create chart
		return new Chart(multiPlot, GetName());
	}
};

//Exemplo apenas com barras invertidas
class CombinedAxisDemo4 : public ChartDemo
{
public:
	CombinedAxisDemo4()
		: ChartDemo(wxT("example with bar and line"))
	{
	}

	virtual Chart *Create()
	{
		wxString names[] = { // category names
			wxT("Cat 1"),
			wxT("Cat 2"),
			wxT("Cat 3"),
			wxT("Cat 4"),
			wxT("Cat 5"),
		};

		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			14.0,
			12.0,
		};

		// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30); //Deve dizer se inverte ou não aqui
		barType->setOriented(true);

		// Set bar renderer for it
		BarRenderer *br1 = new BarRenderer(barType, true);

		dataset->SetRenderer(br1);
		//br1->SetSerieColour(0, &color1); //do not work with bar

		//BarRenderer *br2 = new BarRenderer(barType2);


		//dataset2->SetRenderer(br2);
		//br2->SetSerieColour(0, &color2); //do not work with bar

		// Why doesn't SetSerieColour work for bars?
		br1->SetBarDraw(0, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#007F7F"))));
		//br2->SetBarDraw(1, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#EA4B32"))));

		// Create bar plot
		BarPlot *plot1 = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		leftAxis->SetMargins(5, 0);
		plot1->AddAxis(leftAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM, true);
		bottomAxis->SetMargins(20, 20);
		plot1->AddAxis(bottomAxis);

		NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT);
		rightAxis->SetMargins(5, 0);
		plot1->AddAxis(rightAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *topAxis = new CategoryAxis(AXIS_TOP);
		topAxis->SetMargins(20, 20);
		plot1->AddAxis(topAxis);

		// Add dataset to plot
		plot1->AddDataset(dataset);
		//plot->AddDataset(dataset2);

		plot1->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot1->LinkDataHorizontalAxis(0, 0);

		//novo
		//plot->LinkDataHorizontalAxis(1, 1);

		// Link first dataset with vertical axis
		plot1->LinkDataVerticalAxis(0, 0);

		//novo
		//plot->LinkDataVerticalAxis(1, 1);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot1->SetLegend(legend);

		// Create a custom title.
		TextElement title(GetName());

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		// add second plot to multiplot
		multiPlot->addPlot(plot1);

		multiPlot->AddAxis(leftAxis);
		multiPlot->AddAxis(bottomAxis);

		// The beginning of the first graph

		// first plot data
		double data1[][2] = {
			{ 10, 20, },
			{ 43, 16, },
			{ 17, 30, },
			{ 65, 34, },
			{ 25, 4, },
		};

		// create first plot
		XYPlot *plot2 = new XYPlot();

		// create dataset
		XYSimpleDataset *dataset1 = new XYSimpleDataset();

		// and add serie to it
		dataset1->AddSerie((double *)data1, WXSIZEOF(data1));

		// set line renderer to dataset
		dataset1->SetRenderer(new XYLineRenderer());

		// add our dataset to plot
		plot2->AddDataset(dataset1);

		// create left number axes
		NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT, true);
		//NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT);

		AxisShare *leftAxis1Shared = new AxisShare(leftAxis1);
		leftAxis1Shared->SetShareVisible(true);

		// create left axis, that will be shared between two plots
		NumberAxis *bottomAxisN = new NumberAxis(AXIS_BOTTOM);

		// create axis share for second plot to share leftAxis between plots
		// by default it will be invisible
		AxisShare *bottomAxis1 = new AxisShare(bottomAxisN);

		//AxisShare *bottomAxis1Shared = new AxisShare(bottomAxis1);
		bottomAxis1->SetShareVisible(true);

		// add axes to plot
		plot2->AddAxis(leftAxis1);
		plot2->AddAxis(bottomAxis1);

		// link axes and dataset
		plot2->LinkDataVerticalAxis(0, 0);
		plot2->LinkDataHorizontalAxis(0, 0);

		// add first plot to multiplot
		multiPlot->addPlot(plot2);

		multiPlot->AddAxis(leftAxis1Shared);
		multiPlot->AddAxis(bottomAxis1);

		//The end of the second graph

		// and finally create chart
		return new Chart(multiPlot, GetName());
	}
};

//Exemplo apenas com barras invertidas
class CombinedAxisDemo5 : public ChartDemo
{
public:
	CombinedAxisDemo5()
		: ChartDemo(wxT("example with bar and line"))
	{
	}

	virtual Chart *Create()
	{
		wxString names[] = { // category names
			wxT("Cat 1"),
			wxT("Cat 2"),
			wxT("Cat 3"),
			wxT("Cat 4"),
			wxT("Cat 5"),
		};

		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			14.0,
			12.0,
		};

		// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30); //Deve dizer se inverte ou não aqui
		barType->setOriented(true);

		// Set bar renderer for it
		BarRenderer *br1 = new BarRenderer(barType, true);

		dataset->SetRenderer(br1);
		//br1->SetSerieColour(0, &color1); //do not work with bar

		//BarRenderer *br2 = new BarRenderer(barType2);


		//dataset2->SetRenderer(br2);
		//br2->SetSerieColour(0, &color2); //do not work with bar

		// Why doesn't SetSerieColour work for bars?
		br1->SetBarDraw(0, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#007F7F"))));
		//br2->SetBarDraw(1, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#EA4B32"))));

		// Create bar plot
		BarPlot *plot1 = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		leftAxis->SetMargins(5, 0);
		plot1->AddAxis(leftAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM, true);
		bottomAxis->SetMargins(20, 20);
		plot1->AddAxis(bottomAxis);

		NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT);
		rightAxis->SetMargins(5, 0);
		plot1->AddAxis(rightAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *topAxis = new CategoryAxis(AXIS_TOP);
		topAxis->SetMargins(20, 20);
		plot1->AddAxis(topAxis);

		// Add dataset to plot
		plot1->AddDataset(dataset);
		//plot->AddDataset(dataset2);

		plot1->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot1->LinkDataHorizontalAxis(0, 0);

		//novo
		//plot->LinkDataHorizontalAxis(1, 1);

		// Link first dataset with vertical axis
		plot1->LinkDataVerticalAxis(0, 0);

		//novo
		//plot->LinkDataVerticalAxis(1, 1);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot1->SetLegend(legend);

		// Create a custom title.
		TextElement title(GetName());

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		// add second plot to multiplot
		multiPlot->addPlot(plot1);

		multiPlot->AddAxis(leftAxis);
		multiPlot->AddAxis(bottomAxis);

		// The beginning of the first graph

		// first plot data
		double data1[][2] = {
			{ 10, 20, },
			{ 17, 30, },
			{ 25, 4, },
			{ 43, 16, },
			{ 65, 34, }
		};

		// create first plot
		XYPlot *plot2 = new XYPlot();

		// create dataset
		XYSimpleDataset *dataset1 = new XYSimpleDataset();

		// and add serie to it
		dataset1->AddSerie((double *)data1, WXSIZEOF(data1));

		// set line renderer to dataset
		dataset1->SetRenderer(new XYLineRenderer());

		// add our dataset to plot
		plot2->AddDataset(dataset1);

		// create left number axes
		NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT, true);
		//NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT);

		AxisShare *leftAxis1Shared = new AxisShare(leftAxis1);
		leftAxis1Shared->SetShareVisible(true);

		// create left axis, that will be shared between two plots
		NumberAxis *bottomAxisN = new NumberAxis(AXIS_BOTTOM);

		// create axis share for second plot to share leftAxis between plots
		// by default it will be invisible
		AxisShare *bottomAxis1 = new AxisShare(bottomAxisN);

		//AxisShare *bottomAxis1Shared = new AxisShare(bottomAxis1);
		bottomAxis1->SetShareVisible(true);

		// add axes to plot
		plot2->AddAxis(leftAxis1);
		plot2->AddAxis(bottomAxis1);

		// link axes and dataset
		plot2->LinkDataVerticalAxis(0, 0);
		plot2->LinkDataHorizontalAxis(0, 0);

		// add first plot to multiplot
		multiPlot->addPlot(plot2);

		//Não estou inserindo os eixos do gráfico de linha
		//multiPlot->AddAxis(leftAxis1Shared);
		//multiPlot->AddAxis(bottomAxis1);

		//The end of the second graph

		// and finally create chart
		return new Chart(multiPlot, GetName());
	}
};

ChartDemo *combinedAxisDemos[] = {
        new CombinedAxisDemo1(),
        new CombinedAxisDemo2(),
		new CombinedAxisDemo3(),
		new CombinedAxisDemo4(),
		new CombinedAxisDemo5()
};
int combinedAxisDemosCount = WXSIZEOF(combinedAxisDemos);
