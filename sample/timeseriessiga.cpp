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
		//multiPlot->AddAxis(bottomAxis2); //adiciona eixo de baixo do gráfico de linha

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

		// serie 2 values
		/*double values2[] = {
			298603,    286184,    292299,    304342,    353072,    389122,    433905,    497245,
		};*/


		// Create dataset
		CategorySimpleDataset *dataset = new CategorySimpleDataset(names, WXSIZEOF(names));

		// add two series to it
		dataset->AddSerie(wxT("Goods"), values1, WXSIZEOF(values1));
		//dataset->AddSerie(wxT("Services"), values2, WXSIZEOF(values2));

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

ChartDemo *timeSeriesSigaDemos[] = {
    new TimeSerieSiga1(),
	new TimeSerieSiga2(),
	new TimeSerieSiga3(),
	new TimeSerieSiga4(),
	new TimeSerieSiga5()
};
int timeSeriesSigaDemosCount = WXSIZEOF(timeSeriesSigaDemos);
