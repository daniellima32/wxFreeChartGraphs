/////////////////////////////////////////////////////////////////////////////
// Name:    timeseriesdemos.cpp
// Purpose: time series demos code
// Author:    Moskvichev Andrey V.
// Created:    30.11.2008
// Copyright:    (c) 2009 Moskvichev Andrey V.
// Licence:    wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include "democollection.h"

#include <wx/xy/xyplot.h>
#include <wx/xy/xylinerenderer.h>

#include <wx/axis/numberaxis.h>
#include <wx/axis/dateaxis.h>

#include <wx/xy/timeseriesdataset.h>

#include <wx/axismultiplot.h>

#include <wx/xy/xyarearenderer.h>

#include <wx/category/categorysimpledataset.h>

#include <wx/bars/barplot.h>

#include <wx/axis/categoryaxis.h>

#include <wx/xy/xysimpledataset.h>


/**
 *
 */
class TimeSerieSiga1 : public ChartDemo
{
public:
	TimeSerieSiga1()
    : ChartDemo(wxT("Time series siga 1"))
    {
    }

    virtual Chart *Create()
    {
        // data
        double data[] = {
             64.09,
             63.34,
             61.41,
             62.00,
             61.71,
             63.39,
             63.64,
             63.61,
             65.11,
             65.72,
             66.89,
             66.68,
             66.51,
             66.40,
             67.27,
             67.66,
        };
        // dates
        const wxChar *strDates[] = {
            wxT("20060317"),
            wxT("20060320"),
            wxT("20060321"),
            wxT("20060322"),
            wxT("20060323"),
            wxT("20060324"),
            wxT("20060327"),
            wxT("20060328"),
            wxT("20060329"),
            wxT("20060330"),
            wxT("20060331"),
            wxT("20060403"),
            wxT("20060404"),
            wxT("20060405"),
            wxT("20060406"),
            wxT("20060407"),
        };

        time_t times[WXSIZEOF(strDates)];

        wxDateTime dt;
        for (size_t n = 0; n < WXSIZEOF(strDates); n++) {
            dt.ParseFormat(strDates[n], wxT("%Y%m%d"));
            times[n] = dt.GetTicks();
        }

        // first step: create plot
        XYPlot *plot = new XYPlot();

        TimeSeriesDataset *dataset = new TimeSeriesDataset(data, times, WXSIZEOF(data));

        dataset->SetRenderer(new XYLineRenderer());

        plot->AddDataset(dataset);

        // add left number and bottom date axes
        NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
        DateAxis *bottomAxis = new DateAxis(AXIS_BOTTOM);

        // setup window
        //bottomAxis->SetWindow(0, 10);
        //bottomAxis->SetUseWindow(true);

        bottomAxis->SetVerticalLabelText(true);
        bottomAxis->SetDateFormat(wxT("%d-%m"));

        // add axes to first plot
        plot->AddAxis(leftAxis);
        plot->AddAxis(bottomAxis);

        // link axes and dataset
        plot->LinkDataVerticalAxis(0, 0);
        plot->LinkDataHorizontalAxis(0, 0);

        // and finally create chart
        Chart *chart = new Chart(plot, GetName());

        //chart->SetScrolledAxis(bottomAxis);
        return chart;
    }
};

class TimeSerieSiga2 : public ChartDemo
{
public:
	TimeSerieSiga2()
    : ChartDemo(wxT("Time series siga 2"))
    {
    }

