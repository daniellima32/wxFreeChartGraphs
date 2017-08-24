/////////////////////////////////////////////////////////////////////////////
// Name:    multipleaxisdemos.cpp
// Purpose: This file contains source code, that demonstrates how to
//          multiple axis charts.
// Author:    Daniel Sucupira Lima
// Created:    18/08/17
/////////////////////////////////////////////////////////////////////////////


#include "democollection.h"

#include <wx/xy/xyplot.h>
#include <wx/xy/xysimpledataset.h>
#include <wx/xy/xylinerenderer.h>

#include <wx/axis/numberaxis.h>

// for area demo
#include <wx/xy/xyarearenderer.h>

#include <wx/xy/xyhistorenderer.h>
#include <wx/category/categorysimpledataset.h>

#include <wx/bars/barplot.h>
#include <wx/axis/categoryaxis.h>

/**
 * SigaDemo2: Multiple axis demo.
 */
//class MultipleAxisDemo2 : public ChartDemo
class SigaDemo3A : public ChartDemo
{
public:
	SigaDemo3A()
    : ChartDemo(wxT("Siga Demo 2 - Multiple axis 1"))
    {
    }

    virtual Chart *Create()
    {
        // first dataset values
        double values1[][2] = {
                { 1, 1 },
                { 2, 3 },
                { 5, 4 },
                { 6, 3 },
                { 7, 6 },
                { 8, 6 },
                { 9, 4 },
        };

		double values2[][2] = {
			{ 0, 0 },
			{ 2, -1 },
			{ 4, 6 },
			{ 5, 2 },
			{ 7, 8 },
			{ 8, 4 },
			{ 9, -2 },
			{ 10, 10 },
			{ 12, 12 },
			{ 19, 7 },
			{ 27, 70 },
			{ 40, 25 },
			{ 51, 12 },
		};

        // colors for first and second datasets
        wxColour color1 = wxColour(255, 0, 0);
        wxColour color2 = wxColour(0, 0, 255);

        // create xy plot
        XYPlot *plot = new XYPlot();

        // create first dataset
        XYSimpleDataset *dataset1 = new XYSimpleDataset();
        // add serie to it
        dataset1->AddSerie((double *) values1, WXSIZEOF(values1));

        // create second dataset
        XYSimpleDataset *dataset2 = new XYSimpleDataset();
        // add serie to it
        dataset2->AddSerie((double *) values2, WXSIZEOF(values2));

        // create renderer for first dataset
        XYLineRenderer *renderer1 = new XYLineRenderer(); //Desenha apenas as linhas de dados
        renderer1->SetSerieColour(0, &color1);

        // add first dataset to plot
        plot->AddDataset(dataset1);

        // set it to first dataset
        dataset1->SetRenderer(renderer1);

        // create renderer for second dataset
        XYLineRenderer *renderer2 = new XYLineRenderer(true); //Desenha apenas as linhas de dados
        renderer2->SetSerieColour(0, &color2);

        // set it to second dataset
        dataset2->SetRenderer(renderer2);

        // add second dataset to plot
        plot->AddDataset(dataset2);

        // create left axis for first dataset
		//Desenha os números nos eixos, os seus marcadores e o titulo de cada eixo
        NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
        leftAxis->SetLabelTextColour(color1);
        leftAxis->SetTitle("Left Axis");
        plot->AddAxis(leftAxis);

        // create left axis for second dataset
        NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT, true);
        rightAxis->SetLabelTextColour(color2);
        rightAxis->SetTitle("Right Axis");
        plot->AddAxis(rightAxis);

        // create top axis for first dataset
        NumberAxis *topAxis = new NumberAxis(AXIS_TOP);
        topAxis->SetLabelTextColour(color1);
        topAxis->SetTitle("Top Axis");
        plot->AddAxis(topAxis);

        // create bottom axis for second dataset
        NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM);
        bottomAxis->SetLabelTextColour(color2);
        bottomAxis->SetTitle("Bottom Axis");
        plot->AddAxis(bottomAxis);

        // link first dataset with left axis
        plot->LinkDataVerticalAxis(0, 0);
        // link second dataset with right axis
        plot->LinkDataVerticalAxis(1, 1);

        // link first dataset with top axis
        plot->LinkDataHorizontalAxis(0, 0);

        // link second dataset with bottom axis
        plot->LinkDataHorizontalAxis(1, 1);

        return new Chart(plot, GetName());
    }
};

class SigaDemo3B : public ChartDemo
{
public:
	SigaDemo3B()
		: ChartDemo(wxT("XY Demo - areas"))
	{
	}

