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


ChartDemo *timeSeriesSigaDemos[] = {
    new TimeSerieSiga1(),
	new TimeSerieSiga2(),
	new TimeSerieSiga3(),
};
int timeSeriesSigaDemosCount = WXSIZEOF(timeSeriesSigaDemos);