    virtual Chart *Create()
    {
        // data
        double data[] = {
             64.09,
             63.34,
             61.41,
             62.00,
             61.71,
             63.39,
             63.64,
             63.61,
             65.11,
             65.72,
             66.89,
             66.68,
             66.51,
             66.40,
             67.27,
             67.66,
        };
        // dates
        const wxChar *strDates[] = {
            wxT("20060317"),
            wxT("20060320"),
            wxT("20060321"),
            wxT("20060322"),
            wxT("20060323"),
            wxT("20060324"),
            wxT("20060327"),
            wxT("20060328"),
            wxT("20060329"),
            wxT("20060330"),
            wxT("20060331"),
            wxT("20060403"),
            wxT("20060404"),
            wxT("20060405"),
            wxT("20060406"),
            wxT("20060407"),
        };

        time_t times[WXSIZEOF(strDates)];

        wxDateTime dt;
        for (size_t n = 0; n < WXSIZEOF(strDates); n++) {
            dt.ParseFormat(strDates[n], wxT("%Y%m%d"));
            times[n] = dt.GetTicks();
        }

        // first step: create plot
        XYPlot *plot = new XYPlot();

        TimeSeriesDataset *dataset = new TimeSeriesDataset(data, times, WXSIZEOF(data));

        dataset->SetRenderer(new XYLineRenderer());

        plot->AddDataset(dataset);

        // add left number and bottom date axes
        NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
        DateAxis *bottomAxis = new DateAxis(AXIS_BOTTOM);

        // setup window
        //bottomAxis->SetWindow(0, 10);
        //bottomAxis->SetUseWindow(true);

        bottomAxis->SetVerticalLabelText(true);
        bottomAxis->SetDateFormat(wxT("%d-%m"));

        // add axes to first plot
        plot->AddAxis(leftAxis);
        plot->AddAxis(bottomAxis);

        // link axes and dataset
        plot->LinkDataVerticalAxis(0, 0);
        plot->LinkDataHorizontalAxis(0, 0);

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		multiPlot->addPlot(plot); //Adicionando gráfico de linha

		multiPlot->AddAxis(leftAxis); //adiciona eixo da esquerda do gráfico de linha
		multiPlot->AddAxis(bottomAxis); //adiciona eixo de baixo do gráfico de linha

		Chart *chart = new Chart(multiPlot, GetName());
		return chart;
    }
};

class TimeSerieSiga3 : public ChartDemo
{
public:
	TimeSerieSiga3()
		: ChartDemo(wxT("Time series siga 3"))
	{
	}

	virtual Chart *Create()
	{
		//inicio da configuração do gráfico 1

		// data
		double data[] = {
			64.09,
			63.34,
			61.41,
			62.00,
			61.71,
			63.39,
			63.64,
			63.61,
			65.11,
			65.72,
			66.89,
			66.68,
			66.51,
			66.40,
			67.27,
			67.66,
		};
		// dates
		const wxChar *strDates[] = {
			wxT("20060317"),
			wxT("20060320"),
			wxT("20060321"),
			wxT("20060322"),
			wxT("20060323"),
			wxT("20060324"),
			wxT("20060327"),
			wxT("20060328"),
			wxT("20060329"),
			wxT("20060330"),
			wxT("20060331"),
			wxT("20060403"),
			wxT("20060404"),
			wxT("20060405"),
			wxT("20060406"),
			wxT("20060407"),
		};

		time_t times[WXSIZEOF(strDates)];

		wxDateTime dt;
		for (size_t n = 0; n < WXSIZEOF(strDates); n++) {
			dt.ParseFormat(strDates[n], wxT("%Y%m%d"));
			times[n] = dt.GetTicks();
		}

		// first step: create plot
		XYPlot *plot = new XYPlot();

		TimeSeriesDataset *dataset = new TimeSeriesDataset(data, times, WXSIZEOF(data));

		dataset->SetRenderer(new XYLineRenderer());

		plot->AddDataset(dataset);

		// add left number and bottom date axes
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
		DateAxis *bottomAxis = new DateAxis(AXIS_BOTTOM);

		// setup window
		//bottomAxis->SetWindow(0, 10);
		//bottomAxis->SetUseWindow(true);

		bottomAxis->SetVerticalLabelText(true);
		bottomAxis->SetDateFormat(wxT("%d-%m"));

		// add axes to first plot
		plot->AddAxis(leftAxis);
		plot->AddAxis(bottomAxis);

		// link axes and dataset
		plot->LinkDataVerticalAxis(0, 0);
		plot->LinkDataHorizontalAxis(0, 0);

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		multiPlot->addPlot(plot); //Adicionando gráfico de linha

		multiPlot->AddAxis(leftAxis); //adiciona eixo da esquerda do gráfico de linha
		multiPlot->AddAxis(bottomAxis); //adiciona eixo de baixo do gráfico de linha

		//inicio da configuração do gráfico 1
		//inicio da configuração do gráfico 2

		// data
		double data2[] = {
			34.09,
			43.34,
			39.41,
			42.00,
			41.71,
			35.39,
			43.64,
			35.61,
			30.11,
			25.72,
			35.89,
			40.68,
			43.51,
			43.40,
			50.27,
			44.66,
		};
		
		// first step: create plot
		XYPlot *plot2 = new XYPlot();

		TimeSeriesDataset *dataset2 = new TimeSeriesDataset(data2, times, WXSIZEOF(data2));


		//dataset2->SetRenderer(new XYLineRenderer());
		dataset2->SetRenderer(new XYAreaRenderer());

		plot2->AddDataset(dataset2);

		// add left number and bottom date axes
		NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT);
		DateAxis *bottomAxis2 = new DateAxis(AXIS_BOTTOM);

