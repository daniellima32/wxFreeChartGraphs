#include <wx/AxisMultiPlot.h>

AxisMultiPlot::AxisMultiPlot()
{
}

AxisMultiPlot::~AxisMultiPlot()
{
}

void AxisMultiPlot::addPlot(AxisPlot * plot)
{
	m_plots.push_back(plot);
}

void AxisMultiPlot::DrawGridLines(wxDC &dc, wxRect rc)
{
	if (m_drawGridVertical) {
		for (size_t nAxis = 0; nAxis < m_verticalAxes.Count(); nAxis++) {
			m_verticalAxes[nAxis]->setRcPlotBackup(rcPlotBackup);
			m_verticalAxes[nAxis]->DrawGridLines(dc, rc);
		}
	}

	if (m_drawGridHorizontal) {
		for (size_t nAxis = 0; nAxis < m_horizontalAxes.Count(); nAxis++) {
			m_horizontalAxes[nAxis]->setRcPlotBackup(rcPlotBackup);
			m_horizontalAxes[nAxis]->DrawGridLines(dc, rc);
		}
	}
}

void AxisMultiPlot::DrawData(ChartDC & cdc, wxRect rc)
{
	for (auto plot: m_plots)
	{
		if (plot != nullptr) plot->DrawData(cdc, rc);
	}
}

bool AxisMultiPlot::HasData()
{
	bool result = true;
	for (auto plot: m_plots)
	{
		if (plot != nullptr) 
		{
			result &= plot->HasData();
		}
	}
	return result;
}

void AxisMultiPlot::DatasetChanged(Dataset * dataset)
{
}

void AxisMultiPlot::AxisChanged(Axis * axis)
{
}

void AxisMultiPlot::BoundsChanged(Axis * axis)
{
}

void AxisMultiPlot::ChartMouseDown(wxPoint & pt, int key)
{
}

bool AxisMultiPlot::AcceptAxis(Axis * axis)
{
	return true;
}

bool AxisMultiPlot::AcceptDataset(Dataset * dataset)
{
	//return false;
	return true;
}

void AxisMultiPlot::DrawDatasets(wxDC & dc, wxRect rc)
{
}