	virtual Chart *Create()
	{

		// XY data for first series
		wxVector<wxRealPoint> data1;

		data1.push_back(wxRealPoint(0, 2));
		data1.push_back(wxRealPoint(1, 2));
		data1.push_back(wxRealPoint(2, 4));
		data1.push_back(wxRealPoint(3, 3));
		data1.push_back(wxRealPoint(4, 5));
		data1.push_back(wxRealPoint(5, 5));
		data1.push_back(wxRealPoint(6, 7));
		data1.push_back(wxRealPoint(7, 6));
		data1.push_back(wxRealPoint(8, 5));
		data1.push_back(wxRealPoint(9, 6));
		data1.push_back(wxRealPoint(10, 6));

		// XY data for second series
		wxVector<wxRealPoint> data2;

		data2.push_back(wxRealPoint(0, 1));
		data2.push_back(wxRealPoint(1, 1));
		data2.push_back(wxRealPoint(2, 2));
		data2.push_back(wxRealPoint(3, 4));
		data2.push_back(wxRealPoint(4, 3));
		data2.push_back(wxRealPoint(5, 2));
		data2.push_back(wxRealPoint(6, 3));
		data2.push_back(wxRealPoint(7, 6));
		data2.push_back(wxRealPoint(8, 3));
		data2.push_back(wxRealPoint(9, 4));
		data2.push_back(wxRealPoint(10, 3));

		// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// First step: create the plot.
		XYPlot *plot = new XYPlot();

		// Second step: create the dataset.
		XYSimpleDataset *dataset = new XYSimpleDataset();

		XYSimpleDataset *dataset2 = new XYSimpleDataset();

		// Third step: add the two series to it.
		dataset->AddSerie(new XYSerie(data1));
		//dataset->AddSerie(new XYSerie(data2)); //Não insiro o dado 2 aqui

		dataset2->AddSerie(new XYSerie(data2));

		// create area renderer and set it to dataset
		XYAreaRenderer *renderer = new XYAreaRenderer(true);
		dataset->SetRenderer(renderer);
		renderer->SetSerieColour(0, &color1);

		XYAreaRenderer *renderer2 = new XYAreaRenderer(true);
		dataset2->SetRenderer(renderer2);
		renderer2->SetSerieColour(0, &color2);

		// add our dataset to plot
		plot->AddDataset(dataset);

		plot->AddDataset(dataset2);

		// create left and bottom number axes
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT, true);
		NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM, true);

		//NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT, true);
		NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT, true);
		//NumberAxis *bottomAxis2 = new NumberAxis(AXIS_BOTTOM, true);
		NumberAxis *topAxis = new NumberAxis(AXIS_TOP, true);

		// add axes to plot
		plot->AddAxis(leftAxis);
		plot->AddAxis(bottomAxis);

		//plot->AddAxis(leftAxis2);
		plot->AddAxis(rightAxis);
		//plot->AddAxis(bottomAxis2);
		plot->AddAxis(topAxis);

		// link first dataset with left axis
		plot->LinkDataVerticalAxis(0, 0);
		// link second dataset with right axis
		plot->LinkDataVerticalAxis(1, 1);

		// link first dataset with top axis
		plot->LinkDataHorizontalAxis(0, 0);

		// link second dataset with bottom axis
		plot->LinkDataHorizontalAxis(1, 1);

		// link axes and dataset
		//plot->LinkDataVerticalAxis(0, 0);

		//plot->LinkDataVerticalAxis(1, 1);

		// set serie names to be displayed on legend
		dataset->SetSerieName(0, wxT("Serie 0"));
		//dataset->SetSerieName(1, wxT("Serie 1"));

		dataset2->SetSerieName(0, wxT("Serie 1"));

		// set legend
		plot->SetLegend(new Legend(wxCENTER, wxRIGHT));

		// and finally create chart
		Chart *chart = new Chart(plot, GetName());
		return chart;
	}
};

/**
* Simple demo with one dataset, and left and bottom axes.
*/
class SigaDemo3C : public ChartDemo
{
public:
	SigaDemo3C()
		: ChartDemo(wxT("Bar demo 1 - Single Series"))
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