		// setup window
		//bottomAxis->SetWindow(0, 10);
		//bottomAxis->SetUseWindow(true);

		bottomAxis2->SetVerticalLabelText(true);
		bottomAxis2->SetDateFormat(wxT("%d-%m"));

		// add axes to first plot
		plot2->AddAxis(leftAxis2);
		plot2->AddAxis(bottomAxis2);

		// link axes and dataset
		plot2->LinkDataVerticalAxis(0, 0);
		plot2->LinkDataHorizontalAxis(0, 0);

		multiPlot->addPlot(plot); //Adicionando gráfico de linha

		multiPlot->addPlot(plot2); //Adicionando segundo gráfico de linha

		multiPlot->AddAxis(leftAxis2); //adiciona eixo da esquerda do gráfico de linha
		//multiPlot->AddAxis(bottomAxis2); //adiciona eixo de baixo do gráfico de linha ..this

		//fim da configuração do gráfico 2

		Chart *chart = new Chart(multiPlot, GetName());
		return chart;
	}
};

//fake example of lib that uses data
/**
* Layered date bars demo.
*/
class TimeSerieSiga4 : public ChartDemo
{
public:
	TimeSerieSiga4()
		: ChartDemo(wxT("Example of lib that uses text as data with Bar"))
	{
	}

	virtual Chart *Create()
	{
		// TODO: !!! remake this demo to use dates, not string representation of years!
		wxString names[] = { // category names
			wxT("2010"),
			wxT("2011"),
			wxT("2012"),
			wxT("2013"),
			wxT("2014"),
			wxT("2015"),
			wxT("2016"),
			wxT("2017"),
		};

		// serie 1 values
		double values1[] = {
			771994,    718712,    682422,    713415,    807516,    894631,    1023109, 1148481,
		};

		// serie 2 values
		double values2[] = {
			298603,    286184,    292299,    304342,    353072,    389122,    433905,    497245,
		};


		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add two series to it
		dataset->AddSerie(wxT("Goods"), values1, WXSIZEOF(values1));
		dataset->AddSerie(wxT("Services"), values2, WXSIZEOF(values2));

		// create layered bar type with width=20 and base=0
		BarType *barType = new LayeredBarType(30, 0);

		// Set bar renderer for it, with layered bar type
		BarRenderer *renderer = new BarRenderer(barType);

		// Some eye-candy: gradient bars.
		renderer->SetBarDraw(0, new GradientAreaDraw(*wxTRANSPARENT_PEN, DEFAULT_BAR_FILL_COLOUR_0,
			DEFAULT_BAR_FILL_COLOUR_0.ChangeLightness(50), wxSOUTH));
		renderer->SetBarDraw(1, new GradientAreaDraw(*wxTRANSPARENT_PEN, DEFAULT_BAR_FILL_COLOUR_1,
			DEFAULT_BAR_FILL_COLOUR_1.ChangeLightness(50), wxSOUTH));

		// assign renderer to dataset
		dataset->SetRenderer(renderer);

		// Create bar plot
		BarPlot *plot = new BarPlot();

		// Add left number axis
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);

		///// leftAxis Experiments.
		leftAxis->SetMargins(20, 0);
		// leftAxis->SetMajorLabelSteps(5);
		leftAxis->SetMinorIntervalCount(0);
		// leftAxis->SetLabelSkip(5);

		plot->AddAxis(leftAxis);

		// Add bottom category axis
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM);
		bottomAxis->SetMargins(20, 20);
		bottomAxis->SetVerticalLabelText(true);
		plot->AddAxis(bottomAxis);

		// Add dataset to plot
		plot->AddDataset(dataset);

		// Link first dataset with first horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		// Link first dataset with first vertical axis
		plot->LinkDataVerticalAxis(0, 0);

		// Set legend
		plot->SetLegend(new Legend(wxCENTER, wxRIGHT));

		// Experiments.
		plot->SetDrawGrid(true, false);

		plot->SetBackground(new FillAreaDraw(*wxGREEN_PEN, *wxBLUE_BRUSH));
		plot->SetDataBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// and finally construct and return chart
		return new Chart(plot, wxT("USA Export Goods / Services"));;
	}
};

class TimeSerieSiga5 : public ChartDemo
{
public:
	TimeSerieSiga5()
		: ChartDemo(wxT("Example with Bar (text) using just one data"))
	{
	}

