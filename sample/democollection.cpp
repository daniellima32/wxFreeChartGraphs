/////////////////////////////////////////////////////////////////////////////
// Name:    democollection.cpp
// Purpose: Demo collection class implementation
// Author:    Moskvichev Andrey V.
// Created:    2008/11/12
// Copyright:    (c) 2008-2009 Moskvichev Andrey V.
// Licence:    wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include "democollection.h"

// demos
extern ChartDemo *ohlcDemos[];
extern int ohlcDemosCount;

extern ChartDemo *barDemos[];
extern int barDemosCount;

extern ChartDemo *xyDemos[];
extern int xyDemosCount;

extern ChartDemo *ganttDemos[];
extern int ganttDemosCount;

extern ChartDemo *bubbleDemos[];
extern int bubbleDemosCount;

extern ChartDemo *combinedAxisDemos[];
extern int combinedAxisDemosCount;

extern ChartDemo *multipleAxisDemos[];
extern int multipleAxisDemosCount;

extern ChartDemo *timeSeriesDemos[];
extern int timeSeriesDemosCount;

extern ChartDemo *markersDemos[];
extern int markersDemosCount;

extern ChartDemo *titleDemos[];
extern int titleDemosCount;

extern ChartDemo *pieplotDemos[];
extern int pieplotDemosCount;

//siga demos
extern ChartDemo *sigaDemos[];
extern int sigaDemosCount;

//siga demos 2
extern ChartDemo *sigaDemos2[];
extern int sigaDemos2Count;

//siga demos 3
extern ChartDemo *sigaDemos3[];
extern int sigaDemos3Count;

static DemoCollection instance;

/**
 * Demo category.
 */
class Category
{
public:
    Category(wxString name, ChartDemo **charts, int chartCount)
    {
        m_name = name;
        m_chartDemos = charts;
        m_chartCount = chartCount;
    }

	//New
	~Category()
	{
		for (int i=0;i<m_chartCount;i++)
		{
			free(m_chartDemos[i]);
		}
		free(m_chartDemos);
	}

    const wxString &GetName()
    {
        return m_name;
    }

    const wxString &GetChartName(int chartIndex)
    {
        return m_chartDemos[chartIndex]->GetName();
    }

    ChartDemo *GetChartDemo(int chartIndex)
    {
        return m_chartDemos[chartIndex];
    }

    int GetChartCount()
    {
        return m_chartCount;
    }

private:
    wxString m_name;
    ChartDemo **m_chartDemos;
    int m_chartCount;
};

// demo categories
static Category *cats[] = {
    new Category(wxT("OHLC Charts"), ohlcDemos, ohlcDemosCount),
    new Category(wxT("Bar Charts"), barDemos, barDemosCount),
    new Category(wxT("XY Charts"), xyDemos, xyDemosCount),
    new Category(wxT("Gantt Charts"), ganttDemos, ganttDemosCount),
    new Category(wxT("Bubble Charts"), bubbleDemos, bubbleDemosCount),
    new Category(wxT("Combined axis"), combinedAxisDemos, combinedAxisDemosCount),
    new Category(wxT("Multiple axis"), multipleAxisDemos, multipleAxisDemosCount),
    new Category(wxT("Time series Charts"), timeSeriesDemos, timeSeriesDemosCount),
    new Category(wxT("Markers"), markersDemos, markersDemosCount),
    new Category(wxT("Title"), titleDemos, titleDemosCount),
    new Category(wxT("Pie plots"), pieplotDemos, pieplotDemosCount),
	new Category(wxT("SIGA Demos"), sigaDemos, sigaDemosCount),
	new Category(wxT("SIGA Demos 2"), sigaDemos2, sigaDemos2Count),
	new Category(wxT("SIGA Demos 3"), sigaDemos3, sigaDemos3Count)
};

//
// DemoCollection
//
DemoCollection::DemoCollection()
{
}

DemoCollection::~DemoCollection()
{
	for (auto el : cats)
	{
		free(el);
	}
}

int DemoCollection::GetCategoryCount()
{
    return WXSIZEOF(cats);
}

const wxString &DemoCollection::GetCategory(int index)
{
    return cats[index]->GetName();
}

int DemoCollection::GetCategoryDemoCount(int index)
{
    return cats[index]->GetChartCount();
}

ChartDemo *DemoCollection::GetCategoryDemo(int catIndex, int demoIndex)
{
    return cats[catIndex]->GetChartDemo(demoIndex);
}

DemoCollection *DemoCollection::Get()
{
    return &instance;
}