		wxString names2[] = { // category names
			wxT("Cat 6"),
			wxT("Cat 7"),
			wxT("Cat 8"),
			wxT("Cat 9"),
			wxT("Cat 10"),
		};

		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			14.0,
			12.0,
		};

		// serie 2 values
		double values2[] = {
			12.0,
			21.0,
			7.0,
			10.0,
			9.0,
		};

		// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));
		CategorySimpleDataset *dataset2 = new CategorySimpleDataset(names2, WXSIZEOF(names2));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		dataset2->AddSerie(wxT("Serie 1"), values2, WXSIZEOF(values2));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30); //Deve dizer se inverte ou não aqui
		barType->setOriented(true);

		BarType *barType2 = new NormalBarType(30); //Deve dizer se inverte ou não aqui
		barType2->setOriented(true);

		// Set bar renderer for it
		BarRenderer *br1 = new BarRenderer(barType, true);
		

		dataset->SetRenderer(br1);
		//br1->SetSerieColour(0, &color1); //do not work with bar

		BarRenderer *br2 = new BarRenderer(barType2);
		
		
		dataset2->SetRenderer(br2);
		//br2->SetSerieColour(0, &color2); //do not work with bar

		// Why doesn't SetSerieColour work for bars?
		br1->SetBarDraw(0, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#007F7F"))));
		br2->SetBarDraw(1, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#EA4B32"))));

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
		plot->AddDataset(dataset2);

		plot->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		//novo
		plot->LinkDataHorizontalAxis(1, 1);

		// Link first dataset with vertical axis
		plot->LinkDataVerticalAxis(0, 0);

		//novo
		plot->LinkDataVerticalAxis(1, 1);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot->SetLegend(legend);

		// Create a custom title.
		TextElement title(GetName());

		// and finally construct and return chart
		Chart* chart = new Chart(plot, new Header(title));

		return chart;
	}
};

class SigaDemo3D : public ChartDemo
{
public:
	SigaDemo3D()
		: ChartDemo(wxT("Siga Demo 2 - Multiple axis 1"))
	{
	}

	virtual Chart *Create()
	{
		// first dataset values
		double values1[][2] = {
			{ 1, 1 },
			{ 2, 3 },
			{ 5, 2 },
			{ 6, 2 },
			{ 7, 3 },
			{ 8, 15 },
			{ 9, 2 },
		};

		// XY data for first series
		wxVector<wxRealPoint> data2;

		data2.push_back(wxRealPoint(0, 2));
		data2.push_back(wxRealPoint(1, 2));
		data2.push_back(wxRealPoint(2, 4));
		data2.push_back(wxRealPoint(3, 3));
		data2.push_back(wxRealPoint(4, 5));
		data2.push_back(wxRealPoint(5, 5));
		data2.push_back(wxRealPoint(6, 7));
		data2.push_back(wxRealPoint(7, 1));
		data2.push_back(wxRealPoint(8, 2));
		data2.push_back(wxRealPoint(9, 0.5));
		data2.push_back(wxRealPoint(10, 1));

	// colors for first and second datasets
		wxColour color1 = wxColour(255, 0, 0);
		wxColour color2 = wxColour(0, 0, 255);

		// create xy plot
		XYPlot *plot = new XYPlot();

		// create first dataset
		XYSimpleDataset *dataset1 = new XYSimpleDataset();
		// add serie to it
		dataset1->AddSerie((double *)values1, WXSIZEOF(values1));

		XYSimpleDataset *dataset2 = new XYSimpleDataset();

		dataset2->AddSerie(new XYSerie(data2));

		// create renderer for first dataset
		XYLineRenderer *renderer1 = new XYLineRenderer(); //Desenha apenas as linhas de dados
		renderer1->SetSerieColour(0, &color1);

		XYAreaRenderer *renderer2 = new XYAreaRenderer(true);
		dataset2->SetRenderer(renderer2);
		renderer2->SetSerieColour(0, &color2);
		

		// add first dataset to plot
		plot->AddDataset(dataset1);

		// set it to first dataset
		dataset1->SetRenderer(renderer1);

		plot->AddDataset(dataset2);

		// create left axis for first dataset
		//Desenha os números nos eixos, os seus marcadores e o titulo de cada eixo
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
		leftAxis->SetLabelTextColour(color1);
		leftAxis->SetTitle("Left Axis");
		plot->AddAxis(leftAxis);

		// create top axis for first dataset
		NumberAxis *topAxis = new NumberAxis(AXIS_TOP);
		topAxis->SetLabelTextColour(color1);
		topAxis->SetTitle("Top Axis");
		plot->AddAxis(topAxis);

		//NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT, true);
		NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT, true);
		plot->AddAxis(rightAxis);
		NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM, true);
		plot->AddAxis(bottomAxis);
		//NumberAxis *topAxis = new NumberAxis(AXIS_TOP, true);

		// link first dataset with left axis
		plot->LinkDataVerticalAxis(0, 0);
		// link second dataset with right axis
		plot->LinkDataVerticalAxis(1, 1);

		// link first dataset with top axis
		plot->LinkDataHorizontalAxis(0, 0);

		// link second dataset with bottom axis
		plot->LinkDataHorizontalAxis(1, 1);

		return new Chart(plot, GetName());
	}
};

ChartDemo *sigaDemos3[] = {
		new SigaDemo3A(),
		new SigaDemo3B(),
		new SigaDemo3C(),
		new SigaDemo3D()
};

int sigaDemos3Count = WXSIZEOF(sigaDemos3);