	virtual Chart *Create()
	{
		// TODO: !!! remake this demo to use dates, not string representation of years!
		wxString names[] = { // category names
			wxT("2010"),
			wxT("2011"),
			wxT("2012"),
			wxT("2013"),
			wxT("2014"),
			wxT("2015"),
			wxT("2016"),
			wxT("2017"),
		};

		// serie 1 values
		double values1[] = {
			771994,    718712,    682422,    713415,    807516,    894631,    1023109, 1148481,
		};

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add two series to it
		dataset->AddSerie(wxT("Goods"), values1, WXSIZEOF(values1));

		// create layered bar type with width=20 and base=0
		BarType *barType = new LayeredBarType(30, 0);

		// Set bar renderer for it, with layered bar type
		BarRenderer *renderer = new BarRenderer(barType);

		// Some eye-candy: gradient bars.
		renderer->SetBarDraw(0, new GradientAreaDraw(*wxTRANSPARENT_PEN, DEFAULT_BAR_FILL_COLOUR_0,
			DEFAULT_BAR_FILL_COLOUR_0.ChangeLightness(50), wxSOUTH));
		renderer->SetBarDraw(1, new GradientAreaDraw(*wxTRANSPARENT_PEN, DEFAULT_BAR_FILL_COLOUR_1,
			DEFAULT_BAR_FILL_COLOUR_1.ChangeLightness(50), wxSOUTH));

		// assign renderer to dataset
		dataset->SetRenderer(renderer);

		// Create bar plot
		BarPlot *plot = new BarPlot();

		// Add left number axis
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);

		///// leftAxis Experiments.
		leftAxis->SetMargins(20, 0);
		// leftAxis->SetMajorLabelSteps(5);
		leftAxis->SetMinorIntervalCount(0);
		// leftAxis->SetLabelSkip(5);

		plot->AddAxis(leftAxis);

		// Add bottom category axis
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM);
		bottomAxis->SetMargins(20, 20);
		bottomAxis->SetVerticalLabelText(true);
		plot->AddAxis(bottomAxis);

		// Add dataset to plot
		plot->AddDataset(dataset);

		// Link first dataset with first horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		// Link first dataset with first vertical axis
		plot->LinkDataVerticalAxis(0, 0);

		// Set legend
		plot->SetLegend(new Legend(wxCENTER, wxRIGHT));

		// Experiments.
		plot->SetDrawGrid(true, false);

		plot->SetBackground(new FillAreaDraw(*wxGREEN_PEN, *wxBLUE_BRUSH));
		plot->SetDataBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// and finally construct and return chart
		return new Chart(plot, wxT("USA Export Goods / Services"));;
	}
};

/**
* Simple demo with one dataset, and left and bottom axes.
*/
class TimeSerieSiga6 : public ChartDemo
{
public:
	TimeSerieSiga6()
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
		// serie 1 values - we have only one serie
		double values[] = {
			10.0,
			20.0,
			5.0,
			50.0,
			25.0,
		};

		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		dataset->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30);

		// Set bar renderer for it
		dataset->SetRenderer(new BarRenderer(barType));

		// Create bar plot
		BarPlot *plot = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
		leftAxis->SetMargins(5, 0);

		plot->AddAxis(leftAxis);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxis = new CategoryAxis(AXIS_BOTTOM);
		bottomAxis->SetMargins(20, 20);

		plot->AddAxis(bottomAxis);

		// Add dataset to plot
		plot->AddDataset(dataset);

		plot->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot->LinkDataHorizontalAxis(0, 0);

		// Link first dataset with vertical axis
		plot->LinkDataVerticalAxis(0, 0);

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

class TimeSerieSiga7 : public ChartDemo
{
public:
	TimeSerieSiga7()
		: ChartDemo(wxT("Time series siga 3"))
	{
	}

