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
		multiPlot->addPlot(plot); //Adicionando gr�fico de linha

		multiPlot->AddAxis(leftAxis); //adiciona eixo da esquerda do gr�fico de linha
		multiPlot->AddAxis(bottomAxis); //adiciona eixo de baixo do gr�fico de linha

		Chart *chart = new Chart(multiPlot, GetName());
		return chart;
    }
};

ChartDemo *timeSeriesSigaDemos[] = {
    new TimeSerieSiga1(),
	new TimeSerieSiga2(),
};
int timeSeriesSigaDemosCount = WXSIZEOF(timeSeriesSigaDemos);