	virtual Chart *Create()
	{
		//inicio da configuração do gráfico 1

		// data
		double data[] = {
			64.09,
			63.34,
			61.41,
			62.00,
			61.71,
			63.39,
			63.64,
			63.61,
			65.11,
			65.72,
			66.89,
			66.68,
			66.51,
			66.40,
			67.27,
			67.66,
		};
		// dates
		const wxChar *strDates[] = {
			wxT("20060317"),
			wxT("20060320"),
			wxT("20060321"),
			wxT("20060322"),
			wxT("20060323"),
			wxT("20060324"),
			wxT("20060327"),
			wxT("20060328"),
			wxT("20060329"),
			wxT("20060330"),
			wxT("20060331"),
			wxT("20060403"),
			wxT("20060404"),
			wxT("20060405"),
			wxT("20060406"),
			wxT("20060407"),
		};

		time_t times[WXSIZEOF(strDates)];

		wxDateTime dt;
		for (size_t n = 0; n < WXSIZEOF(strDates); n++) {
			dt.ParseFormat(strDates[n], wxT("%Y%m%d"));
			times[n] = dt.GetTicks();
		}

		// first step: create plot
		XYPlot *plot = new XYPlot();

		TimeSeriesDataset *dataset = new TimeSeriesDataset(data, times, WXSIZEOF(data));

		dataset->SetRenderer(new XYLineRenderer());

		plot->AddDataset(dataset);

		// add left number and bottom date axes
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
		DateAxis *bottomAxis = new DateAxis(AXIS_BOTTOM);

		bottomAxis->SetVerticalLabelText(true);
		bottomAxis->SetDateFormat(wxT("%d-%m"));

		// add axes to first plot
		plot->AddAxis(leftAxis);
		plot->AddAxis(bottomAxis);

		// link axes and dataset
		plot->LinkDataVerticalAxis(0, 0);
		plot->LinkDataHorizontalAxis(0, 0);

		AxisMultiPlot *multiPlot = new AxisMultiPlot();
		multiPlot->addPlot(plot); //Adicionando gráfico de linha

		multiPlot->AddAxis(leftAxis); //adiciona eixo da esquerda do gráfico de linha
		multiPlot->AddAxis(bottomAxis); //adiciona eixo de baixo do gráfico de linha

		//fim da configuração do gráfico 1
		//inicio da configuração do gráfico 2

		// data
		double data2[] = {
			34.09,
			43.34,
			39.41,
			42.00,
			41.71,
			35.39,
			43.64,
			35.61,
			30.11,
			25.72,
			35.89,
			40.68,
			43.51,
			43.40,
			50.27,
			44.66,
		};

		// first step: create plot
		XYPlot *plot2 = new XYPlot();

		TimeSeriesDataset *dataset2 = new TimeSeriesDataset(data2, times, WXSIZEOF(data2));


		//dataset2->SetRenderer(new XYLineRenderer());
		dataset2->SetRenderer(new XYAreaRenderer());

		plot2->AddDataset(dataset2);

		// add left number and bottom date axes
		NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT);
		DateAxis *bottomAxis2 = new DateAxis(AXIS_BOTTOM);

		bottomAxis2->SetVerticalLabelText(true);
		bottomAxis2->SetDateFormat(wxT("%d-%m"));

		// add axes to first plot
		plot2->AddAxis(leftAxis2);
		plot2->AddAxis(bottomAxis2);

		// link axes and dataset
		plot2->LinkDataVerticalAxis(0, 0);
		plot2->LinkDataHorizontalAxis(0, 0);

		multiPlot->addPlot(plot); //Adicionando gráfico de linha

		multiPlot->addPlot(plot2); //Adicionando segundo gráfico de linha

		multiPlot->AddAxis(leftAxis2); //adiciona eixo da esquerda do gráfico de linha
		//multiPlot->AddAxis(bottomAxis2); //adiciona eixo de baixo do gráfico de linha ..this

		//fim da configuração do gráfico 2

		//inicio da conf do gráfico 3


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
			50.0,
			25.0,
		};

		// Create dataset
		CategorySimpleDataset *datasetCat = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add serie to it
		datasetCat->AddSerie(wxT("Serie 0"), values, WXSIZEOF(values));

		// create normal bar type with bar width = 10
		BarType *barType = new NormalBarType(30);

		BarRenderer *rendererBar = new BarRenderer(barType, true); //isto inverte o gráfico

		rendererBar->SetBarDraw(0, new FillAreaDraw(*wxTRANSPARENT_PEN, wxBrush(wxColour("#007F7F"))));

		// Set bar renderer for it
		datasetCat->SetRenderer(rendererBar);

		// Create bar plot
		BarPlot *plot3 = new BarPlot();

		// Create left number axis, set it's margins, and add it to plot
		NumberAxis *leftAxisCat = new NumberAxis(AXIS_LEFT);
		leftAxisCat->SetMargins(5, 0);

		plot3->AddAxis(leftAxisCat);

		// Create bottom axis, set it's margins, and add it to plot
		CategoryAxis *bottomAxisCat = new CategoryAxis(AXIS_BOTTOM);
		bottomAxisCat->SetMargins(20, 20);

		plot3->AddAxis(bottomAxisCat);

		// Add dataset to plot
		plot3->AddDataset(datasetCat);

		plot3->SetBackground(new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));

		// Link first dataset with horizontal axis
		plot3->LinkDataHorizontalAxis(0, 0);

		// Link first dataset with vertical axis
		plot3->LinkDataVerticalAxis(0, 0);

		// Show a legend at the centre-right position.
		Legend* legend = new Legend(wxCENTER, wxRIGHT, new FillAreaDraw(*wxTRANSPARENT_PEN, *wxTRANSPARENT_BRUSH));
		plot3->SetLegend(legend);

		multiPlot->addPlot(plot3); //Adicionando segundo gráfico de linha

		//não adiciono eixo nenhum
		//multiPlot->AddAxis(leftAxis2);

		//fim da conf do gráfico 3

		Chart *chart = new Chart(multiPlot, GetName());
		return chart;
	}
};

class TimeSerieSiga8 : public ChartDemo
{
public:
	TimeSerieSiga8()
		: ChartDemo(wxT("Siga Demo 2 - Multiple axis 1"))
	{
	}

	virtual Chart *Create()
	{
		// first dataset values
		double values1[][2] = {
			{ 0, 2 },
			{ 1, 1 },
			{ 2, 1 },
			{ 2, 1.5 },
			{ 2, 2.7 },
			{ 5, 2 },
			{ 6, 2 },
			{ 7, 3 },
			{ 8, 15 },
			{ 9, 2 },
		};

		// XY data for first series
		wxVector<wxRealPoint> data2;

		data2.push_back(wxRealPoint(0, 1));
		data2.push_back(wxRealPoint(1, 2));
		data2.push_back(wxRealPoint(2, 4));
		data2.push_back(wxRealPoint(3, 3));
		data2.push_back(wxRealPoint(4, 5));
		data2.push_back(wxRealPoint(5, 5));
		data2.push_back(wxRealPoint(6, 7));
		data2.push_back(wxRealPoint(7, 1));
		data2.push_back(wxRealPoint(8, 2));
		data2.push_back(wxRealPoint(9, 0.5));

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

		XYAreaRenderer *renderer2 = new XYAreaRenderer();
		dataset2->SetRenderer(renderer2);
		renderer2->SetSerieColour(0, &color2);

		// set it to first dataset
		dataset1->SetRenderer(renderer1);

		//Essa ordem de adição altera a ordem do paint
		plot->AddDataset(dataset2); // add the second dataset to plot
		plot->AddDataset(dataset1); // add the first dataset to plot

									// create left axis for first dataset
									//Desenha os números nos eixos, os seus marcadores e o titulo de cada eixo
		NumberAxis *leftAxis = new NumberAxis(AXIS_LEFT);
		//leftAxis->SetMargins(50, 120); //TESTE
		leftAxis->SetLabelTextColour(color1);
		leftAxis->SetTitle("Left Axis");
		plot->AddAxis(leftAxis);

		// create top axis for first dataset
		NumberAxis *topAxis = new NumberAxis(AXIS_TOP);
		topAxis->SetLabelTextColour(color1);
		topAxis->SetTitle("Top Axis");
		plot->AddAxis(topAxis);

		//NumberAxis *rightAxis = new NumberAxis(AXIS_RIGHT);
		//plot->AddAxis(rightAxis);
		NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT);
		plot->AddAxis(leftAxis2);

		NumberAxis *bottomAxis = new NumberAxis(AXIS_BOTTOM);
		plot->AddAxis(bottomAxis);

		// link first dataset with left axis
		plot->LinkDataVerticalAxis(1, 0);
		// link second dataset with right axis
		plot->LinkDataVerticalAxis(0, 1);

		// link first dataset with top axis
		plot->LinkDataHorizontalAxis(1, 0);

		// link second dataset with bottom axis
		plot->LinkDataHorizontalAxis(0, 1);

		return new Chart(plot, GetName());
	}
};


ChartDemo *timeSeriesSigaDemos[] = {
    new TimeSerieSiga1(),
	new TimeSerieSiga2(),
	new TimeSerieSiga3(),
	new TimeSerieSiga4(),
	new TimeSerieSiga5(),
	new TimeSerieSiga6(),
	new TimeSerieSiga7(),
	new TimeSerieSiga8()
};
int timeSeriesSigaDemosCount = WXSIZEOF(timeSeriesSigaDemos);
